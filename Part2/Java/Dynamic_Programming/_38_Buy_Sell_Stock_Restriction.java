package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _38_Buy_Sell_Stock_Restriction {
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
     * Find the maximum profit you can achieve. You may complete as many
     * transactions as you like (i.e., buy one and sell one share of the stock
     * multiple times) with the following restrictions:
     * 
     * After you sell your stock, you cannot buy stock on the next day (i.e.,
     * cooldown one day).
     * 
     * Note: You may not engage in multiple transactions simultaneously (i.e., you
     * must sell the stock before you buy again).
     * 
     * 
     * 
     * Example 1:
     * 
     * Input: prices = [1,2,3,0,2]
     * Output: 3
     * Explanation: transactions = [buy, sell, cooldown, buy, sell]
     * 
     * Example 2:
     * 
     * Input: prices = [1]
     * Output: 0
     * 
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Stocks_Buy_Sell_Recursion(int index, int canBuyStock, int[] prices, int n) {
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
            int isBought = -prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n);

            int isNotBought = Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n);

            profit = Math.max(isBought, isNotBought);
        } else {
            // AFTER STOCK IS SELL, CANNOT BUY ON NEXT DAY, BUT WE CAN DO IT ON THE DAY AFTER TOMORROW
            int ifSell = prices[index] + Stocks_Buy_Sell_Recursion(index + 2, 1, prices, n);

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Recursion(index + 1, 0, prices, n);

            profit = Math.max(ifSell, ifNotSell);
        }

        return profit;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Memoization(int index, int canBuyStock, int[] prices, int n, int dp[][]) {
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
            int isBought = -prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp);

            int isNotBought = Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp);

            profit = Math.max(isBought, isNotBought);
        } else {
            // if cant buy means only we can sell, so if sold then profit will be
            int ifSell = prices[index] + Stocks_Buy_Sell_Memoization(index + 2, 1, prices, n, dp);

            // if not sold today
            int ifNotSell = 0 + Stocks_Buy_Sell_Memoization(index + 1, 0, prices, n, dp);

            profit = Math.max(ifSell, ifNotSell);
        }

        dp[index][canBuyStock] = profit;
        return profit;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Stocks_Buy_Sell_Tabulation(int[] prices, int n) {

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
                    if(i+2 <=n ){
                        profit = Math.max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                    }else{
                        profit = Math.max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);   
                    }
                }
                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n) {

        int next_1[] = new int[2];  // i + 1
        int next_2[] = new int[2];  // i + 2
        // base case
        // if (index >= n) return 0;
        // for last index
        // next[0] = 0; // if bought and sold on same day
        // next[1] = 0; // if bought, then our account is running in -ve on last day

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr[] = new int[2];
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy == 1) {
                    // can bought
                    profit = Math.max(next_1[0] - prices[i], next_1[1]);
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + next_2[1], 0 + next_1[0]);
                }
                curr[canBuy] = profit;
            }
            // update curr
            next_2 = next_1;
            next_1 = curr;
        }
        return next_1[1];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    public static int Stocks_Buy_Sell_DPOptimized_1(int[] prices, int n) {
        int next_1_0=0;
        int next_1_1=0;

        // int next_2_0=0;
        int next_2_1=0;
        // base case
        // if (index >= n) return 0;
        
        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr_0=0;
            int curr_1=0;
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                int profit = 0;
                if (canBuy == 1) {
                    // can bought
                    profit = Math.max(next_1_0 - prices[i], next_1_1);
                    curr_1 = profit;
                } else {
                    // cannot buy, then sell
                    profit = Math.max(prices[i] + next_2_1, 0 + next_1_0);
                    curr_0 = profit;
                }
            }
            // update all next 
            // next_2_0 = next_1_0;
            next_2_1 = next_1_1;

            next_1_0 = curr_0;
            next_1_1 = curr_1;
        }
        return next_1_1;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Recursion(0, 1, prices, n);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n + 1][2];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Stocks_Buy_Sell_Memoization(0, 1, prices, n, dp);
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
