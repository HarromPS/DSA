package Java.Recursion;

import java.util.ArrayList;

public class _1_SubArrayOneAns {
    public static ArrayList<Integer> num;

    public static Boolean getSubsequenceSum(int index,int n,ArrayList<Integer> arr,int sum,int targetSum){

        // base condition, when a solution is found and no need to find further solutions
        if(index>=n || sum>targetSum){

            // condition satisfied
            if(sum==targetSum){
                for(int i=0;i<arr.size();i++){
                    System.out.print(arr.get(i)+" ");
                }
                System.out.println();
                return true;
            }
            // if not satisfied
            return false;
        }


        int currSum = 0;
        // pick the element from the list and add its sum in the subsequence
        arr.add(num.get(index));

        // calculate the sum when picked
        for(int i=0;i<arr.size();i++){
            currSum = currSum + arr.get(i);
        }
        
        // check if the function call got any solution so that further recursion calls can be avoided
        if(getSubsequenceSum(index+1, n, arr, currSum, targetSum)==true){
            return true;
        }
        
        // dont pick the element and remove its sum from the from the subsequence
        arr.remove(arr.size()-1);        
        
        currSum=0;
        // calculate the sum when not picked
        for(int i=0;i<arr.size();i++){
            currSum = currSum + arr.get(i);
        }
        
        if(getSubsequenceSum(index+1, n, arr, currSum, targetSum)){
            return true;
        }

        // if no one has found a solution yet return false
        return false;
    }
    public static void main(String[] args) {
        // initialize the array list
        num = new ArrayList<Integer>();

        int lst[] = {1,2,1};
        for(int i=0;i<lst.length;i++){
            num.add(lst[i]);
        }

        int targetSum = 2;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        getSubsequenceSum(0, lst.length, ans, 0, targetSum);
    }
}
