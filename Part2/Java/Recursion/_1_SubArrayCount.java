package Java.Recursion;

import java.util.ArrayList;

public class _1_SubArrayCount {
    public static ArrayList<Integer> num;
    public static int count;

    public static void getSubsequenceSum(int index,int n,ArrayList<Integer> arr,int sum,int targetSum){

        if(index>=n || sum>targetSum){

            // it looks like:
            // f(index: 3, list[1, 1], sum: 2)
            // f(index: 3, list[2], sum: 2)

            // if the sum if equal to the target sum
            if(sum==targetSum){
                // count the subsequence
                count+=1;
            }

            // note: do not write the above code block outside this if condition
            // else even if the sum is equal it will be skipped as index is out of bounds
            return;
        }


        int currSum = 0;
        // pick the element from the list and add its sum in the subsequence
        arr.add(num.get(index));

        // calculate the sum when picked
        for(int i=0;i<arr.size();i++){
            currSum = currSum + arr.get(i);
        }
        // move the list forward by add index and a function call
        getSubsequenceSum(index+1, n, arr, currSum, targetSum);
        
        // dont pick the element and remove its sum from the from the subsequence
        arr.remove(arr.size()-1);        
        
        currSum=0;
        // calculate the sum when not picked
        for(int i=0;i<arr.size();i++){
            currSum = currSum + arr.get(i);
        }
        
        getSubsequenceSum(index+1, n, arr, currSum, targetSum);

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

        // get the count 
        System.out.println(count);
    }
}