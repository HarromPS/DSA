package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _21_Unbounded_KnapSack {
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
     * You are given weights and values of N items, put these items in a knapsack of
     * capacity W to get the maximum total value in the knapsack.
     * Note that we have only one quantity of each item.
     * In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which
     * represent values and Input:
     * N = 3
     * W = 4
     * values[] = {1,2,3}
     * weight[] = {4,5,1}
     * Output: 3
     * Explanation: Choose the last item that weighs 1 unit and holds a value of 3.
     * weights associated with N items respectively. Also given an integer W which
     * represents knapsack capacity,
     * find out the maximum value subset of val[] such that sum of the weights of
     * this subset is smaller than or equal to W.
     * You cannot break an item, either pick the complete item or dont pick it (0-1
     * property).
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int KnapSack_Recursion_1(int index, int W, int value[], int weight[], int n) {
        // base case
        // if bag capaity gets full or weight of item at index 0 is more that required
        // capacity return 0 i.e cant pick it
        if (index == 0) {
            if (weight[index] <= W) {
                int numberOfItemsCanSteal = W / weight[0];
                int totalProfit = numberOfItemsCanSteal * value[0];
                return totalProfit;
            }
            return 0;
        }
        // not pick item, move to next item
        int dontPick = 0 + KnapSack_Recursion_1(index - 1, W, value, weight, n);

        // pick only if there is capacity in the bag
        int pick = (int) (-1e9);
        if (W >= weight[index]) {

            // can pick same index more than once
            pick = value[index] + KnapSack_Recursion_1(index, W - weight[index], value, weight, n);
        }

        return Math.max(pick, dontPick);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    public static int KnapSack_Memoization_1(int index, int W, int value[], int weight[], int n, int dp[][]) {
        // base case
        // if bag capaity gets full or weight of item at index 0 is more that required
        // capacity return 0 i.e cant pick it
        if (index == 0) {
            if (weight[index] <= W) {
                int numberOfItemsCanSteal = W / weight[0];
                int totalProfit = numberOfItemsCanSteal * value[0];
                return totalProfit;
            }
            return 0;
        }

        // check if subproblems are previously solved
        if (dp[index][W] != -1) {
            return dp[index][W];
        }

        // not pick item, move to next item
        int dontPick = 0 + KnapSack_Memoization_1(index - 1, W, value, weight, n, dp);

        // pick only if there is capacity in the bag
        int pick = (int) (-1e9);
        if (W >= weight[index]) {

            // can pick same index more than once
            pick = value[index] + KnapSack_Memoization_1(index, W - weight[index], value, weight, n, dp);
        }

        dp[index][W] = Math.max(pick, dontPick);
        return dp[index][W];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int KnapSack_Tabulation(int W, int value[], int weight[], int n) {
        int dp[][] = new int[n][W + 1];

        // base case
        // if bag caacity is there item at index 0, then profit is number of times 0th
        // item can be chosen * its value
        // else 0
        for (int c = 0; c <= W; c++) {
            if (c >= weight[0]) {
                dp[0][c] = (int)(c/weight[0])*value[0];
            } else {
                dp[0][c] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) { // from index 1 as index 0 is done as base case
            for (int c = 0; c <= W; c++) {
                // dont pick
                int dontpick = 0 + dp[i - 1][c];

                // pick
                int pick = 0;
                if (c >= weight[i]) {
                    // we can pick items
                    pick = value[i] + dp[i][c - weight[i]];
                }

                dp[i][c] = Math.max(pick, dontpick);
            }
        }
        return dp[n - 1][W];
    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int KnapSack_DPOptimized(int W, int value[], int weight[], int n) {
        int prev[] = new int[W + 1];
        prev[0] = 0;

        // base case
        // if bag caacity is there item at index 0, then profit is number of times 0th
        // item can be chosen * its value
        // else 0
        for (int c = 0; c <= W; c++) {
            if (c >= weight[0]) {
                prev[c] = (c / weight[0]) * value[0];
            } else {
                prev[c] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) { // from index 1 as index 0 is done as base case
            int cur[] = new int[W + 1];
            for (int c = 0; c <= W; c++) {
                // dont pick
                int dontpick = 0 + prev[c];

                // pick
                int pick = 0;
                if (c >= weight[i]) {
                    pick = value[i] + cur[c - weight[i]];
                }

                cur[c] = Math.max(pick, dontpick);
            }
            // update previous
            prev = cur;
        }
        return prev[W];
    }

    // DP Single array optimized
    // T.C: O(n*W)
    // S.C: O(1)
    public static int KnapSack_DPOptimized_2(int W, int value[], int weight[], int n) {
        int prev[] = new int[W + 1];

        // if we see from fill W to 0 it still fill prev correct
        // & if we fill curr values in prev row itself -> no problem
        // as we take curr value from perv (c-weight[i]);

        // so same base
        // if bag caacity is there item at index 0, then profit is number of times 0th
        // item can be chosen * its value
        // else 0
        for (int c = 0; c <=W; c++) {
            if (c >= weight[0]) {
                prev[c] = (c / weight[0]) * value[0];
            } else {
                prev[c] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) { // from index 1 as index 0 is done as base case
            for (int c=0;c<=W;c++) {
                // dont pick
                int dontpick = 0 + prev[c];

                // pick
                int pick = 0;
                if (c >= weight[i]) {
                    // we can use current index more than once
                    pick = value[i] + prev[c - weight[i]] ;
                }

                prev[c] = Math.max(pick, dontpick);
            }
        }
        return prev[W];
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int w = sc.nextInt();

        // same question
        int val[] = new int[n];
        int weight[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            val[j] = r;
            r = sc.nextInt();
            weight[j] = r;
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = KnapSack_Recursion_1(n - 1, w, val, weight, n);
        System.out.println("Brute force 1: " + ans);

        int dp[][] = new int[n][w + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                dp[i][j] = -1;
            }
        }

        ans = KnapSack_Memoization_1(n-1,w,val,weight,n,dp);
        System.out.println("DP Memoization:" + ans);

        ans = KnapSack_Tabulation(w,val,weight,n);
        System.out.println("DP Tabulation:" + ans);

        ans = KnapSack_DPOptimized(w,val,weight,n);
        System.out.println("DP Optimized 1:" + ans);

        ans = KnapSack_DPOptimized_2(w,val,weight,n);
        System.out.println("DP Optimized 2:" + ans);
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
