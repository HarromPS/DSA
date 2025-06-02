package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _48_Burst_Ballons {
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
     * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
     * with a number on it represented by an array nums. You are asked to burst all
     * the balloons.
     * 
     * If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i +
     * 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as
     * if there is a balloon with a 1 painted on it.
     * 
     * Return the maximum coins you can collect by bursting the balloons wisely.
     * 
     * Example 1:
     * 
     * Input: nums = [3,1,5,8]
     * Output: 167
     * Explanation:
     * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
     * coins = 3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167
     */

    
    // Solving this problem independantly will not work 
    // Brute force
    public static int Min_Cost_Burst_Ballon_Recursion(int i, int j, int nums[]) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0; // coins gain 0
        }

        int ans = (int) (-1e9); 
        // try all partitions (run loop)
        for (int ind = i; ind <= j; ind++) {
            int coins = nums[i-1] * nums[ind] * nums[j+1] + Min_Cost_Burst_Ballon_Recursion(i, ind - 1, nums) + Min_Cost_Burst_Ballon_Recursion(ind + 1, j, nums);;

            // minimize cost of all coins
            ans = Math.max(ans, coins);
        }

        // return best possible
        return ans;
    }

    // DP Memoization
    public static int Min_Cost_Burst_Ballon_Memoization(int i, int j, int nums[], int dp[][]) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0; // cost required is 0
        }

        // check if subproblems are solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = (int) (-1e9);
        // try all partitions (run loop)
        for (int ind = i; ind <= j; ind++) {
            int coins = nums[i-1] * nums[ind] * nums[j+1] + Min_Cost_Burst_Ballon_Memoization(i, ind - 1, nums, dp)+ Min_Cost_Burst_Ballon_Memoization(ind + 1, j, nums, dp);

            ans = Math.max(ans, coins);
        }

        // return best possible
        dp[i][j] = ans;
        return ans;
    }

    // DP Tabulation
    public static int Min_Cost_Burst_Ballon_Tabulation(int nums[], int n) {
        int dp[][] = new int[n + 2][n + 2];

        // 1. base case
        // if i>j return 0

        // 2. indexes
        // in recursion fun(1, n) (i,j)
        // i -> 1 to n & j -> n to 1

        // in tabulation
        // i -> n to 1 & j -> 1 to n

        // 3.recurrence relation
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) {
                    continue;
                }
                int ans = (int) (-1e9);
                for (int ind = i; ind <= j; ind++) {
                    int coins = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind - 1] + dp[ind + 1][j];
                    ans = Math.max(ans, coins);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }

    // // DP Optimized
    // public static int Min_Cost_Burst_Ballon_Optimized(int coins[], int n) {
    // int prev[] = new int[n+2];

    // // 1. base case
    // // if i>j return 0

    // // 2. indexes
    // // in recursion fun(1, n) (i,j)
    // // i -> 1 to n & j -> n to 1

    // // in tabulation
    // // i -> n to 1 & j -> 1 to n

    // // 3.recurrence relation
    // for (int i = n; i >= 1; i--) {
    // int curr[] = new int[n+2];
    // for (int j = 1; j <= n; j++) {
    // if(i>j){
    // continue;
    // }
    // int ans = (int) (1e9);
    // for (int ind = i; ind <= j; ind++) {
    // int cost = coins[j+1]-coins[i-1] + prev[i] + prev[ind+1];
    // ans = Math.min(ans,cost);
    // }
    // curr[j] = ans;
    // }
    // // update prev
    // prev = curr;
    // }
    // return prev[n];
    // }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n+2];

        // Note: add 0 and max length at the end of array
        arr[0]=1;
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        arr[n+1] = 1;

        int dp[][] = new int[n + 1][n + 1];
        for (int rows[] : dp) {
            Arrays.fill(rows, -1);
        }

        // Start with entire block
        int ans = Min_Cost_Burst_Ballon_Recursion(1, n, arr);
        System.out.println("Brute Force:" + ans);

        ans = Min_Cost_Burst_Ballon_Memoization(1, n, arr, dp);
        System.out.println("DP DPOptimized Sriver:" + ans);

        ans = Min_Cost_Burst_Ballon_Tabulation(arr, n);
        System.out.println("DP Tabulation Sriver:" + ans);

        // ans = Min_Cost_Burst_Ballon_Optimized(arr, n);
        // System.out.println("DP Optimized Sriver:" + ans);

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
