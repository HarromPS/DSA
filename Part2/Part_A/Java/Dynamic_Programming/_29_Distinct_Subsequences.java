package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _29_Distinct_Subsequences {
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
     * Given two strings s and t, return the number of distinct subsequences of s
     * which equals t.
     * 
     * The test cases are generated so that the answer fits on a 32-bit signed
     * integer.
     * 
     * Example 1:
     * 
     * Input: s = "rabbbit", t = "rabbit"
     * Output: 3
     * Explanation:
     * As shown below, there are 3 ways you can generate "rabbit" from s.
     * rabbbit
     * rabbbit
     * rabbbit
     * 
     * Example 2:
     * 
     * Input: s = "babgbag", t = "bag"
     * Output: 5
     * Explanation:
     * As shown below, there are 5 ways you can generate "bag" from s.
     * babgbag
     * babgbag
     * babgbag
     * babgbag
     * babgbag
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
    public static int Distinct_Supersequence_Recursion(int i, int j, String str1, String str2) {
        // base case change
        if (j < 0) {
            // all characters in s2 are matched
            return 1;
        }
        if (i < 0 && j >= 0) {
            // there is no s1 to match s2 with
            return 0;
        }

        // if characters matched
        if (str1.charAt(i) == str2.charAt(j)) {
            // can be picked
            int pick = Distinct_Supersequence_Recursion(i - 1, j - 1, str1, str2);

            // or not picked
            int notPick = Distinct_Supersequence_Recursion(i - 1, j, str1, str2);

            return pick + notPick;
        }

        // if characters are not matched
        // reduce s1 as we have to search s2 in s1 until we found another 'g'
        int res = Distinct_Supersequence_Recursion(i - 1, j, str1, str2);
        return res;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Distinct_Supersequence_Memoization(int i, int j, String str1, String str2, int dp[][]) {
        // base case change
        if (j < 0) {
            // all characters in s2 are matched
            return 1;
        }
        if (i < 0 && j >= 0) {
            // there is no s1 to match s2 with
            return 0;
        }

        // check if subproblems are previously solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if characters matched
        if (str1.charAt(i) == str2.charAt(j)) {
            // can be picked
            int pick = Distinct_Supersequence_Memoization(i - 1, j - 1, str1, str2, dp);

            // or not picked
            int notPick = Distinct_Supersequence_Memoization(i - 1, j, str1, str2, dp);

            dp[i][j] = pick + notPick;
            return dp[i][j];
        }

        // if characters are not matched
        // reduce s1 as we have to search s2 in s1 until we found another 'g'
        int res = Distinct_Supersequence_Memoization(i - 1, j, str1, str2, dp);

        dp[i][j] = res;
        return res;
    }

    public static int Distinct_Supersequence_Recursion_Shifting_Index(int i, int j, String str1, String str2) {
        // base case change
        if (j == 0) {
            // all characters in s2 are matched
            return 1;
        }
        if (i == 0) {
            // there is no s1 to match s2 with
            return 0;
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            // can be picked
            int pick = Distinct_Supersequence_Recursion_Shifting_Index(i - 1, j - 1, str1, str2);

            // or not picked
            int notPick = Distinct_Supersequence_Recursion_Shifting_Index(i - 1, j, str1, str2);

            return pick + notPick;
        }

        // if characters are not matched
        // reduce s1 as we have to search s2 in s1 until we found another 'g'
        int res = Distinct_Supersequence_Recursion_Shifting_Index(i - 1, j, str1, str2);
        return res;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Distinct_Supersequence_Memoization_Shifting_Index(int i, int j, String str1, String str2,
            int dp[][]) {
        // base case change
        if (j == 0) {
            // there is no s1 to match s2 with
            return 1;
        }

        if (i == 0) {
            // all characters in s2 are matched
            return 0;
        }

        // check if subproblems are previously solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if characters matched
        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
            // can be picked
            int pick = Distinct_Supersequence_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp);

            // or not picked
            int notPick = Distinct_Supersequence_Memoization_Shifting_Index(i - 1, j, str1, str2, dp);

            dp[i][j] = pick + notPick;
            return dp[i][j];
        }

        // if characters are not matched
        // reduce s1 as we have to search s2 in s1 until we found another 'g'
        int res = Distinct_Supersequence_Memoization_Shifting_Index(i - 1, j, str1, str2, dp);

        dp[i][j] = res;
        return res;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Distinct_Supersequence_Tabulation(int n, int m, String str1, String str2) {

        // Shifting index by +1 => n+1, m+1
        int dp[][] = new int[n + 1][m + 1];

        // base case
        // i==0 return 0
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // j==0 return 1;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j <= m; j++) {
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    // can be picked
                    int pick = dp[i - 1][j - 1];

                    // or not picked
                    int notPick = dp[i - 1][j];

                    dp[i][j] = pick + notPick;
                } else {
                    // if characters are not matched
                    // reduce s1 as we have to search s2 in s1 until we found another 'g'
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static int Distinct_Supersequence_DPOptimized(int n, int m, String str1, String str2) {
        // Shifting index by +1 => n+1, m+1
        int prev[] = new int[m + 1];

        // base case
        // when j == 0, it will be 1
        // j==0 return 1;
        prev[0]=1;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            int curr[]=new int[m+1];
            curr[0]=1;  // j=0 return 1;

            for (int j = 1; j <= m; j++) {
                // if characters matched
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    // can be picked
                    int pick = prev[j - 1];

                    // or not picked
                    int notPick = prev[j];

                    curr[j] = pick + notPick;
                } else {
                    // if characters are not matched
                    // reduce s1 as we have to search s2 in s1 until we found another 'g'
                    curr[j] = prev[j];
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

        int ans = Distinct_Supersequence_Recursion(n - 1, m - 1, str1, str2);
        System.out.println("Brute force Striver:" + ans);

        ans = Distinct_Supersequence_Memoization(n - 1, m - 1, str1, str2, dp);
        System.out.println("DP Memoization Shifing index:" + ans);

        // just add +1 to everything
        ans = Distinct_Supersequence_Recursion_Shifting_Index(n, m, str1, str2);
        System.out.println("Brute force Striver:" + ans);

        dp = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Distinct_Supersequence_Memoization_Shifting_Index(n, m, str1, str2, dp);
        System.out.println("DP Memoization Shifing index:" + ans);

        ans = Distinct_Supersequence_Tabulation(n, m, str1, str2);
        System.out.println("DP Tabulation:" + ans);

        ans = Distinct_Supersequence_DPOptimized(n, m, str1, str2);
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
