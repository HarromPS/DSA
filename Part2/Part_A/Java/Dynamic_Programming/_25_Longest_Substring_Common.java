package Java.Dynamic_Programming;


import java.io.*;
import java.util.*;

public class _25_Longest_Substring_Common {
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
     Given two strings. The task is to find the length of the longest common substring.
     
     Substrings: Which follows Consecutive rule 
     Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
    Output: 4
    Explanation: The longest common substring
    is "CDGH" which has length 4.
     */

    // Brute force: TLE T.C: O(2^n x 2^m) S.C: (n+m)
    // f(i,j): lcs of str1 from 0 to i && str2 from 0 to j
    public static int Longest_Common_Substring_Recursion_1(int i, int j, String str1, String str2,int maxLen) {
        // base case
        // if any index goes out of bounary
        if (i < 0 || j < 0) {
            // lcs is 0
            return maxLen;
        }

        // gather only if characters matches
        if (str1.charAt(i) == str2.charAt(j)) {
            // 1 means 1 length string matched
            maxLen = Longest_Common_Substring_Recursion_1(i - 1, j - 1, str1, str2, maxLen + 1);
            return maxLen;
        }

        // but consecutive string is broken so maxLen string is 0

        // if characters are not matched
        // check by moving 1 index left on both strings

        maxLen = Math.max(maxLen, Math.max(Longest_Common_Substring_Recursion_1(i - 1, j, str1, str2, 0),Longest_Common_Substring_Recursion_1(i, j - 1, str1, str2, 0)));

        return maxLen;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    // public static int Longest_Common_Substring_Memoization_1(int i, int j, String str1, String str2, int dp[][],int maxLen) {
    //     // base case
    //     // if any index goes out of bounary
    //     if (i < 0 || j < 0) {
    //         // lcs is 0
    //         return maxLen;
    //     }

    //     // check if previously solved subproblems
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     // if characters matched
    //     if (str1.charAt(i) == str2.charAt(j)) {
    //         // 1 means 1 length string matched
    //         maxLen = Longest_Common_Substring_Memoization_1(i - 1, j - 1, str1, str2, dp, maxLen + 1);

    //         // save calculation
    //         dp[i][j]=maxLen;
    //         return dp[i][j];
    //     }

    //     // but consecutive string is broken so maxLen string is 0

    //     // if characters are not matched
    //     // check by moving 1 index left on both strings
    //     maxLen= Math.max(maxLen, Math.max(Longest_Common_Substring_Memoization_1(i - 1, j, str1, str2,dp, 0),Longest_Common_Substring_Memoization_1(i, j - 1, str1, str2,dp, 0)));

    //     dp[i][j] = maxLen;
    //     return dp[i][j];
    // }

    // Brute force: TLE T.C: O(2^n x 2^m) S.C: (n+m)
    // f(i,j): lcs of str1 from 0 to i && str2 from 0 to j
     // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Longest_Common_Substring_Recursion_Shifting_Index(int i, int j, String str1, String str2,int maxLen) {
        // base case change
        // if any index goes out of boundary
        if (i == 0 || j == 0) {
            // lcs is 0
            return maxLen;
        }

        // if characters matched
        if (str1.charAt(i-1) == str2.charAt(j-1)) {
            // 1 means 1 length string matched
            maxLen = Longest_Common_Substring_Recursion_Shifting_Index(i - 1, j - 1, str1, str2,maxLen+1);
            return maxLen;
        }

        // if characters are not matched
        // check by moving 1 index left on both strings
        maxLen = Math.max(maxLen, Math.max(maxLen,Math.max(Longest_Common_Substring_Recursion_Shifting_Index(i - 1, j, str1, str2, 0),Longest_Common_Substring_Recursion_Shifting_Index(i, j - 1, str1, str2, 0))));

        return maxLen;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    // public static int Longest_Common_Substring_Memoization_Shifting_Index(int i, int j, String str1, String str2, int dp[][],int maxLen) {
    //     // base case change
    //     // if any index goes out of bounary
    //     if (i == 0 || j == 0) {
    //         // lcs is 0
    //         return maxLen;
    //     }

    //     // check if previously solved subproblems
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     // if characters matched
    //     if (str1.charAt(i-1) == str2.charAt(j-1)) {
    //         // 1 means 1 length string matched
    //         maxLen = Longest_Common_Substring_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp,maxLen+1);
    //         dp[i][j]=maxLen;
    //         return dp[i][j];
    //     }

    //     // if characters are not matched
    //     // check by moving 1 index left on both strings
    //     int move_i = 0 + Longest_Common_Substring_Memoization_Shifting_Index(i - 1, j, str1, str2, dp, 0);

    //     int move_j = 0 + Longest_Common_Substring_Memoization_Shifting_Index(i, j - 1, str1, str2, dp, 0);

    //     maxLen = Math.max(maxLen,Math.max(move_i, move_j));
    //     dp[i][j] = maxLen;
    //     return dp[i][j];
    // }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Longest_Common_Substring_Tabulation(int n, int m, String str1, String str2) {
        int dp[][] = new int[n + 1][m + 1];

        // base case
        // i==0
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        // j==0
        for(int i=0;i<=m;i++) dp[0][i] = 0;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j <= m; j++) {
                // if matched
                if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    // 1 means 1 length string matched
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    // if not matched
                    dp[i][j] = 0;   // no previous value as it is broken link, again start if string matches
                }               
            }
        }

        int maxLen = Integer.MIN_VALUE;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                maxLen = Math.max(maxLen,dp[i][j]);
            }
        }
        return maxLen;
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static int Longest_Common_Substring_DPOptimized(int n, int m, String str1, String str2) {
        // we require only 2 arrays
        int prev[] = new int[m + 1];
        int maxLen = Integer.MIN_VALUE;

        // base case
        // j==0
        for(int i=0;i<=m;i++) prev[i] = 0;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            int curr[]=new int[m+1];
            for (int j = 1; j <= m; j++) {
                // if matched
                if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    // 1 means 1 length string matched
                    curr[j] = 1 + prev[j - 1];
                }else{
                    // if not matched
                    curr[j] = 0;
                }            
                maxLen = Math.max(maxLen,curr[j]);   
            }
            // update prev
            prev = curr;
        }

        // return prev[m];
        return maxLen;
    }
    public static int Longest_Common_Substring_DPOptimized_2(int n, int m, String str1, String str2) {
        // we require only 2 arrays
        int prev[] = new int[m + 1];
        int maxLen = Integer.MIN_VALUE;

        // base case
        // j==0
        for(int i=0;i<=m;i++) prev[i] = 0;

        // recurrence relation
        for (int i = 1; i <= n; i++) { // from index 1 as index 0 is done as base case
            for (int j = m; j >0 ; j--) {
                // if matched
                if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    // 1 means 1 length string matched
                    prev[j] = 1 + prev[j - 1];
                    maxLen = Math.max(maxLen, prev[j]);
                }else{
                    // if not matched
                    prev[j] = 0;
                }            
            }
        }

        // return prev[m];
        return maxLen;
    }


    public static void solve(FastReader sc) {
        String str1 = "", str2 = "";
        str1 = sc.nextLine();
        str2 = sc.nextLine();

        int n = str1.length();
        int m = str2.length();

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = Longest_Common_Substring_Recursion_1(n - 1, m - 1, str1, str2, 0);
        System.out.println("Brute force: " + ans);

        int dp[][] = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        
        // FIND MEMOIZATION SOLUTION IS CPP FOLDERS
        // ans = Longest_Common_Substring_Memoization_1(n - 1, m - 1, str1, str2, dp, 0);
        // System.out.println("DP Memoization:" + ans);
        // ans = Longest_Common_Substring_Memoization_Shifting_Index(n - 1, m - 1, str1, str2, dp,0);
        // System.out.println("DP Memoization Shifing index:" + ans);

        ans = Longest_Common_Substring_Recursion_Shifting_Index(n, m, str1, str2,0);
        System.out.println("Brute force Shifing index:" + ans);


        ans = Longest_Common_Substring_Tabulation(n,m,str1,str2);
        System.out.println("DP Tabulation:" + ans);
        
        ans = Longest_Common_Substring_DPOptimized(n,m,str1,str2);
        System.out.println("DP Optimized 1:" + ans);

        ans = Longest_Common_Substring_DPOptimized_2(n,m,str1,str2);
        System.out.println("DP Optimized 2:" + ans);
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
