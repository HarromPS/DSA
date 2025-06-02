package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _18_Coin_Change {
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
     * You are given an integer array coins representing coins of different
     * denominations and an integer amount representing a total amount of money.
     * 
     * Return the fewest number of coins that you need to make up that amount.
     * If that amount of money cannot be made up by any combination of the coins,
     * return -1.
     * 
     * You may assume that you have an infinite number of each kind of coin.
     * 
     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int KnapSack_Recursion_1(int index, int coins[], int sum) {
        // base case
        if (index == 0) {
            if (sum % coins[0] == 0) {
                return sum / coins[0];
            }
            return (int) 1e9;
        }

        // recurrence relation
        int dontpick = 0 + KnapSack_Recursion_1(index - 1, coins, sum);

        int pick = (int) 1e9;
        if (sum >= coins[index]) {
            // then pick, else dont pick choose next index
            pick = 1 + KnapSack_Recursion_1(index, coins, sum - coins[index]);
        }

        return Math.min(pick, dontpick);
    }

    // DP Memoization
    // T.C: O(N x amt)
    // S.C: O(N x amt) + O(N) recursive stack
    public static int KnapSack_Memoization_1(int index, int coins[], int sum, int dp[][]) {
        // base case
        if (index == 0) {
            if (sum % coins[0] == 0) {
                return sum / coins[0];
            }
            return (int) 1e9;
        }

        // check if the solution previously solved
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        // recurrence relation
        int dontpick = 0 + KnapSack_Memoization_1(index - 1, coins, sum,dp);

        int pick = (int) 1e9;
        if (sum >= coins[index]) {
            // then pick, else dont pick choose next index
            pick = 1 + KnapSack_Memoization_1(index, coins, sum - coins[index],dp);
        }

        dp[index][sum] = Math.min(pick, dontpick);
        return dp[index][sum];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int KnapSack_Tabulation(int coins[], int sum) {
        // base case
        int n = coins.length;
        int T = sum;
        int dp[][] = new int[n][T + 1];
        
        // base case
        // for any target value from 0 to T when index == 0, is given as
        for (int t = 0; t < (T + 1); t++) {
            // if amount is divisible by coins at index 0
            if (t % coins[0] == 0) {
                // then number of coins can be picked is
                dp[0][t] = t / coins[0];
            } else {
                dp[0][t] = (int) 1e9;
            }
        }

        // Recurrence relation
        for (int i = 1; i < n; i++) {
            for (int t = 0; t < (T + 1); t++) {
                // dont pick
                int dontpick = 0 + dp[i - 1][t];

                // pick
                int pick = (int) 1e9;
                if (t >= coins[i]) {
                    pick = 1 + dp[i][t - coins[i]];
                }

                dp[i][t] = Math.min(pick, dontpick);
            }
        }

        return dp[n - 1][T];
    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int KnapSack_DPOptimized(int coins[], int sum) {
        // base case
        int n = coins.length;
        int T = sum;
        int prev[] = new int[T + 1];
        
        // base case
        // for any target value from 0 to T when index == 0, is given as
        for (int t = 0; t < (T + 1); t++) {
            // if amount is divisible by coins at index 0
            if (t % coins[0] == 0) {
                // then number of coins can be picked is
                prev[t] = t / coins[0];
            } else {
                prev[t] = (int) 1e9;
            }
        }

        // Recurrence relation
        for (int i = 1; i < n; i++) {
            int curr[] = new int[T+1];
            for (int t = 0; t < (T + 1); t++) {
                // dont pick
                int dontpick = 0 + prev[t];

                // pick
                int pick = (int) 1e9;
                if (t >= coins[i]) {
                    pick = 1 + curr[t - coins[i]];
                }

                curr[t] = Math.min(pick, dontpick);
            }
            // update prev
            prev = curr;
        }

        return prev[T];
    }

    // DP optimized for single array optimization
    // T.C: O(n x T) 
    // S.C: O(1)
    public static int KnapSack_DPOptimized_2(int coins[], int sum) {
        // base case
        int n = coins.length;
        int T = sum;
        int prev[] = new int[T + 1];
        
        // base case
        // for any target value from 0 to T when index == 0, is given as
        for (int t = 0; t < (T + 1); t++) {
            // if amount is divisible by coins at index 0
            if (t % coins[0] == 0) {
                // then number of coins can be picked is
                prev[t] = t / coins[0];
            } else {
                prev[t] = (int) 1e9;
            }
        }

        // Recurrence relation
        for (int i = 1; i < n; i++) {
            for (int t = 0; t < (T + 1); t++) {
                // dont pick
                int dontpick = 0 + prev[t];

                // pick
                int pick = (int) 1e9;
                if (t >= coins[i]) {
                    pick = 1 + prev[t - coins[i]];
                }

                prev[t] = Math.min(pick, dontpick);
            }
        }

        return prev[T];
    }

    
    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int amt = sc.nextInt();

        // same question
        int coins[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            coins[j] = r;
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = KnapSack_Recursion_1(n - 1, coins, amt);
        System.out.println("Brute force 1: " + ans);

        int dp[][] = new int[n][amt + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= amt; j++) {
                dp[i][j] = -1;

            }
        }

        ans = KnapSack_Memoization_1(n - 1, coins, amt, dp);
        System.out.println("DP Memoization:" + ans);

        ans = KnapSack_Tabulation(coins, amt);
        System.out.println("DP Tabulation:" + ans);

        ans = KnapSack_DPOptimized(coins, amt);
        System.out.println("DP Optimized:" + ans);

        ans = KnapSack_DPOptimized_2(coins, amt);
        System.out.println("DP Optimized 2 :" + ans);
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
