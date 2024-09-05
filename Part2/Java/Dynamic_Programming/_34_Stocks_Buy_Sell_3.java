package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _34_Stocks_Buy_Sell_3 {
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
     * You are given an array prices where prices[i] is the price of a given stock
     * on the ith day.
     * 
     * Find the maximum profit you can achieve. You may complete at most two
     * transactions.
     * 
     * Note: You may not engage in multiple transactions simultaneously (i.e., you
     * must sell the stock before you buy again).
     * 
     * In previous problem, infinite transactions were allowed
     * Here only two transactions are allowed
     * So think like knapsack problem
     * 
     * Example 1:
     * 
     * Input: prices = [3,3,5,0,0,3,1,4]
     * Output: 6
     * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
     * 3-0 = 3.
     * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
     * 3.
     * 
     * Example 2:
     * 
     * Input: prices = [1,2,3,4,5]
     * Output: 4
     * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
     * 5-1 = 4.
     * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
     * are engaging multiple transactions at the same time. You must sell before
     * buying again.
     * 
     * Example 3:
     * 
     * Input: prices = [7,6,4,3,1]
     * Output: 0
     * Explanation: In this case, no transaction is done, i.e. max profit = 0.
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
    public static int Stocks_Buy_Sell_Memoization(int index, int canBuyStock, int[] prices, int n, int dp[][],
            int transactions) {
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
    public static int Stocks_Buy_Sell_Tabulation(int[] prices, int n) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int dp[][][] = new int[n + 1][2][3];

        // if cap == 0 means index and buy can be anything
        // index here from n to 0
        for (int index = n; index >= 0; index--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                // cap == 0 so return 0
                dp[index][canBuy][0] = 0;
            }
        }

        // if index == 0 means cap and buy can be anything
        // index here from n to 0
        for (int cap = 0; cap < 3; cap++) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                // cap == 0 so return 0
                dp[0][canBuy][cap] = 0;
            }
        }

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= 2; cap++) {
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
        return dp[0][1][2];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n) {

        // in memoization we have 3 parameters
        // (index) (canbuy) (transactions -> 0/1/2 (max 3))
        int next[][] = new int[2][3];

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr[][] = new int[2][3];
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= 2; cap++) {
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
        return next[1][2];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    public static int Stocks_Buy_Sell_DPOptimized_1(int[] prices, int n) {

        // base case
        // if (index >= n) return 0;
        // for last index
        int next_0 = 0; // if bought and sold on same day
        int next_1 = 0; // if bought, then our account is running in -ve on last day

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr_0 = 0;
            int curr_1 = 0;

            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy == 1) {
                    // can bought
                    profit = Math.max(next_0 - prices[i], next_1);
                    curr_1 = profit;
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + next_1, 0 + next_0);
                    curr_0 = profit;
                }
            }
            // update prev
            next_0 = curr_0;
            next_1 = curr_1;
        }
        return next_1;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Recursion(0, 1, prices, n, 2);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n + 1][2];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Stocks_Buy_Sell_Memoization(0, 1, prices, n, dp, 2);
        System.out.println("DP Memoization:" + ans);

        ans = Stocks_Buy_Sell_Tabulation(prices, n);
        System.out.println("DP Tabulation:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized(prices, n);
        System.out.println("DP DPOptimized:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized_1(prices, n);
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
