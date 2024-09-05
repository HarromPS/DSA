package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _36_Buy_Sell_Stocks_K_Transactions {
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
     * 
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    // we can do buy on ith day or not buy
    // if buy then cant buy again until sell
    // can sell (for a good price) or not sell (wait for better price)
    public static int Stocks_Buy_Sell_Recursion(int index, int canBuyStock, int[] prices, int n, int transactions) {
        // base case
        if (index >= n || transactions == 0) {
            // no stock to buy or sell so profit is 0
            return 0;
        }

        // cannot buy for 0 & can buy for 1
        int profit = (int) (-1e8);

        // 1st stock can definately be bought,
        if (canBuyStock == 1) {
            // if so then what profit we are making, if bought then cant buy again

            // selling ith day stock so minus
            int isBought = -prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n, transactions);

            int isNotBought = Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n, transactions);

            profit = Math.max(isBought, isNotBought);
        } else {
            // if cant buy means only we can sell, so if sold then profit will be
            int ifSell = prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n, transactions - 1);

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n, transactions);

            profit = Math.max(ifSell, ifNotSell);
        }

        return profit;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Memoization(int index, int canBuyStock, int[] prices, int n, int dp[][],int transactions) {
        // base case
        if (index >= n || transactions == 0) {
            // no stock to buy or sell so profit is 0
            return 0;
        }

        // if overlapping problems are solved
        if (dp[index][canBuyStock] != -1) {
            return dp[index][canBuyStock];
        }

        // cannot buy for 0 & can buy for 1
        int profit = (int) (-1e8);

        // 1st stock can definately be bought,
        if (canBuyStock == 1) {
            // if so then what profit we are making, if bought then cant buy again

            // selling ith day stock so minus
            int isBought = -prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp, transactions);

            int isNotBought = Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp, transactions);

            profit = Math.max(isBought, isNotBought);
        } else {
            // if cant buy means only we can sell, so if sold then profit will be
            int ifSell = prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp, transactions - 1);

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp, transactions);

            profit = Math.max(ifSell, ifNotSell);
        }

        dp[index][canBuyStock] = profit;
        return profit;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Tabulation(int[] prices, int n,int transactions) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int dp[][][] = new int[n + 1][2][transactions+1];

        // if cap == 0 means index and buy can be anything
        // index here from n to 0
        for (int index = n; index >= 0; index--) {
            for (int canBuy = 0; canBuy < transactions; canBuy++) {
                // cap == 0 so return 0
                dp[index][canBuy][0] = 0;
            }
        }

        // if index == 0 means cap and buy can be anything
        // index here from n to 0
        for (int cap = 0; cap < transactions; cap++) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                // cap == 0 so return 0
                dp[0][canBuy][cap] = 0;
            }
        }

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= transactions; cap++) {
                    int profit = 0;
                    if (canBuy == 1) {
                        // can bought
                        profit = Math.max(dp[i + 1][1][cap], -prices[i] + dp[i + 1][0][cap]);
                    } else {
                        // cannot buy, then sell
                        profit = Math.max(prices[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
                    }
                    dp[i][canBuy][cap] = profit;
                }
            }
        }
        return dp[0][1][transactions];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n, int transactions) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int next[][] = new int[2][transactions+1];

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr[][] = new int[2][transactions+1];
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= transactions; cap++) {
                    int profit = 0;
                    if (canBuy == 1) {
                        // can bought
                        profit = Math.max(next[1][cap], -prices[i] + next[0][cap]);
                    } else {
                        // cannot buy, then sell
                        profit = Math.max(prices[i] + next[1][cap - 1], 0 + next[0][cap]);
                    }
                    curr[canBuy][cap] = profit;
                }
            }
            // update next
            next = curr;
        }
        return next[1][transactions];
    }


    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int transactions = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Recursion(0, 1, prices, n, transactions);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n + 1][2];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Stocks_Buy_Sell_Memoization(0, 1, prices, n, dp, transactions);
        System.out.println("DP Memoization:" + ans);

        ans = Stocks_Buy_Sell_Tabulation(prices, n, transactions);
        System.out.println("DP Tabulation:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized(prices, n,transactions);
        System.out.println("DP DPOptimized:" + ans);
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
