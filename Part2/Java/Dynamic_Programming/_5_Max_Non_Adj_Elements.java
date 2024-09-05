package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _5_Max_Non_Adj_Elements {
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
     * You are given an array/list of ‘N’ integers.
     * You are supposed to return the maximum sum of the subsequence with the
     * constraint
     * that no two elements are adjacent in the given array/list.
     * 
     * Note: A subsequence of an array/list is obtained by deleting some number of
     * elements (can be zero) from the array/list,
     * leaving the remaining elements in their original order.
     * 
     * e.g [1 2 4]
     * => cannot pick 1,2 or 2,4 as they are adjacent
     * => can pick 1,4 as not adjacent
     * 
     * e.g [2 1 1 2] [0 1 2 3]
     * => cannot pick index 0-1 1-2 2-3
     * => can pick 0-2 0-3 1-3
     * 
     */

    // Brute force: T.C:O(2^n), S.C: O(N) recursive stack
    public static int maxSumAdjElementsRecursion_1(int arr[], int n) {
        // base cases
        if (n == 0)
            return arr[n]; // if chosen 2nd index, then 0th is picked and 1st index is not picked
        if (n < 0)
            return 0; // if negative index, return 0

        // if picked current index, cannot pick adj element (n-1), but element next to
        // adj can be picked i.e (n-2)
        int picked = arr[n] + maxSumAdjElementsRecursion_1(arr, n - 2);

        // if current not picked, then 0 is added to max sum, can pick adj element (n-1)
        int notPicked = 0 + maxSumAdjElementsRecursion_1(arr, n - 1);

        // return max of picked and not picked elements
        return Math.max(picked, notPicked);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(N), S.C: O(N)+O(N)
    public static int maxSumAdjElementsMemoization(int arr[], int n, int dp[]) {
        // base cases
        if (n == 0)
            return arr[0];
        if (n < 0)
            return 0;

        // check if there is a solution for subproblem
        if (dp[n] != -1)
            return dp[n];

        // calculate the value of subproblem
        int pick = arr[n] + maxSumAdjElementsMemoization(arr, n - 2, dp);
        int nonPick = 0 + maxSumAdjElementsMemoization(arr, n - 1, dp);

        // store value in dp
        dp[n] = Math.max(pick, nonPick);
        return dp[n];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(N), S.C: O(N);
    public static int maxSumAdjElementsTabulation(int arr[]) {
        int dp[] = new int[arr.length + 1];

        // base case
        dp[0] = arr[0];

        for (int i = 1; i < arr.length; i++) {
            // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
            int pick = arr[i];
            if (i > 1)
                pick += dp[i - 2];
            // if dont pick current, then can pick prev
            int nonPick = 0 + dp[i - 1];

            dp[i] = Math.max(pick, nonPick);
        }
        return dp[arr.length - 1];
    }

    // DP optimized
    // T.C: O(N), S.C : O(1)
    public static int maxSumAdjElementsDPOptimized(int arr[]) {
        int prev = arr[0], prev2 = 0;

        for (int i = 1; i < arr.length; i++) {
            // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
            int pick = arr[i];
            if (i > 1)
                pick += prev2;
            // if dont pick current, then can pick prev
            int nonPick = 0 + prev;

            int curri = Math.max(pick, nonPick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int maxSum = maxSumAdjElementsRecursion_1(arr, n - 1);
        System.out.println("Brute Force 1:" + maxSum);

        int dp[] = new int[arr.length + 1];
        for (int i = 0; i < arr.length + 1; i++)
            dp[i] = -1;
        maxSum = maxSumAdjElementsMemoization(arr, n - 1, dp);
        System.out.println("DP Memoization:" + maxSum);

        maxSum = maxSumAdjElementsTabulation(arr);
        System.out.println("DP Tabulation:" + maxSum);

        maxSum = maxSumAdjElementsDPOptimized(arr);
        System.out.println("DP Optimized:" + maxSum);
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
