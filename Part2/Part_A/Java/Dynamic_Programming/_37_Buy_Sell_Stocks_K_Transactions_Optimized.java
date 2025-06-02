package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _37_Buy_Sell_Stocks_K_Transactions_Optimized {
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
     * You are given an integer array prices where prices[i] is the price of a given
     * stock on the ith day, and an integer k.
     * 
     * Find the maximum profit you can achieve. You may complete at most k
     * transactions: i.e. you may buy at most k times and sell at most k times.
     * 
     * Note: You may not engage in multiple transactions simultaneously (i.e., you
     * must sell the stock before you buy again).
     * 
     * 
     * 
     * Example 1:
     * 
     * Input: k = 2, prices = [2,4,1]
     * Output: 2
     * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
     * 4-2 = 2.
     * 
     * Example 2:
     * 
     * Input: k = 2, prices = [3,2,6,5,0,3]
     * Output: 7
     * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
     * 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit
     * = 3-0 = 3.
     * 
     */

    // WE CAN DO THE SAME PROBLEM IN N X (2*transactions) DP
    /* 
    
    3 transactions

    B S B S B S

    4 

    B S B S B S B S
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Stocks_Buy_Sell_Recursion(int index, int transactions, int[] prices, int n,int neededTransactions) {
        // base case
        if (index >= n || transactions == (2*neededTransactions)) {
            // no stock to buy or sell so profit is 0
            return 0;
        }

        // cannot buy for 0 & can buy for 1
        int profit = (int) (-1e8);

        // even then buy
        if (transactions % 2 == 0) {
            // if so then what profit we are making, if bought then cant buy again

            // time to sell
            int isBought = -prices[index] + Stocks_Buy_Sell_Recursion(index + 1, transactions + 1, prices, n, neededTransactions);

            // time to buy
            int isNotBought = Stocks_Buy_Sell_Recursion(index + 1, transactions, prices, n, neededTransactions);

            profit = Math.max(isBought, isNotBought);
        } else {
            // time to buy
            int ifSell = prices[index] + Stocks_Buy_Sell_Recursion(index + 1, transactions + 1, prices, n, neededTransactions);

            // time to sell
            int ifNotSell = 0 + Stocks_Buy_Sell_Recursion(index + 1, transactions, prices, n, neededTransactions);

            profit = Math.max(ifSell, ifNotSell);
        }

        return profit;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Memoization(int index, int transactions, int[] prices, int n, int dp[][],int neededTransactions) {
        // base case
        if (index >= n || transactions == (2*neededTransactions)) {
            // no stock to buy or sell so profit is 0
            return 0;
        }

        // cannot buy for 0 & can buy for 1
        int profit = (int) (-1e8);

        // even then buy
        if (transactions % 2 == 0) {
            // if so then what profit we are making, if bought then cant buy again

            // time to sell
            int isBought = -prices[index] + Stocks_Buy_Sell_Memoization(index + 1, transactions + 1, prices, n, dp, neededTransactions);

            // time to buy
            int isNotBought = Stocks_Buy_Sell_Memoization(index + 1, transactions, prices, n, dp, neededTransactions);

            profit = Math.max(isBought, isNotBought);
        } else {
            // time to buy
            int ifSell = prices[index] + Stocks_Buy_Sell_Memoization(index + 1, transactions + 1, prices, n, dp, neededTransactions);

            // time to sell
            int ifNotSell = 0 + Stocks_Buy_Sell_Memoization(index + 1, transactions, prices, n, dp, neededTransactions);

            profit = Math.max(ifSell, ifNotSell);
        }

        return profit;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Tabulation(int[] prices, int n,int transactions) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int dp[][] = new int[n + 1][(2*transactions) + 1];

        // base case
        // when transaction is 0 index can be anything
        for (int index = 0; index <= n; index++) {
            dp[index][0] = 0;
        }

        // when index = n transaction can be anything
        for (int transaction = 0; transaction <= (2*transactions); transaction++) {
            dp[n][transaction] = 0;
        }

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            for (int transaction = (transactions*2)-1; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    // can bought
                    profit = Math.max(dp[i + 1][transaction], -prices[i] + dp[i + 1][transaction + 1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + dp[i + 1][transaction + 1], 0 + dp[i + 1][transaction]);
                }
                dp[i][transaction] = profit;
            }
        }
        return dp[0][0];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n,int transactions) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int next[] = new int[(2*transactions) + 1];

        // base case
        // when transaction is 0 index can be anything
        for (int index = 0; index <= n; index++) {
            next[0] = 0;
        }

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr[] = new int[(2*transactions) + 1];
            for (int transaction = (2*transactions) - 1; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    // can bought
                    profit = Math.max(next[transaction], -prices[i] + next[transaction + 1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + next[transaction + 1], 0 + next[transaction]);
                }
                curr[transaction] = profit;
            }
            // update next
            next = curr;
        }
        return next[0];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    public static int Stocks_Buy_Sell_DPOptimized_1(int[] prices, int n,int transactions) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int next[] = new int[(2*transactions) + 1];

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            for (int transaction = (2*transactions)-1; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    // can bought
                    profit = Math.max(next[transaction], -prices[i] + next[transaction + 1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + next[transaction + 1], 0 + next[transaction]);
                }
                next[transaction] = profit;
            }
        }
        return next[0];
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int transactions = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Recursion(0, 0, prices, n,transactions);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n + 1][2];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Stocks_Buy_Sell_Memoization(0, 0, prices, n, dp, transactions);
        System.out.println("DP Memoization:" + ans);

        ans = Stocks_Buy_Sell_Tabulation(prices, n, transactions);
        System.out.println("DP Tabulation:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized(prices, n, transactions);
        System.out.println("DP DPOptimized:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized_1(prices, n, transactions);
        System.out.println("DP DPOptimized 1:" + ans);
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
