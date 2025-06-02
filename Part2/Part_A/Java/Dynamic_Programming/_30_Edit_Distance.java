package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _30_Edit_Distance {
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
     * Given two strings word1 and word2, return the minimum number of operations
     * required to convert word1 to word2.
     * 
     * You have the following three operations permitted on a word:
     * 
     * Insert a character
     * Delete a character
     * Replace a character
     * 
     * Example 1:
     * 
     * Input: word1 = "horse", word2 = "ros"
     * Output: 3
     * Explanation:
     * horse -> rorse (replace 'h' with 'r')
     * rorse -> rose (remove 'r')
     * rose -> ros (remove 'e')
     * 
     * Example 2:
     * 
     * Input: word1 = "intention", word2 = "execution"
     * Output: 5
     * Explanation:
     * intention -> inention (remove 't')
     * inention -> enention (replace 'i' with 'e')
     * enention -> exention (replace 'n' with 'x')
     * exention -> exection (replace 'n' with 'c')
     * exection -> execution (insert 'u')
     * 
     */

    /*
     * SOLUTION:
     * 
     * Count the number of s2 in s1
     * 
     * when a character is matched it can be picked as a subseq. or not picked as we
     * can choose next character as well
     * 
     */

    // Brute force: TLE T.C: O(2^n x 2^m) S.C: (n+m)
    public static int Edit_Distance_Recursion(int i, int j, String str1, String str2) {
        // base case change
        if (j < 0) {
            // s2 is empty, so converting s1 to empty string will needed to delete i+1
            // operations
            return i + 1;
        }
        if (i < 0) {
            // s1 is empty, so j+1 operations needed to convert emptt string to s2
            return j + 1;
        }

        // if characters matched
        if (str1.charAt(i) == str2.charAt(j)) {
            // just move
            return Edit_Distance_Recursion(i - 1, j - 1, str1, str2);
        }

        // if characters are not matched
        // do all operations
        int insert = 1 + Edit_Distance_Recursion(i, j - 1, str1, str2);
        int delete = 1 + Edit_Distance_Recursion(i - 1, j, str1, str2);
        int replace = 1 + Edit_Distance_Recursion(i - 1, j - 1, str1, str2);

        // return min operations required to convert s1 to s2
        return Math.min(replace, Math.min(delete, insert));
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Edit_Distance_Memoization(int i, int j, String str1, String str2, int dp[][]) {
        // base case change
        if (j < 0) {
            // s2 is empty, so converting s1 to empty string will needed to delete i+1
            // operations
            return i + 1;
        }
        if (i < 0) {
            // s1 is empty, so j+1 operations needed to convert emptt string to s2
            return j + 1;
        }

        // check if there is subproblem solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if characters matched
        if (str1.charAt(i) == str2.charAt(j)) {
            // just move
            dp[i][j] = Edit_Distance_Memoization(i - 1, j - 1, str1, str2, dp);
            return dp[i][j];
        }

        // if characters are not matched
        // do all operations
        int insert = 1 + Edit_Distance_Memoization(i, j - 1, str1, str2, dp);
        int delete = 1 + Edit_Distance_Memoization(i - 1, j, str1, str2, dp);
        int replace = 1 + Edit_Distance_Memoization(i - 1, j - 1, str1, str2, dp);

        // return min operations required to convert s1 to s2
        dp[i][j] = Math.min(replace, Math.min(delete, insert));
        return dp[i][j];
    }

    public static int Edit_Distance_Recursion_Shifting_Index(int i, int j, String str1, String str2) {
        // base case change
        if (j == 0) {
            // all characters in s2 are matched
            return i; // as doing 1 based indexing i=3, it will return 2nd index (i+1) => 3
        }
        if (i == 0) {
            // there is no s1 to match s2 with
            return j;
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            return Edit_Distance_Recursion_Shifting_Index(i - 1, j - 1, str1, str2);
        }

        // if characters are not matched
        // do all operations
        int insert = 1 + Edit_Distance_Recursion_Shifting_Index(i, j - 1, str1, str2);
        int delete = 1 + Edit_Distance_Recursion_Shifting_Index(i - 1, j, str1, str2);
        int replace = 1 + Edit_Distance_Recursion_Shifting_Index(i - 1, j - 1, str1, str2);

        // return min operations required to convert s1 to s2
        return Math.min(replace, Math.min(delete, insert));
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Edit_Distance_Memoization_Shifting_Index(int i, int j, String str1, String str2,
            int dp[][]) {
        // base case change
        if (j == 0) {
            // there is no s1 to match s2 with
            return i;
        }

        if (i == 0) {
            // all characters in s2 are matched
            return j;
        }

        // check if subproblems are previously solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            // just move
            dp[i][j] = Edit_Distance_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp);
            return dp[i][j];
        }

        // if characters are not matched
        // do all operations
        int insert = 1 + Edit_Distance_Memoization_Shifting_Index(i, j - 1, str1, str2, dp);
        int delete = 1 + Edit_Distance_Memoization_Shifting_Index(i - 1, j, str1, str2, dp);
        int replace = 1 + Edit_Distance_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp);

        // return min operations required to convert s1 to s2
        dp[i][j] = Math.min(replace, Math.min(delete, insert));
        return dp[i][j];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Edit_Distance_Tabulation(int n, int m, String str1, String str2) {

        // Shifting index by +1 => n+1, m+1
        int dp[][] = new int[n + 1][m + 1];

        // base case
        // i==0 return j
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // j==0 return 1;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j <= m; j++) {
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {

                    // if characters are not matched
                    // do all operations
                    int insert = 1 + dp[i][j - 1];
                    int delete = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    // return min operations required to convert s1 to s2
                    dp[i][j] = Math.min(replace, Math.min(delete, insert));
                }
            }
        }
        return dp[n][m];
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static int Edit_Distance_DPOptimized(int n, int m, String str1, String str2) {
        // Shifting index by +1 => n+1, m+1
        int prev[] = new int[m + 1];

        // base case
        // i==0 return j
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            int curr[] = new int[m + 1];

            // i=0
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    curr[j] = prev[j - 1];
                } else {

                    // if characters are not matched
                    // do all operations
                    int insert = 1 + curr[j - 1];
                    int delete = 1 + prev[j];
                    int replace = 1 + prev[j - 1];

                    // return min operations required to convert s1 to s2
                    curr[j] = Math.min(replace, Math.min(delete, insert));
                }
            }
            // update prev
            prev = curr;
        }
        return prev[m];
    }

    // DP optimized 1D aray
    // T.C: O(n x m), S.C:O(m)
    // public static int Edit_Distance_DPOptimized_1D_Array(int n, int m, String str1, String str2) {
    //     // Shifting index by +1 => n+1, m+1
    //     int prev[] = new int[m + 1];

    //     // base case
    //     // i==0 return j
    //     for (int j = 0; j <= m; j++) {
    //         prev[j] = j;
    //     }

    //     // recurrence relation
    //     for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
    //         int curr = i;
    //         int curr_1 = 0;
            
    //         for (int j = 1; j <= m; j++) {
    //             // if characters matched
    //             if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
    //                 curr = prev[j - 1];
    //             } else {

    //                 // if characters are not matched
    //                 // do all operations
    //                 int insert = 1 + curr_1;
    //                 int delete = 1 + prev[j];
    //                 int replace = 1 + prev[j - 1];

    //                 // return min operations required to convert s1 to s2
    //                 prev[j] = Math.min(replace, Math.min(delete, insert));
    //             }
    //             curr_1=curr;
    //             curr=prev[j];
    //         }
    //     }
    //     return prev[m];
    // }

    public static void solve(FastReader sc) {
        String str1 = "";
        String str2 = "";

        str1 = sc.nextLine();
        str2 = sc.nextLine();

        int n = str1.length();
        int m = str2.length();

        int dp[][] = new int[n][m];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        /*
         * SOLUTION:
         * Try All possible operations
         * 
         * insert -> hypotetically insert a matching element and move in s2 as s1 & s2's
         * element is matched,but hypothetically nothing has done with s1
         * fun(i, j-1)
         * 
         * delete -> delete the ith element and check with next element
         * fun(i-1,j)
         * 
         * replace -> change element of s1 to matching character of s2, both will move
         * fun(i-1,j-1)
         * 
         * return MIN of all of the operations
         * 
         */

        int ans = Edit_Distance_Recursion(n - 1, m - 1, str1, str2);
        System.out.println("Brute force:" + ans);

        ans = Edit_Distance_Memoization(n - 1, m - 1, str1, str2, dp);
        System.out.println("DP Memoization:" + ans);

        // just add +1 to everything
        ans = Edit_Distance_Recursion_Shifting_Index(n, m, str1, str2);
        System.out.println("Brute force Shifting Index:" + ans);

        dp = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Edit_Distance_Memoization_Shifting_Index(n, m, str1, str2, dp);
        System.out.println("DP Memoization Shifing index:" + ans);

        ans = Edit_Distance_Tabulation(n, m, str1, str2);
        System.out.println("DP Tabulation:" + ans);

        ans = Edit_Distance_DPOptimized(n, m, str1, str2);
        System.out.println("DP Optimized 1:" + ans);

        // ans = Edit_Distance_DPOptimized_1D_Array(n, m, str1, str2);
        // System.out.println("DP Optimized 1:" + ans);
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
