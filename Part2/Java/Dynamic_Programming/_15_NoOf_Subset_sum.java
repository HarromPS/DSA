package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _15_NoOf_Subset_sum {
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
     * - Given an array arr of size n of non-negative integers and an integer sum,
     * - The task is to count all subsets of the given array with a sum equal to a
     * given sum.
     * 
     * - Note: Answer can be very large, so, output answer modulo 109+7.
     * 
     * Input n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
     * Output: 3
     * Explanation:
     * {5, 2, 3}, {2, 8}, {10} are possible subsets.
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int subsetSumRecursion_1(int index, int target, int arr[], int n) {
        // base cases
        // if case satisfies condition

        // this condition will give wrong answers for array containing zeros
        // if (target == 0) {
        // return 1;
        // }

        /*
         * - if arr[0] is zero and the target is zero, it incorrectly increments val
         * twice for the same subset.
         * - This means it counts the empty subset {} and the subset {0} separately,
         * which should not be the case when checking for subset sums.
         * 
         */
        // if(index==0){
        // int val = (target==0?1:0);
        // val += (target==arr[index]?1:0);
        // return val;
        // }

        // As at any index if target == 0 we return 1;
        // if arr = 0 0 0 1
        // when i=2 && target = 0, if we return 1, it will give wrong answer
        // as there are 8 valid subsets with sum 1
        // so we have to do the pick / notpick for index = 0 as well and change base
        // case:
        if (index == 0) {
            if (target == 0 || arr[index]==target)
                return 1;
            else if(target==0 && arr[index]==0){
                return 2;
            }
            return 0;
        }

        // generate subsequences

        // pick
        int pick = 0;
        if (arr[index] <= target) {
            pick = subsetSumRecursion_1(index - 1, target - arr[index], arr, n);
        }

        // dont pick
        int dontPick = subsetSumRecursion_1(index - 1, target, arr, n);
        return pick + dontPick;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    public static int subsetSumMemoization(int index, int target, int arr[], int n, int dp[][]) {
        // base cases
        // if case satisfies condition

        // this condition will give wrong answers for array containing zeros
        // if (target == 0) {
        // return 1;
        // }

        // As at any index if target == 0 we return 1;
        // if arr = 0 0 0 1
        // when i=2 && target = 0, if we return 1, it will give wrong answer
        // as there are 8 valid subsets with sum 1
        // so we have to do the pick / notpick for index = 0 as well and change base
        // case:
        if (index < 0) {
            if (target == 0)
                return 1;
            return 0;
        }

        // check if already subproblems are solved
        if (dp[index][target] != -1)
            return dp[index][target];

        // generate subsequences
        // pick
        int pick = 0;
        if (arr[index] <= target) {
            pick = subsetSumMemoization(index - 1, target - arr[index], arr, n, dp);
        }

        // dont pick
        int dontPick = subsetSumMemoization(index - 1, target, arr, n, dp);

        // save the calculated value
        dp[index][target] = (pick + dontPick) % 1000000007;
        return dp[index][target];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int subsetSumTabulation(int arr[], int n, int target) {
        int dp[][] = new int[n][target + 1];
        // base case

        // initially whole dp is false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0; // false

            }
        }

        // // if target = 0, possible value of i is 0 to n-1
        // for (int i = 0; i < n; i++) {
        // dp[i][0] = 1;
        // }

        // we cannot do it like this
        // i.e dp[i][0]=1, as for zeros, we need to do their pick and non pick as well

        // so base case for tabulation will be
        dp[0][0] = 1;

        // else will be same

        // when only 1st element is considered, 2 ways, either is equal to target
        // or is included in subsequence, so index == 0, if arr[0]<=target return true
        if (arr[0] <= target) {
            dp[0][arr[0]] += 1;
        }

        // start from index 1 till n
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) { // start filling from 0 target
                // pick
                int pick = 0;
                if (j - arr[i] >= 0) {
                    pick = dp[i - 1][j - arr[i]];
                }
                int nonPick = dp[i - 1][j];
                dp[i][j] = pick + nonPick;
            }
        }
        return dp[n - 1][target];
    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int subsetSumDPOptimized(int arr[], int n, int k) {
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

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        int arr[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            arr[j] = r;
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = subsetSumRecursion_1(n - 1, k, arr, n);
        System.out.println("Brute force: " + ans);

        int dp[][] = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;

            }
        }

        ans = subsetSumMemoization(n - 1, k, arr, n, dp);
        System.out.println("DP Memoization:" + ans);

        ans = subsetSumTabulation(arr, n, k);
        System.out.println("DP Tabulation:" + ans);

        ans = subsetSumDPOptimized(arr, n, k);
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
