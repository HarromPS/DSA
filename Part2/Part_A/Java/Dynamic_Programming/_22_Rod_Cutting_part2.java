package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _22_Rod_Cutting_part2 {
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
     * Problem statement
     * 
     * Given a rod of length ‘N’ units.
     * The rod can be cut into different sizes and each size has a cost associated
     * with it.
     * Determine the maximum cost obtained by cutting the rod and selling its
     * pieces.
     * Note:
     * 
     * 1. The sizes will range from 1 to ‘N’ and will be integers.
     * 
     * 2. The sum of the pieces cut should be equal to ‘N’.
     * 
     * 3. Consider 1-based indexing.
     * 
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int Rod_Cutting_Recursion_1(int index, int targetN, int price[]) {
        // base case
        // as rod length 1 can be used to make the length of rod upto target N
        if (index == 1) {
            return targetN * price[index-1];
        }
        // not pick item, move to next item
        int dontPick = 0 + Rod_Cutting_Recursion_1(index - 1, targetN, price);

        // pick only if there is capacity in the bag
        int pick = (int) (-1e9);
        int rodLength = index;
        if (targetN >= rodLength) {
            // can pick same index more than once
            pick = price[index-1] + Rod_Cutting_Recursion_1(index, targetN - rodLength, price);
        }

        return Math.max(pick, dontPick);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    public static int Rod_Cutting_Memoization_1(int index, int targetN, int price[], int dp[][]) {
          // base case
        // as rod length 1 can be used to make the length of rod upto target N
        if (index == 1) {
            return targetN * price[index-1];
        }

        // check if the subproblems are solved
        if(dp[index][targetN]!=-1){
            return dp[index][targetN];
        }

        // not pick item, move to next item
        int dontPick = 0 + Rod_Cutting_Memoization_1(index - 1, targetN, price, dp);

        // pick only if there is capacity in the bag
        int pick = (int) (-1e9);
        int rodLength = index;
        if (targetN >= rodLength) {
            // can pick same index more than once
            pick = price[index-1] + Rod_Cutting_Memoization_1(index, targetN - rodLength, price, dp);
        }

        dp[index][targetN] = Math.max(pick, dontPick);
        return dp[index][targetN];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Rod_Cutting_Tabulation(int targetN, int price[], int n) {
        int dp[][] = new int[n+1][targetN + 1];

        // base case
        int index = 1;
        for (int len = 0; len <= targetN; len++) {
            dp[index][len] = len * price[index-1];
        }

        // recurrence relation
        for (int ind = 1; ind <= n; ind++) { // from index 1 as index 0 is done as base case
            for (int len = 0; len <= targetN; len++) {
                // dont pick
                int dontpick = 0 + dp[ind-1][len];

                // pick
                int pick = (int) (-1e9);
                int rodLength = ind;
                if (len >= rodLength) {
                    // we can pick items
                    pick = price[ind-1] + dp[ind][len - rodLength];
                }

                dp[ind][len] = Math.max(pick, dontpick);
            }
        }
        return dp[n][targetN];
    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int Rod_Cutting_DPOptimized(int targetN, int price[], int n) {
        int prev[] = new int[targetN + 1];

        // base case
        int index = 1;
        for (int len = 0; len <= targetN; len++) {
            prev[len] = len * price[index-1];
        }

        // recurrence relation
        for (int ind = 1; ind <= n; ind++) { // from index 1 as index 0 is done as base case
            int curr[]=new int[targetN+1];
            for (int len = 0; len <= targetN; len++) {
                // dont pick
                int dontpick = 0 + prev[len];

                // pick
                int pick = (int) (-1e9);
                int rodLength = ind;
                if (len >= rodLength) {
                    // we can pick items
                    pick = price[ind-1] + curr[len - rodLength];
                }

                curr[len] = Math.max(pick, dontpick);
            }
        }
        return prev[targetN];
    }

    // DP Single array optimized
    // T.C: O(n*W)
    // S.C: O(W)
    public static int Rod_Cutting_DPOptimized_2(int targetN, int price[], int n){
        int prev[] = new int[targetN + 1];

        // base case
        int index = 1;
        for (int len = 0; len <= targetN; len++) {
            prev[len] = len * price[index-1];
        }

        // recurrence relation
        for (int ind = 1; ind <= n; ind++) { // from index 1 as index 0 is done as base case
            for (int len = 0; len <= targetN; len++) {
                // dont pick
                int dontpick = 0 + prev[len];

                // pick
                int pick = (int) (-1e9);
                int rodLength = ind;
                if (len >= rodLength) {
                    // we can pick items
                    pick = price[ind-1] + prev[len - rodLength];
                }

                prev[len] = Math.max(pick, dontpick);
            }
        }
        return prev[targetN];
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int targetN = n;

        // same question
        int price[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            price[j] = r;
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = Rod_Cutting_Recursion_1(n, targetN, price);
        System.out.println("Brute force 1: " + ans);

        int dp[][] = new int[n+1][targetN + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= targetN; j++) {
                dp[i][j] = -1;
            }
        }

        ans = Rod_Cutting_Memoization_1(n, targetN, price, dp);
        System.out.println("DP Memoization:" + ans);

        ans = Rod_Cutting_Tabulation(targetN, price, n);
        System.out.println("DP Tabulation:" + ans);

        ans = Rod_Cutting_DPOptimized(targetN, price, n);
        System.out.println("DP Optimized 1:" + ans);

        ans = Rod_Cutting_DPOptimized_2(targetN, price, n);
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
