package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _61_Largest_Square_formed {
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
     * Given a binary matrix mat of size n * m,
     * find out the maximum length of a side of a square sub-matrix with all 1s.
     * 
     * Input: n = 6, m = 5
     * mat = [[0, 1, 1, 0, 1],
            * [1, 1, 0, 1, 0],
            * [0, 1, 1, 1, 0],
            * [1, 1, 1, 1, 0],
            * [1, 1, 1, 1, 1],
            * [0, 0, 0, 0, 0]]
     * Output: 3
     * Explanation:
     * 
     * The maximum length of a side of the square sub-matrix is 3 where every
     * element is 1.
     * 
     * Input: n = 2, m = 2
     * mat = [[1, 1],
     * [1, 1]]
     * Output: 2
     * Explanation: The maximum length of a side of the square sub-matrix is 2. The
     * matrix itself is the maximum sized sub-matrix in this case.
     * 
     * Input: n = 2, m = 2
     * mat = [[0, 0],
     * [0, 0]]
     * Output: 0
     * Explanation: There is no 1 in the matrix.
     */

    /*
     * SOLUTION:
     * if current val is 1 means it maybe a part of square
     * so check its square parts from right, down and diagonal and find max length
     * in between
     */

    // Brute force: TLE T.C: O(3^ n x m) S.C: (n+m)
    // f(i,j): lcs of str1 from 0 to i && str2 from 0 to j
    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Largest_Square_Length_Recursion(int i, int j, int mat[][]) {
        // base case change
        // if any index goes out of boundary
        if (i < 0 || j < 0)
            return 0;

        if (i == 0 && j == 0) {
            if (mat[i][j] == 1) {
                return 1;
            } else {
                return 0;
            }
        }

        // check all 3 ways
        int left = Largest_Square_Length_Recursion(i, j - 1, mat);
        int diagonal = Largest_Square_Length_Recursion(i - 1, j - 1, mat);
        int up = Largest_Square_Length_Recursion(i - 1, j, mat);

        // if current is 1 then is will be considered as a part of largest square
        if (mat[i][j] == 1) {
            int ans = 1 + Math.min(left, Math.min(diagonal, up));

            // grab the max len os square in recursive call
            maxLen = Math.max(maxLen, ans);
            return ans;
        }

        return 0;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Largest_Square_Length_Memoization(int i, int j, int mat[][], int dp[][]) {
        // base case change
        // if any index goes out of boundary
        if (i < 0 || j < 0)
            return 0;

        if (i == 0 && j == 0) {
            if (mat[i][j] == 1) {
                return 1;
            } else {
                return 0;
            }
        }

        // check is subproblems are previously solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // check all 3 ways
        int left = Largest_Square_Length_Memoization(i, j - 1, mat,dp);
        int diagonal = Largest_Square_Length_Memoization(i - 1, j - 1, mat,dp);
        int up = Largest_Square_Length_Memoization(i - 1, j, mat,dp);

        // if current is 1 then is will be considered as a part of largest square
        if (mat[i][j] == 1) {
            int ans = 1 + Math.min(left, Math.min(diagonal, up));

            // save dp
            dp[i][j] = ans;

            // grab the max len os square in recursive call
            maxLen = Math.max(maxLen, ans);

            return ans;
        }

        return 0;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Largest_Square_Length_Tabulation(int n, int m, int mat[][]) {

        // base case
        int dp[][] = new int[n][m];

        // base case
        // i==0 && j==0
        int maxLength = 0;

        // when any of i or j is 0, means only 1 length of square is there
        for (int i = 0; i < n; i++){
            if (mat[i][0] == 1){
                dp[i][0] = 1;
                maxLength = 1;  // At least one 1 found
            }
        }

        for (int i = 0; i < m; i++){
            if (mat[0][i] == 1){
                dp[0][i] = 1;
                maxLength = 1;  // At least one 1 found
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) { // from index 1 as index 0 is done as base case
            for (int j = 1; j < m; j++) {
                 // check all 3 ways
                int left = dp[i][j - 1];
                int diagonal = dp[i - 1][j - 1];
                int up = dp[i - 1][j];

                // if current is 1 then is will be considered as a part of largest square
                if (mat[i][j] == 1) {
                    // save dp
                    dp[i][j] = 1 + Math.min(left, Math.min(diagonal, up));

                    // grab the max len os square in recursive call
                    maxLength = Math.max(maxLength, dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }

        return maxLength;
    }

    // DP optimized
    // T.C: O(n x m), S.C:O(m)
    public static int Largest_Square_Length_DPOptimized(int n, int m, int mat[][]) {
       
        // base case
        int prev[] = new int[m];

        // base case
        // i==0 && j==0
        int maxLength = 0;

        // when any of i or j is 0, means only 1 length of square is there
        for (int i = 0; i < m; i++){
            if (mat[0][i] == 1){
                prev[i] = 1;
                maxLength = 1;  // At least one 1 found
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) { // from index 1 as index 0 is done as base case

            int curr[]=new int[m];
            for (int j = 0; j < m; j++) {
                // check all 3 ways
                int left = Integer.MAX_VALUE,diagonal=Integer.MAX_VALUE, up = Integer.MAX_VALUE;

                if(j-1>=0){
                    left = curr[j - 1];
                    diagonal = prev[j - 1];
                }
                up = prev[j];

                // if current is 1 then is will be considered as a part of largest square
                if (mat[i][j] == 1) {
                    if(j==0){
                        curr[j]=1;
                    }else{
                        // save dp
                        curr[j] = 1 + Math.min(left, Math.min(diagonal, up));
                    }

                    // grab the max len os square in recursive call
                    maxLength = Math.max(maxLength, curr[j]);
                }else{
                    curr[j]=0;
                }
            }

            // update prev
            prev=curr;
        }

        return maxLength;
    }

    static public int maxLen = 0;

    public static void solve(FastReader sc) {

        int n = sc.nextInt();
        int m = sc.nextInt();

        int mat[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        int dp[][] = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        maxLen = 0;
        Largest_Square_Length_Recursion(n - 1, m - 1, mat);
        System.out.println("Brute force Striver:" + maxLen);

        maxLen = 0;
        Largest_Square_Length_Memoization(n-1, m-1, mat, dp);
        System.out.println("DP Memoization Shifing index:" + maxLen);

        int ans = Largest_Square_Length_Tabulation(n, m, mat);
        System.out.println("DP Tabulation:" + ans);

        ans = Largest_Square_Length_DPOptimized(n, m, mat);
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
