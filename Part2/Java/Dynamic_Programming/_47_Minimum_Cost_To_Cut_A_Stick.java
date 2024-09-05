package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _47_Minimum_Cost_To_Cut_A_Stick {
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
     * Minimum Cost to Cut a Stick
     * 
     * Given a wooden stick of length n units. The stick is labelled from 0 to n.
     * For example, a stick of length 6 is labelled as follows:
     * 
     * Given an integer array cuts where cuts[i] denotes a position you should
     * perform a cut at.
     * 
     * You should perform the cuts in order, you can change the order of the cuts as
     * you wish.
     * 
     * The cost of one cut is the length of the stick to be cut, the total cost is
     * the sum of costs of all cuts. When you cut a stick, it will be split into two
     * smaller sticks (i.e. the sum of their lengths is the length of the stick
     * before the cut). Please refer to the first example for a better explanation.
     * 
     * Return the minimum total cost of the cuts.
     * 
     * Example 1:
     * 
     * Input: n = 7, cuts = [1,3,4,5]
     * Output: 16
     * Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the
     * following scenario:
     * 
     * The first cut is done to a rod of length 7 so the cost is 7. The second cut
     * is done to a rod of length 6 (i.e. the second part of the first cut), the
     * third is done to a rod of length 4 and the last cut is to a rod of length 3.
     * The total cost is 7 + 6 + 4 + 3 = 20.
     * Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario
     * with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
     */

    // Brute force
    public static int Cost_Of_A_Stick_Recursion(int i, int j, int cuts[]) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0;   // cost required is 0
        }

        int ans = (int) (1e9);
        // try all partitions (run loop)
        for (int ind = i; ind <= j; ind++) {
            int cost = (cuts[j + 1] - cuts[i - 1]) + Cost_Of_A_Stick_Recursion(i, ind-1, cuts) + Cost_Of_A_Stick_Recursion(ind+1, j, cuts);

            // minimize cost of all cuts
            ans=Math.min(ans, cost);
        }

        // return best possible
        return ans;
    }

    // DP Memoization
    public static int Cost_Of_A_Stick_Memoization(int i, int j, int cuts[], int dp[][]) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0;   // cost required is 0
        }

        // check if subproblems are solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = (int) (1e9);
        // try all partitions (run loop)
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j+1] - cuts[i-1] + Cost_Of_A_Stick_Memoization(i, ind-1, cuts, dp) + Cost_Of_A_Stick_Memoization(ind+1, j, cuts, dp);

            ans = Math.min(ans, cost);
        }

        // return best possible
        dp[i][j] = ans;
        return ans;
    }

    // DP Tabulation
    public static int Cost_Of_A_Stick_Tabulation(int cuts[], int n) {
        int dp[][] = new int[n+2][n+2];

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
                if(i>j){
                    continue;
                }
                int ans = (int) (1e9);
                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    ans =  Math.min(ans,cost);                    
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }

    // // DP Optimized
    // public static int Cost_Of_A_Stick_Optimized(int cuts[], int n) {
    //     int prev[] = new int[n+2];

    //     // 1. base case
    //     // if i>j return 0

    //     // 2. indexes
    //     // in recursion fun(1, n) (i,j)
    //     // i -> 1 to n & j -> n to 1

    //     // in tabulation 
    //     // i -> n to 1 & j -> 1 to n
        
    //     // 3.recurrence relation
    //     for (int i = n; i >= 1; i--) {
    //         int curr[] = new int[n+2];
    //         for (int j = 1; j <= n; j++) {
    //             if(i>j){
    //                 continue;
    //             }
    //             int ans = (int) (1e9);
    //             for (int ind = i; ind <= j; ind++) {
    //                 int cost = cuts[j+1]-cuts[i-1] + prev[i] + prev[ind+1];
    //                 ans =  Math.min(ans,cost);                    
    //             }
    //             curr[j] = ans;
    //         }
    //         // update prev
    //         prev = curr;
    //     }
    //     return prev[n];
    // }

    public static void solve(FastReader sc) {
        int len = sc.nextInt();     // length of the stick
        int n = sc.nextInt();

        int arr[] = new int[n+2];

        // Note: add 0 and max length at the end of array
        arr[0]=0;
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        arr[n+1] = len;

        // Sort to partition independently
        Arrays.sort(arr);
        
        int dp[][] = new int[n+1][n+1];
        for (int rows[] : dp) {
            Arrays.fill(rows, -1);
        }

        // Start with entire block
        // fun (1,4)=> return min no of multiplications to multilpy matrix (1 to 4)
        int ans = Cost_Of_A_Stick_Recursion(1, n, arr);
        System.out.println("Brute Force:" + ans);

        ans = Cost_Of_A_Stick_Memoization(1, n, arr, dp);
        System.out.println("DP DPOptimized Sriver:" + ans);

        ans = Cost_Of_A_Stick_Tabulation(arr, n);
        System.out.println("DP Tabulation Sriver:" + ans);

        // ans = Cost_Of_A_Stick_Optimized(arr, n);
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
