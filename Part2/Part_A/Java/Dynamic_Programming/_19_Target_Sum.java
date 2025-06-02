package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _19_Target_Sum {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    /*
     * You are given an integer array nums and an integer target.
     * 
     * You want to build an expression out of nums by adding one of the symbols '+'
     * and '-'
     * before each integer in nums and then concatenate all the integers.
     * 
     * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
     * and
     * concatenate them to build the expression "+2-1".
     * 
     * Return the number of different expressions that you can build, which
     * evaluates to target.
     * 
     * Example 1:
     * 
     * Input: nums = [1,1,1,1,1], target = 3
     * Output: 5
     * Explanation: There are 5 ways to assign symbols to make the sum of nums be
     * target 3.
     * -1 + 1 + 1 + 1 + 1 = 3
     * +1 - 1 + 1 + 1 + 1 = 3
     * +1 + 1 - 1 + 1 + 1 = 3
     * +1 + 1 + 1 - 1 + 1 = 3
     * +1 + 1 + 1 + 1 - 1 = 3
     * 
     * Example 2:
     * 
     * Input: nums = [1], target = 1
     * Output: 1
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int Target_Sum_Brute_1(int index, int arr[], int sum, int target) {
        // base case
        if (index == 0) {
            if (sum + arr[0] == target || sum - arr[0] == target) {
                return 1;
            } else {
                return 0;
            }
        }

        // recurrence relation
        int plus = Target_Sum_Brute_1(index - 1, arr, sum + arr[index], target);
        int substract = Target_Sum_Brute_1(index - 1, arr, sum - arr[index], target);

        return (plus + substract);
    }

    // DP Memoization
    // T.C: O(N x amt)
    // S.C: O(N x amt) + O(N) recursive stack
    // public static int Target_Sum_Memoization_1(int index, int arr[], int sum,int
    // target, int dp[][]) {
    // // base case
    // // if (index == 0) {
    // // if((sum + arr[0] == target || sum - arr[0] == target) && arr[0]==0){
    // // return 2;
    // // }else if((sum + arr[0] == target || sum - arr[0] == target)){
    // // return 1;
    // // }else{
    // // return 0;
    // // }
    // // }

    // // for positive targets only
    // if (index == 0) {
    // if((sum + arr[0] == target || sum - arr[0] == target)){
    // return 1;
    // }else{
    // return 0;
    // }
    // }

    // // check if the subproblems are previously solved or not
    // if(sum>=0){
    // if(dp[index][sum] != -1){
    // return dp[index][sum];
    // }
    // }

    // // recurrence relation
    // int plus = Target_Sum_Memoization_1(index - 1, arr, sum +
    // arr[index],target,dp);
    // int substract = Target_Sum_Memoization_1(index - 1, arr, sum -
    // arr[index],target,dp);

    // // save the calculated sums
    // if(sum>=0){
    // dp[index][sum] = (plus+substract);
    // }
    // return dp[index][sum];
    // }

    // AS DP with -ve indices do not work we will use hashmap
    public static int Target_Sum_Memoization_1(int index, int arr[], int sum, int target,
            Map<Integer, Map<Integer, Integer>> dp) {
        // base case
        if (index == 0) {
            if ((sum + arr[0] == target || sum - arr[0] == target) && arr[0] == 0) {
                return 2;
            } else if ((sum + arr[0] == target || sum - arr[0] == target)) {
                return 1;
            } else {
                return 0;
            }
        }

        // Initialize the inner map if it doesn't exist
        if (!dp.containsKey(index)) {
            dp.put(index, new HashMap<>());
        }

        // Get the inner map
        Map<Integer, Integer> innerMap = dp.get(index);

        // Check if the subproblems are previously solved or not
        if (innerMap.containsKey(sum) && innerMap.get(sum) != -1001) {
            return innerMap.get(sum);
        }

        // Recurrence relation
        int plus = Target_Sum_Memoization_1(index - 1, arr, sum + arr[index], target, dp);
        int subtract = Target_Sum_Memoization_1(index - 1, arr, sum - arr[index], target, dp);

        // Save the calculated sums
        innerMap.put(sum, plus + subtract);
        return innerMap.get(sum);
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Target_Sum_Tabulation(int arr[], int target) {
        int n = arr.length;
        int dp[][] = new int[n][target + 1];

        // base case
        // when index == 0
        for (int t = 0; t <= target; t++) {
            if (arr[0] == t || (-arr[0] == t)) {
                dp[0][t] = 1;
            }
            dp[0][t] = 0;
        }

        // recurrence relation
        for (int index = 1; index < n; index++) {
            for (int sum = 0; sum <= target; sum++) {
                int plus = dp[index - 1][sum + arr[index]];
                int sub = 0;
                if (sum - arr[index] >= 0) {
                    sub = dp[index - 1][sum - arr[index]];
                }
                dp[index][sum] = plus + sub;
            }
        }
        return dp[n - 1][target];
    }

    // public static int Target_Sum_Tabulation_2(int[] arr, int target) {
    //     int n = arr.length;
    //     int offset = 1000; // To handle negative sums
    //     int dp[][] = new int[n][2 * offset + 1]; // Range from -1000 to 1000

    //     // Initialize the dp array with -1001 (to mark uncalculated cells)
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j <= 2 * offset; j++) {
    //             dp[i][j] = -1001;
    //         }
    //     }

    //     // Base case
    //     dp[0][arr[0] + offset] = 1;
    //     dp[0][-arr[0] + offset] += 1; // Use += because arr[0] could be 0

    //     // Recurrence relation
    //     for (int index = 1; index < n; index++) {
    //         for (int sum = -offset; sum <= offset; sum++) {
    //             if (dp[index - 1][sum + offset] != -1001) {
    //                 int plus = sum + arr[index] + offset;
    //                 int minus = sum - arr[index] + offset;
    //                 if (plus <= 2 * offset) {
    //                     dp[index][plus] += dp[index - 1][sum + offset];
    //                 }
    //                 if (minus >= 0) {
    //                     dp[index][minus] += dp[index - 1][sum + offset];
    //                 }
    //             }
    //         }
    //     }

    //     return dp[n - 1][target + offset];
    // }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int Target_Sum_DPOptimized(int arr[], int n,int k) {
        // we only need 2 arrays to keep track of
        // previous and current

        int prev[] = new int[k + 1];

        // Base case: If the target is 0, there is one subset (the empty subset)
        prev[0] = 1;

        // Special case for the first element
        if (arr[0] <= k) {
            prev[arr[0]] += 1;
        }

        // Loop through each element starting from the second element (index 1)
        for (int index = 1; index < n; index++) {
            // Initialize the current row array with zeroes
            int currRow[] = new int[k + 1];

            // We always have at least one subset (the empty subset) for a target sum of 0
            currRow[0] = 1;

            // Loop through each possible target value from 0 to k
            for (int target = 0; target <= k; target++) {
                // Recurrence relation: Include or exclude the current element
                int pick = 0;
                if (target - arr[index] >= 0) {
                    pick = prev[target - arr[index]];
                }
                int nonPick = prev[target];
                currRow[target] = (pick + nonPick) % 1000000007;
            }

            // Update the previous row to be the current row
            prev = currRow;
        }

        // The answer is stored in the prev array at the target index
        return prev[k];
    }

    // DP optimized for single array optimization
    // T.C: O(n x T)
    // S.C: O(1)
    public static int Target_Sum_DPOptimized_2(int arr[], int k) {
        // base case
        int n = arr.length;

        // Create an array to store results of subproblems for the current element
        int prev[] = new int[k + 1];

        // Initialize the prev array for the first element of the array
        if (arr[0] == 0)
            prev[0] = 2; // 2 cases - pick and not pick
        else
            prev[0] = 1; // 1 case - not pick

        if (arr[0] != 0 && arr[0] <= k)
            prev[arr[0]] = 1; // 1 case - pick

        // Fill the prev array using dynamic programming
        for (int ind = 1; ind < n; ind++) {
            int cur[] = new int[k + 1];
            for (int target = 0; target <= k; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = (notTaken + taken);
            }
            prev = cur;
        }

        return prev[k];
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int target = sc.nextInt();

        // same question
        int total=0;
        int arr[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            arr[j] = r;
            total+=r;
        }

        if(total-target< 0 || (total-target)%2==1) {
            System.out.println("No partiton can be made for -ve and odd sums");
        }

        // else find sum s2=(total-d)/2
        int k = (total-target)/2;

        // only positive numbers, for negative we can use map

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        // int ans = Target_Sum_Brute_1(n - 1, arr, 0, target);
        // System.out.println("Brute force 1: " + ans);

        // Map<Integer, Map<Integer, Integer>> dp = new HashMap<Integer, Map<Integer, Integer>>();
        // for (int i = 0; i < n; i++) {
        //     Map<Integer, Integer> temp = new HashMap<Integer, Integer>();
        //     for (int j = -1000; j <= target; j++) {
        //         temp.put(j, -1001);
        //     }
        //     dp.put(i, temp);
        // }

        // ans = Target_Sum_Memoization_1(n - 1, arr, 0, target, dp);
        // System.out.println("DP Memoization:" + ans);

        // ans = Target_Sum_Tabulation(arr, target);
        // System.out.println("DP Tabulation:" + ans);



        // PROBLEM IS SUMILAR TO COUNT PARTITIONS 
        // S1 - S2 = d


        int ans = Target_Sum_DPOptimized(arr, n, k);
        System.out.println("DP Optimized:" + ans);

    }

    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        FastReader sc = new FastReader(System.in);
        // int test = sc.nextInt();
        // while (test-- > 0) {
        // solve(sc);
        // }
        solve(sc);
    }
}
