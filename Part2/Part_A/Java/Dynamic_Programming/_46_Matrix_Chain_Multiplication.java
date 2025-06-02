package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _46_Matrix_Chain_Multiplication {
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
     * Matrix Chain Multiplication
     * 
     * Given a sequence of matrices, find the most efficient way to multiply these
     * matrices together. The efficient way is the one that involves the least
     * number of multiplications.
     * 
     * The dimensions of the matrices are given in an array arr[] of size N (such
     * that N = number of matrices + 1) where the ith matrix has the dimensions
     * (arr[i-1] x arr[i]).
     * 
     * Input: N = 5
     * arr = {40, 20, 30, 10, 30}
     * Output: 26000
     * Explanation: There are 4 matrices of dimension
     * 40x20, 20x30, 30x10, 10x30. Say the matrices are
     * named as A, B, C, D. Out of all possible combinations,
     * the most efficient way is (A*(B*C))*D.
     * The number of operations are -
     * 20*30*10 + 40*20*10 + 40*10*30 = 26000.
     */

    // Brute force
    public static int Matrix_Chain_Multiplication_Recursion(int i, int j, int arr[], int n) {
        // base case
        // if only one matrix remains -> smallest number of multiplication is 0
        if (i == j) {
            return 0;
        }

        int ans = (int) (1e9);
        // try all partitions (run loop)
        for (int k = i; k <= j - 1; k++) {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + Matrix_Chain_Multiplication_Recursion(i, k, arr, n)
                    + Matrix_Chain_Multiplication_Recursion(k + 1, j, arr, n);

            ans = Math.min(ans, steps);
        }

        // return best possible
        return ans;
    }

    // DP Memoization
    public static int Matrix_Chain_Multiplication_Memoization(int i, int j, int arr[], int n, int dp[][]) {
        // base case
        // if only one matrix remains -> smallest number of multiplication is 0
        if (i == j) {
            return 0;
        }

        // check if subproblems are solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = (int) (1e9);
        // try all partitions (run loop)
        for (int k = i; k <= j - 1; k++) {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + Matrix_Chain_Multiplication_Memoization(i, k, arr, n, dp)+ Matrix_Chain_Multiplication_Memoization(k + 1, j, arr, n, dp);

            ans = Math.min(ans, steps);
        }

        // return best possible
        dp[i][j] = ans;
        return ans;
    }

    // DP Tabulation
    public static int Matrix_Chain_Multiplication_Tabulation(int arr[], int n) {
        int dp[][] = new int[n][n];

        // base case
        // if i==j return 0
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        // recurrence relation
        // i => it was from 1 to n-1 in memoization in tabulation n-1 to 0
        // j => it was from n-1 till 1 in memoization in tabulation it is from i+1 to n
        // as (i is alwasys on left of i )
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int ans = (int) (1e9);
                for (int k = i; k <= j - 1; k++) {
                    int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    ans = Math.min(ans, steps);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 1];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    // just check the difference between strings

    // Better Striver
    public static int Matrix_Chain_Multiplication_DPOptimized_Striver(int[] arr, int n) {
        return 0;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int dp[][] = new int[n][n];
        for (int rows[] : dp) {
            Arrays.fill(rows, -1);
        }

        // Start with entire block
        // fun (1,4)=> return min no of multiplications to multilpy matrix (1 to 4)
        int ans = Matrix_Chain_Multiplication_Recursion(1, n - 1, arr, n);
        System.out.println("Brute Force:" + ans);

        ans = Matrix_Chain_Multiplication_Memoization(1, n - 1, arr, n, dp);
        System.out.println("DP DPOptimized Sriver:" + ans);

        ans = Matrix_Chain_Multiplication_Tabulation(arr, n);
        System.out.println("DP DPOptimized Sriver:" + ans);

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
