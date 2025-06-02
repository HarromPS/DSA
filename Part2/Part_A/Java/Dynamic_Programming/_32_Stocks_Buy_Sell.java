package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _32_Stocks_Buy_Sell {
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
     * 
     * Problem Statement: Best Time to Buy and Sell Stock
     * 
     * You are given an array prices where prices[i] is the price of a given stock
     * on the ith day.
     * 
     * You want to maximize your profit by choosing a single day to buy one stock
     * and choosing a different day in the future to sell that stock.
     * 
     * Return the maximum profit you can achieve from this transaction. If you
     * cannot achieve any profit, return 0.
     * 
     * Input: prices = [7,1,5,3,6,4]
     * Output: 5
     * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
     * 6-1 = 5.
     * Note that buying on day 2 and selling on day 1 is not allowed because you
     * must buy before you sell.
     * 
     * Example 2:
     * 
     * Input: prices = [7,6,4,3,1]
     * Output: 0
     * Explanation: In this case, no transactions are done and the max profit = 0.
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
    // CHECK LAST MAX SELL PRICE AND COMPARE CURRENT DAY PRICE IF CURRENT DAY BUY IS
    // < MAXSELL
    // MAKE PROFIT
    public static int Stocks_Buy_Sell_Better(int[] prices) {
        int n = prices.length;
        int maxProfit = 0;
        int maxSelling = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] < maxSelling) {
                maxProfit = Math.max(maxProfit, maxSelling - prices[i]);
            } else {
                maxSelling = prices[i];
            }
        }
        return maxProfit;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int prices[]=new int[n];
        for(int i=0;i<n;i++){
            prices[i]=sc.nextInt();
        }

        int ans = Stocks_Buy_Sell_Brute(prices);
        System.out.println("Brute force:" + ans);

        ans = Stocks_Buy_Sell_Better(prices);
        System.out.println("Better Approach:" + ans);

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
