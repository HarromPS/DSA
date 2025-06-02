package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _31_Wildcard_Matching {
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
     * Problem Statement: Wildcard Matching
     * 
     * Given an input string (s) and a pattern (p), implement wildcard pattern
     * matching with support for '?' and '*' where:
     * 
     * '?' Matches any single character.
     * '*' Matches any sequence of characters (including the empty sequence).
     * 
     * The matching should cover the entire input string (not partial).
     * 
     * Example 1:
     * 
     * Input: s = "aa", p = "a"
     * Output: false
     * Explanation: "a" does not match the entire string "aa".
     * 
     * Example 2:
     * 
     * Input: s = "aa", p = "*"
     * Output: true
     * Explanation: '*' matches any sequence.
     * 
     * Example 3:
     * 
     * Input: s = "cb", p = "?a"
     * Output: false
     * Explanation: '?' matches 'c', but the second letter is 'a', which does not
     * match 'b'.
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
    public static boolean WildCard_Matching_Recursion(int i, int j, String str1, String str2) {
        // base case change
        if (i < 0 && j < 0) {
            // means s1 is covered by pattern s2
            return true;
        }
        if (i < 0 && j >= 0) {
            // means s1 is empty, so there must be only * to cover empty string
            for (int x = 0; x <= j; x++) {
                if (str2.charAt(x) != '*') {
                    return false;
                }
            }
            return true;
        }
        if (i >= 0 && j < 0) {
            // means s2 is empty, so there must be any pattern to match in s1, but empty
            return false;
        }

        // if characters matched then it will be
        // either matched character of '?'
        if (str1.charAt(i) == str2.charAt(j) || str2.charAt(j) == '?') {
            // just moveb
            return WildCard_Matching_Recursion(i - 1, j - 1, str1, str2);
        } else if (str2.charAt(j) == '*') {
            // we can say * mathces with character in s1 OR we say it does not comes under
            // * subsequence
            boolean isPartOfStar = WildCard_Matching_Recursion(i - 1, j, str1, str2);
            boolean isNotPartOfStar = WildCard_Matching_Recursion(i, j - 1, str1, str2);

            return (isPartOfStar || isNotPartOfStar);
        }

        // no pattern to match
        return false;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static boolean WildCard_Matching_Memoization(int i, int j, String str1, String str2, int dp[][]) {
        // base case change
        if (i < 0 && j < 0) {
            // means s1 is covered by pattern s2
            return true;
        }
        if (i < 0 && j >= 0) {
            // means s1 is empty, so there must be only * to cover empty string
            for (int x = 0; x <= j; x++) {
                if (str2.charAt(x) != '*') {
                    return false;
                }
            }
            return true;
        }
        if (i >= 0 && j < 0) {
            // means s2 is empty, so there must be any pattern to match in s1, but empty
            return false;
        }

        // check if previously solved
        if (dp[i][j] != -1) {
            if (dp[i][j] == 1) {
                return true;
            }
            return false;
        }

        // if characters matched then it will be
        // either matched character of '?'
        if (str1.charAt(i) == str2.charAt(j) || str2.charAt(j) == '?') {
            // just moveb
            boolean ans = WildCard_Matching_Memoization(i - 1, j - 1, str1, str2, dp);
            if (ans == true) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
            return ans;
        } else if (str2.charAt(j) == '*') {
            // we can say * mathces with character in s1 OR we say it does not comes under
            // * subsequence
            boolean isPartOfStar = WildCard_Matching_Memoization(i - 1, j, str1, str2, dp);
            boolean isNotPartOfStar = WildCard_Matching_Memoization(i, j - 1, str1, str2, dp);

            boolean ans = (isPartOfStar || isNotPartOfStar);
            if (ans == true) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
            return ans;
        }

        // no pattern to match
        dp[i][j] = 0;
        return false;
    }

    public static boolean WildCard_Matching_Recursion_Shifting_Index(int i, int j, String str1, String str2) {
        // 1 based indexing i->i-1, j->j-1
        // n-1 => n, m-1=>m
        // i<0 => i, j>=0 => j>0
        // base case change
        if (i == 0 && j == 0) {
            // means s1 is covered by pattern s2
            return true;
        }
        if (i == 0 && j > 0) {
            // means s1 is empty, so there must be only * to cover empty string
            for (int x = 1; x <= j; x++) {
                if (str2.charAt(x - 1) != '*') {
                    return false;
                }
            }
            return true;
        }
        if (i > 0 && j == 0) {
            // means s2 is empty, so there must be any pattern to match in s1, but empty
            return false;
        }

        // if characters matched then it will be
        // either matched character of '?'
        if (str1.charAt(i - 1) == str2.charAt(j - 1) || str2.charAt(j - 1) == '?') {
            // just moveb
            return WildCard_Matching_Recursion_Shifting_Index(i - 1, j - 1, str1, str2);
        } else if (str2.charAt(j - 1) == '*') {
            // we can say * mathces with character in s1 OR we say it does not comes under
            // * subsequence
            boolean isPartOfStar = WildCard_Matching_Recursion_Shifting_Index(i - 1, j, str1, str2);
            boolean isNotPartOfStar = WildCard_Matching_Recursion_Shifting_Index(i, j - 1, str1, str2);

            return (isPartOfStar || isNotPartOfStar);
        }

        // no pattern to match
        return false;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static boolean WildCard_Matching_Memoization_Shifting_Index(int i, int j, String str1, String str2,
            int dp[][]) {
        // 1 based indexing i->i-1, j->j-1
        // n-1 => n, m-1=>m
        // i<0 => i, j>=0 => j>0
        // base case change
        if (i == 0 && j == 0) {
            // means s1 is covered by pattern s2
            return true;
        }
        if (i == 0 && j > 0) {
            // means s1 is empty, so there must be only * to cover empty string
            for (int x = 1; x <= j; x++) {
                if (str2.charAt(x - 1) != '*') {
                    return false;
                }
            }
            return true;
        }
        if (i > 0 && j == 0) {
            // means s2 is empty, so there must be any pattern to match in s1, but empty
            return false;
        }

        // check if previously solved
        if (dp[i][j] != -1) {
            if (dp[i][j] == 1) {
                return true;
            }
            return false;
        }

        // if characters matched then it will be
        // either matched character of '?'
        if (str1.charAt(i - 1) == str2.charAt(j - 1) || str2.charAt(j - 1) == '?') {
            // just moveb
            boolean ans = WildCard_Matching_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp);
            if (ans == true) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
            return ans;
        } else if (str2.charAt(j - 1) == '*') {
            // we can say * mathces with character in s1 OR we say it does not comes under
            // * subsequence
            boolean isPartOfStar = WildCard_Matching_Memoization_Shifting_Index(i - 1, j, str1, str2, dp);
            boolean isNotPartOfStar = WildCard_Matching_Memoization_Shifting_Index(i, j - 1, str1, str2, dp);

            boolean ans = (isPartOfStar || isNotPartOfStar);
            if (ans == true) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
            return ans;
        }

        // no pattern to match
        dp[i][j] = 0;
        return false;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static boolean WildCard_Matching_Tabulation(int n, int m, String str1, String str2) {
        // 1 based indexing

        // Shifting index by +1 => n+1, m+1
        boolean dp[][] = new boolean[n + 1][m + 1];

        // base case
        // i==0 && j==0
        dp[0][0] = true;

        // if (i > 0 && j == 0)
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // if (i == 0 && j > 0) using 1 based indexing
        for (int j = 1; j <= m; j++) {
            boolean flag = true;
            for (int x = 1; x <= j; x++) {
                if (str2.charAt(x - 1) != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j <= m; j++) {
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1) || str2.charAt(j - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (str2.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static boolean WildCard_Matching_DPOptimized(int n, int m, String str1, String str2) {
        // 1 based indexing

        // Shifting index by +1 => n+1, m+1
        boolean prev[] = new boolean[m + 1];

        // base case
        // i==0 && j==0
        prev[0] = true;

        for (int j = 1; j <= m; j++) {
            boolean flag = true;
            for (int x = 1; x <= j; x++) {
                if (str2.charAt(x - 1) != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            boolean curr[] = new boolean[m + 1];

            curr[0]=false;

            for (int j = 1; j <= m; j++) {                
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1) || str2.charAt(j - 1) == '?') {
                    curr[j] = prev[j - 1];
                } else if (str2.charAt(j - 1) == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }

            // update prev
            prev=curr;
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

        int dp[][] = new int[n][m];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        boolean ans = WildCard_Matching_Recursion(n - 1, m - 1, str1, str2);
        System.out.println("Brute force:" + ans);

        ans = WildCard_Matching_Memoization(n - 1, m - 1, str1, str2, dp);
        System.out.println("DP Memoization:" + ans);

        // just add +1 to everything
        ans = WildCard_Matching_Recursion_Shifting_Index(n, m, str1, str2);
        System.out.println("Brute force Shifting Index:" + ans);

        dp = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = WildCard_Matching_Memoization_Shifting_Index(n, m, str1, str2, dp);
        System.out.println("DP Memoization Shifing index:" + ans);

        ans = WildCard_Matching_Tabulation(n, m, str1, str2);
        System.out.println("DP Tabulation:" + ans);

        ans = WildCard_Matching_DPOptimized(n, m, str1, str2);
        System.out.println("DP Optimized 1:" + ans);

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
