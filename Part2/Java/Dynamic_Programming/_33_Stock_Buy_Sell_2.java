package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _33_Stock_Buy_Sell_2 {
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
     * stock on the ith day.
     * 
     * On each day, you may decide to buy and/or sell the stock. You can only hold
     * at most one share of the stock at any time.
     * However, you can buy it then immediately sell it on the same day.
     * 
     * Find and return the maximum profit you can achieve.
     * 
     * Input: prices = [7,1,5,3,6,4]
     * Output: 7
     * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
     * 5-1 = 4.
     * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
     * 3.
     * Total profit is 4 + 3 = 7.
     * 
     * Example 2:
     * 
     * Input: prices = [1,2,3,4,5]
     * Output: 4
     * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
     * 5-1 = 4.
     * Total profit is 4.
     * 
     * Example 3:
     * 
     * Input: prices = [7,6,4,3,1]
     * Output: 0
     * Explanation: There is no way to make a positive profit, so we never buy the
     * stock to achieve the maximum profit of 0.
     * 
     */

    // Brute force: TLE T.C: O(n^2) S.C: (1)
    // FIND MAX PROFIT WE CAN MAKE ON EACH DAY BY CHECKING MAX SELL PRICE IN FUTURE
    public static int Stocks_Buy_Sell_Brute(int[] prices) {
        int maxProfit = 0;
        int n = prices.length;
        for (int i = 0; i < n - 1; i++) {
            int currMax = prices[i];
            for (int j = i + 1; j < n; j++) {
                currMax = Math.max(currMax, prices[j]);
            }
            maxProfit = Math.max(maxProfit, currMax - prices[i]);
        }
        return maxProfit;
    }

    // Better/Optimal T.C: O(n), S.C: O(1)
    // CHECK LAST DAY BUY PRICE & IF CURR DAY SELL IS MORE THEN BUY PREV DAYS' AND
    // GET MAX PROFIT
    public static int Stocks_Buy_Sell_Better(int[] prices) {
        int n = prices.length;
        int maxProfit = 0;
        int prevDayBuy = prices[0];
        for (int i = 1; i < n; i++) {
            int currDaySell = prices[i];
            if (currDaySell > prevDayBuy) {
                maxProfit += (currDaySell - prevDayBuy);
            }
            prevDayBuy = prices[i];

        }
        return maxProfit;
    }

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    // we can do buy on ith day or not buy
    // if buy then cant buy again until sell
    // can sell (for a good price) or not sell (wait for better price)
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
            // if cant buy means only we can sell, so if sold then profit will be
            int ifSell = prices[index] + Stocks_Buy_Sell_Recursion(index + 1, 1, prices, n);

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
            int ifSell = prices[index] + Stocks_Buy_Sell_Memoization(index + 1, 1, prices, n, dp);

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
                    profit = Math.max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

    // DP Optimized
    public static int Stocks_Buy_Sell_DPOptimized(int[] prices, int n) {

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
                    profit = Math.max(prices[i] + next[1], 0 + next[0]);
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
    public static int Stocks_Buy_Sell_DPOptimized_1(int[] prices, int n) {

        // base case
        // if (index >= n) return 0;
        // for last index
        int next_0=0;   // if bought and sold on same day
        int next_1=0;   // if bought, then our account is running in -ve on last day

        // recurrence relation
        for (int i = n - 1; i >= 0; i--) {
            int curr_0=0;
            int curr_1=0;

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

        int ans = Stocks_Buy_Sell_Brute(prices);
        System.out.println("Brute force:" + ans);

        ans = Stocks_Buy_Sell_Better(prices);
        System.out.println("Better Approach:" + ans);

        ans = Stocks_Buy_Sell_Recursion(0, 1, prices, n);
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
