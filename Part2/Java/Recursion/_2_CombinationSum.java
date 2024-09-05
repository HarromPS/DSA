package Java.Recursion;

import java.util.ArrayList;

/*
Combination sum: 

Given an array [2,3,6,7] and a target sum: find all possible combination which forms the sum
*/

public class _2_CombinationSum {
    static public void CombinationSum(int index, int target, ArrayList<Integer> v, int size, int arr[]) {
        // base case

        // index reach to the end and target found to be zero, means sum reduced to zero
        if (index == size) {
            // else even if target is zero and index is not reached, it will go down and try
            // to access out of bound index

            // check if the target is found after length is reached
            if (target == 0) {
                // print the data structure
                for (int i = 0; i < v.size(); i++) {
                    System.out.print(v.get(i) + " ");
                }
                System.out.println();
            }

            // when found a combination return the function call else it will give out of bound error
            return;
        }

        // pick up the element if target is still able to reach
        if (arr[index] <= target) {
            // pick
            v.add(arr[index]);

            // pick function call
            CombinationSum(index, target - arr[index], v, size, arr);

            // dont pick, remove out the element when function call is returns
            v.remove(v.size() - 1);
        }

        // dont pick function call, move to next index element
        CombinationSum(index + 1, target, v, size, arr);

    }

    public static void main(String[] args) {
        int arr[] = { 2, 3, 6, 7 };
        int size = arr.length;
        int target = 7;

        ArrayList<Integer> s = new ArrayList<Integer>();
        // get all possible combinations for the target sum from the array
        CombinationSum(0, target, s, size, arr);
    }

}