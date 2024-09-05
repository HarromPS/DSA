package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _39_Buy_Sell_Stock_With_Fees {
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
     * on the ith day, and an integer fee representing a transaction fee.
     * 
     * Find the maximum profit you can achieve.
     * You may complete as many transactions as you like, but you need to pay the
     * transaction fee for each transaction.
     * 
     * Note:
     * 
     * You may not engage in multiple transactions simultaneously (i.e., you must
     * sell the stock before you buy again).
     * The transaction fee is only charged once for each stock purchase and sale.
     * 
     * 
     * 
     * Example 1:
     * 
     * Input: prices = [1,3,2,8,4,9], fee = 2
     * Output: 8
     * Explanation: The maximum profit can be achieved by:
     * - Buying at prices[0] = 1
     * - Selling at prices[3] = 8
     * - Buying at prices[4] = 4
     * - Selling at prices[5] = 9
     * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
     * 
     * Example 2:
     * 
     * Input: prices = [1,3,7,5,10,3], fee = 3
     * Output: 6
     * 
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Stocks_Buy_Sell_Recursion(int index, int canBuyStock, int[] prices, int n,int fees) {
        // base case
        if (index >= n) {
            // no stock to buy or sell so profit is 0
            return 0;
        }

        // cannot buy for 0 & can buy for 1
        int profit = (int) (-1e8);

        // 1st stock can definately be bought,
        if (canBuyStock == 1) {
            // if so then what profit we are making, if bought then cant buy again

            // selling ith day stock so minus
            int isBought = -prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n, fees);

            int isNotBought = Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n, fees);

            profit = Math.max(isBought, isNotBought);
        } else {
            // TAKE FEES ONLY IF SELLING THE STOCK IS SUCCESSFULLY BUYED AND SELLED
            int ifSell = (prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n, fees)) - fees;

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n, fees);

            profit = Math.max(ifSell, ifNotSell);
        }

        return profit;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Memoization(int index, int canBuyStock, int[] prices, int n, int dp[][],int fees) {
        // base case
        if (index >= n) {
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
            int isBought = -prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp,fees);

            int isNotBought = Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp,fees);

            profit = Math.max(isBought, isNotBought);
        } else {
            // if cant buy means only we can sell, so if sold then profit will be
            int ifSell = (prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp,fees)) - fees;

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp,fees);

            profit = Math.max(ifSell, ifNotSell);
        }

        dp[index][canBuyStock] = profit;
        return profit;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Tabulation(int[] prices, int n,int fees) {

        int dp[][] = new int[n + 1][2];
        // base case
        // if (index >= n) return 0;
        // for last index
        dp[n][0] = 0; // if bought and sold on same day
        dp[n][1] = 0; // if bought, then our account is running in -ve on last day

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy == 1) {
                    // can bought
                    profit = Math.max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max((prices[i] + dp[i + 1][1])-fees, 0 + dp[i + 1][0]);
                }
                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n,int fees) {

        int next[] = new int[2];
        // base case
        // if (index >= n) return 0;
        // for last index
        next[0] = 0; // if bought and sold on same day
        next[1] = 0; // if bought, then our account is running in -ve on last day

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr[] = new int[2];
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy == 1) {
                    // can bought
                    profit = Math.max(next[0] - prices[i], next[1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max((prices[i] + next[1])-fees, 0 + next[0]);
                }
                curr[canBuy] = profit;
            }
            // update prev
            next = curr;
        }
        return next[1];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    public static int Stocks_Buy_Sell_DPOptimized_1(int[] prices, int n,int fees) {

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
                    profit = Math.max((prices[i] + next_1)-fees, 0 + next_0);
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
        int fees = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Recursion(0, 1, prices, n, fees);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n + 1][2];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Stocks_Buy_Sell_Memoization(0, 1, prices, n, dp,fees);
        System.out.println("DP Memoization:" + ans);

        ans = Stocks_Buy_Sell_Tabulation(prices, n,fees);
        System.out.println("DP Tabulation:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized(prices, n,fees);
        System.out.println("DP DPOptimized:" + ans);

        ans = Stocks_Buy_Sell_DPOptimized_1(prices, n,fees);
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
