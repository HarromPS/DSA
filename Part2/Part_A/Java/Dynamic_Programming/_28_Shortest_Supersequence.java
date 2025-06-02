package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _28_Shortest_Supersequence {
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
     * Problem statement: Delete Operation for Two Strings to make both equal
     * 
     * Given two strings str1 and str2, return the shortest string that has both
     * str1 and str2 as subsequences.
     * If there are multiple valid strings, return any of them.
     * 
     * A string s is a subsequence of string t if deleting some number of characters
     * from t (possibly 0) results in the string s.
     * 
     * Example 1:
     * 
     * Input: str1 = "abac", str2 = "cab"
     * Output: "cabac"
     * Explanation:
     * str1 = "abac" is a subsequence of "cabac" because we can delete the first
     * "c".
     * str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
     * The answer provided is the shortest such string that satisfies these
     * properties.
     * 
     * Example 2:
     * 
     * Input: str1 = "brute", str2 = "groot"
     * Output: "gbruoote" or "bgruoote"
     * 
     * 
     */

    /*
     * SOLUTION:
     * Number of Characters which are not matched from collectively both the strings
     * if we remove those characters from both of them, so we can make word1 and
     * word2 same i.e LCS will remain only
     * 
     * Ans=> [ (s.length() - lcs.length()) + (s2.length() - lcs.length()) ];
     */

    // Brute force: TLE T.C: O(2^n x 2^m) S.C: (n+m)
    // f(i,j): lcs of str1 from 0 to i && str2 from 0 to j
    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Shortest_Supersequence_Recursion_Striver(int i, int j, String str1,
            String str2) {
        // base case change
        // if any index goes out of boundary
        if (i == 0 || j == 0) {
            // lcs is 0
            return 0;
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            // 1 means 1 length string matched
            int res = 1 + Shortest_Supersequence_Recursion_Striver(i - 1, j - 1, str1, str2);
            return res;
        }

        // if characters are not matched
        // check by moving 1 index left on both strings
        int move_i = 0 + Shortest_Supersequence_Recursion_Striver(i - 1, j, str1, str2);

        int move_j = 0 + Shortest_Supersequence_Recursion_Striver(i, j - 1, str1, str2);

        return Math.max(move_i, move_j);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Shortest_Supersequence_Memoization_Shifting_Index_Striver(int i, int j,
            String str1, String str2, int dp[][]) {
        // base case change
        // if any index goes out of bounary
        if (i == 0 || j == 0) {
            // lcs is 0
            return 0;
        }

        // check if previously solved subproblems
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            // 1 means 1 length string matched
            int res = 1 + Shortest_Supersequence_Memoization_Shifting_Index_Striver(i - 1,
                    j - 1, str1, str2, dp);
            dp[i][j] = res;
            return dp[i][j];
        }

        // if characters are not matched
        // check by moving 1 index left on both strings
        int move_i = 0 + Shortest_Supersequence_Memoization_Shifting_Index_Striver(i - 1, j,
                str1, str2, dp);

        int move_j = 0 + Shortest_Supersequence_Memoization_Shifting_Index_Striver(i, j - 1,
                str1, str2, dp);

        dp[i][j] = Math.max(move_i, move_j);
        return dp[i][j];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Shortest_Supersequence_Tabulation(int n, int m, String str1, String str2) {

        /*
         * We know to make a string by combining characters from s1 and s2 to make
         * shortest
         * string which contains both s1 and s2
         * 
         * some from s1 + some common in s1 & s2 + some from s2
         * 
         * We know common is LCS
         * So, lengt of supersequence => (n-lcs + m-lcs + lcs) remove lcs from s1 and s2
         * and add only one common sequence
         * => (n+m-lcs) is length
         * 
         * Now string, backtrack using match and not match rule
         * 
         * if match move (i-1)(j-1) add common only once
         * 
         * if not move max([i-1][j], [i][j-1]) add left out character
         */
        int dp[][] = new int[n + 1][m + 1];

        // base case
        // i==0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        // j==0
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j <= m; j++) {
                // if matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    // 1 means 1 length string matched
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // if not matched
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        String s = "";
        while (i > 0 && j > 0) {
            // if matched
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                s += String.valueOf(str1.charAt(i - 1));
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                s += String.valueOf(str1.charAt(i - 1));
                i--;
            } else {
                s += String.valueOf(str2.charAt(j - 1));
                j--;

            }
        }

        if (i == 0 && j == 0)

        { // means both strings are covered
            System.out.println("Reversed answer: " + s);
        }
        

        // take all from s2 
        while(i > 0) {
            s += str1.charAt(i - 1);
            i--;
        } 
        // take all from s1
        while(j>0) {
            s += str2.charAt(j - 1);
            j--;
        }

        // reverse the string as reverse back
        String ans = "";
        for (i = s.length() - 1; i >= 0; i--) {
            ans += s.charAt(i);
        }
        System.out.println("Shortest common supersequence: " + ans);
        return dp[n][m];
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static int Shortest_Supersequence_DPOptimized(int n, int m, String str1,
            String str2) {
        // we require only 2 arrays
        int prev[] = new int[m + 1];

        // base case
        // j==0
        for (int i = 0; i <= m; i++)
            prev[i] = 0;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            int curr[] = new int[m + 1];
            for (int j = 1; j <= m; j++) {
                // if matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    // 1 means 1 length string matched
                    curr[j] = 1 + prev[j - 1];
                } else {
                    // if not matched
                    curr[j] = Math.max(prev[j], curr[j - 1]);
                }
            }
            // update prev
            prev = curr;
        }
        return prev[m];
    }

    public static void solve(FastReader sc) {
        String str1 = "";
        String str2 = "";

        str1 = sc.nextLine();
        str2 = sc.nextLine();

        int n = str1.length();
        int m = str2.length();

        int dp[][] = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        /*
         * SOLUTION:
         * Number of Characters which are not matched from collectively both the strings
         * if we remove those characters from both of them, so we can make word1 and
         * word2 same i.e LCS will remain only
         * 
         * Ans=> [ (s.length() - lcs.length()) + (s2.length() - lcs.length()) ];
         */

        int ans = Shortest_Supersequence_Recursion_Striver(n, m, str1, str2);
        System.out.println("Brute force Striver:" + ans);

        ans = Shortest_Supersequence_Memoization_Shifting_Index_Striver(n, m, str1, str2,
                dp);
        System.out.println("DP Memoization Shifing index:" + ans);

        // CHECK OPTIMIZED : TRICK
        ans = Shortest_Supersequence_Tabulation(n, m, str1, str2);
        System.out.println("DP Tabulation:" + ans);

        ans = Shortest_Supersequence_DPOptimized(n, m, str1, str2);
        System.out.println("DP Optimized 1:" + ans);

        // ans = Shortest_Supersequence_DPOptimized_2(targetN, price, n);
        // System.out.println("DP Optimized 2:" + ans);
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
