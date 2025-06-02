package Java.Bit_Manipulation;

import java.util.ArrayList;

public class Power_sets {

    // Using Bit manipulation
    public static ArrayList<ArrayList<Integer>> solve(int nums[],int size){
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();

        // iterate upto all the subsets
        for(int num = 0;num<Math.pow(2, size);num++){
            // iterate over each

            ArrayList<Integer> v = new ArrayList<>();
            for(int i=0;i<size;i++){
                if((num & (1<<i))!=0){
                    v.add(nums[i]);
                }
            }
            ans.add(v);
        }
        return ans;
    }
    public static void main(String[] args) {
        int nums[] = {1,2,3};
        int n = nums.length;

        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        ans = solve(nums,n);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.get(i).size();j++){
                System.out.print(ans.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }
}
