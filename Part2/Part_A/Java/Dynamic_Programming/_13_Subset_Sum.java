package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _13_Subset_Sum {
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
     * Given an array of non-negative integers, and a value sum, determine
     * if there is a subset of the given set with sum equal to given sum.
     * 
     * Input:
     * N = 6
     * arr[] = {3, 34, 4, 12, 5, 2}
     * sum = 9
     * Output: 1
     * Explanation: Here there exists a subset with
     * sum = 9, 4+3+2 = 9.
     * 
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static boolean subsetSumRecursion_1(int index, int target, int arr[], int n) {
        // base cases
        // if case satisfies condition
        if (target == 0) {
            return true;
        }

        if (index >= n || target < 0) {
            return false;
        }

        // generate subsequences

        // pick
        target = target - arr[index];
        boolean r = subsetSumRecursion_1(index + 1, target, arr, n);

        if (r == true)
            return true;

        // dont pick
        target = target + arr[index];
        r = subsetSumRecursion_1(index + 1, target, arr, n);
        if (r == true)
            return true;

        return false;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    public static boolean subsetSumMemoization(int index, int target, int arr[], int n, int dp[][]) {
        // base cases
        // if case satisfies condition
        if (target == 0) {
            return true;
        }

        if (index == 0){
            return (arr[0] == target);
        }

        if (index < 0 || target < 0) {
            return false;
        }

        // check if prevoiusly calculated
        if (dp[index][target] != -1) {
            return (dp[index][target] == 0 ? false : true);
        }

        // generate subsequences
        // pick
        // dont pick
        boolean dontPick = subsetSumMemoization(index - 1, target, arr, n, dp);
        
        boolean pick=false;
        if (arr[index] <= target){
            pick = subsetSumMemoization(index - 1, target-arr[index], arr, n, dp);
        }

        dp[index][target] = (pick || dontPick) ? 1 : 0;

        return pick || dontPick;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static boolean subsetSumTabulation(int arr[], int n, int target) {
        int dp[][] = new int[n][target + 1];
        // base case

        // initially whole dp is false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0; // false

            }
        }

        // if target = 0, possible value of i is 0 to n-1
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // when only 1st element is considered, 2 ways, either is equal to target
        // or is included in subsequence, so index == 0, if arr[0]<=target return true
        if (arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        // start from index 1 till n
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // pick
                boolean pick = false;
                if (j - arr[i] >= 0) {
                    pick = (dp[i - 1][j - arr[i]] == 1 ? true : false);
                }
                boolean nonPick = (dp[i - 1][j] == 1 ? true : false);
                dp[i][j] = (pick || nonPick == true ? 1 : 0);
            }
        }
        return (dp[n - 1][target] == 1 ? true : false);

    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static boolean subsetSumDPOptimized(int arr[], int n, int k) {
        // we only need 2 arrays to keep track of
        // previous and current

        int prev[] = new int[k + 1];

        // base case if target is 0
        prev[0] = 1;

        // start from 0 th index, 1st element
        for (int index = 0; index < n; index++) {
            // current row i.e when i==0 base case, if arr[0]<=target curr[arr[0]] = 1;
            int currRow[] = new int[k + 1];
            currRow[0] = 1;
            for (int target = 0; target <= k; target++) {
                // 1st row, 1st element is considered
                if (index == 0) {
                    // if 1st element is equal to target -> (index,target) = true
                    // if arr[0] <= target, means it is included in subsequence
                    if (arr[0] <= k) {
                        currRow[arr[0]] = 1;
                    }
                } else {
                    // copy paste recurrence relation
                    boolean pick = false;
                    if (target - arr[index] >= 0) {
                        pick = (prev[target - arr[index]] == 1 ? true : false);
                    }

                    boolean nonPick = (prev[target] == 1 ? true : false);
                    currRow[target] = (pick || nonPick == true ? 1 : 0);
                }
            }
            // update previous row
            prev = currRow;
        }
        return (prev[k]==1?true:false);
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
        boolean ans = subsetSumRecursion_1(0, k, arr, n);
        System.out.println("Brute force: " + ans);

        int dp[][] = new int[n][k + 1];
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;

            }
        }
        
        ans=subsetSumMemoization(n-1,k,arr,n,dp);
        System.out.println("DP Memoization:"+ans);

        ans = subsetSumTabulation(arr,n,k);
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
