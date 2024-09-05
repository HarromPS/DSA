package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _12_Chocolate_Pickups {
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
     * Problem statement
     * 
     * - You are given an n rows and m cols matrix grid representing a field of
     * chocolates where grid[i][j]
     * represents the number of chocolates that you can collect from the (i, j)
     * cell.
     * 
     * - You have two robots that can collect chocolates for you:
     * 
     * - Robot #1 is located at the top-left corner (0, 0), and
     * - Robot #2 is located at the top-right corner (0, cols - 1).
     * 
     * - Return the maximum number of chocolates collection using both robots by
     * following the rules below:
     * 
     * - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or
     * (i + 1, j + 1).
     * - When any robot passes through a cell, It picks up all chocolates, and the
     * cell becomes an empty cell.
     * - When both robots stay in the same cell, only one takes the chocolates.
     * - Both robots cannot move outside of the grid at any moment.
     * - Both robots should reach the bottom row in grid.
     * 
     * 
     */

    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1), try all elements of last row
    public static int chocolatePickupsRecursion_1(int row, int colA, int colB, int arr[][], int m, int n) {
        // base cases
        // if out of boundary
        if (colA < 0 || colB < 0 || colA >= n || colB >= n) {
            return (int) (-1e8); // return a min value, as we want result to be maximized
        }
        // if reached to last row
        if (row == (m - 1)) {
            // if both are on same cell
            if (colA == colB) {
                return arr[row][colA]; // return value only once
            } else {
                // both are on difference cell
                return arr[row][colA] + arr[row][colB];
            }
        }

        // now exploring all ways->
        // column change => [-1, 0, +1]
        // there will be 9 combinations
        // -1 (-1,0,+1)
        // 0 (-1,0,+1)
        // +1 (-1,0,+1)

        int maxChocolates = (int) -1e8;
        for (int dj1 = -1; dj1 <= +1; dj1++) {
            int value = 0;
            for (int dj2 = -1; dj2 <= +1; dj2++) {
                // if they are going to same cell
                if (dj1 == dj2) {
                    // give chocolates to only one
                    value = arr[row][colA];
                } else {
                    // if they are on different cells, add those cell individually
                    value = arr[row][colA] + arr[row][colB];
                }
                value += chocolatePickupsRecursion_1(row + 1, colA + dj1, colB + dj2, arr, m, n);
                maxChocolates = Math.max(value, maxChocolates);
            }
        }

        // return max chocolates by both
        return maxChocolates;
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int chocolatePickupsMemoization(int row, int colA, int colB, int arr[][], int m, int n,
            int dp[][][]) {
        // base cases
        // if out of boundary
        if (colA < 0 || colB < 0 || colA >= n || colB >= n) {
            return (int) (-1e8); // return a min value, as we want result to be maximized
        }
        // if reached to last row
        if (row == (m - 1)) {
            // if both are on same cell
            if (colA == colB) {
                return arr[row][colA]; // return value only once
            } else {
                // both are on difference cell
                return arr[row][colA] + arr[row][colB];
            }
        }

        // if the subproblem is already solved or not
        if (dp[row][colA][colB] != -1)
            return dp[row][colA][colB];

        // now exploring all ways->
        // column change => [-1, 0, +1]
        // there will be 9 combinations
        // -1 (-1,0,+1)
        // 0 (-1,0,+1)
        // +1 (-1,0,+1)

        int maxChocolates = (int) -1e8;
        for (int dj1 = -1; dj1 <= +1; dj1++) {
            int value = 0;
            for (int dj2 = -1; dj2 <= +1; dj2++) {
                // if they are going to same cell
                if (dj1 == dj2) {
                    // give chocolates to only one
                    value = arr[row][colA];
                } else {
                    // if they are on different cells, add those cell individually
                    value = arr[row][colA] + arr[row][colB];
                }
                value += chocolatePickupsMemoization(row + 1, colA + dj1, colB + dj2, arr, m, n, dp);
                maxChocolates = Math.max(value, maxChocolates);
            }
        }

        // save calculated value
        dp[row][colA][colB] = maxChocolates;

        // return max chocolates by both
        return maxChocolates;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n)
    public static int chocolatePickupsTabulation(int arr[][], int m, int n) {
        int dp[][][] = new int[m][n][n];

        // base case: when i==n-1 multiple combos of colA & colB
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                // if both are on same cell
                if (j1 == j2) {
                    dp[m - 1][j1][j2] = arr[m - 1][j1]; // only one cell collected
                } else {
                    dp[m - 1][j1][j2] = arr[m - 1][j1] + arr[m - 1][j2]; // both two cell collected
                }
            }
        }

        // Recurrence relation: from m-2 till 0 with all column combinations of colA and
        // colB
        for (int i = m - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    // put the memoization recurrence as it is
                    int maxChocolates = Integer.MIN_VALUE;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            // if they are going to same cell
                            if (j1 == j2) {
                                // give chocolates to only one
                                value = arr[i][j1];
                            } else {
                                // if they are on different cells, add those cell individually
                                value = arr[i][j1] + arr[i][j2];
                            }

                            // base case
                            if ((j1 + dj1) >= 0 && (j1 + dj1) < n && (j2 + dj2) >= 0 && (j2 + dj2) < n) {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            } else {
                                value += (int) Math.pow(-10, 9);
                            }
                            maxChocolates = Math.max(value, maxChocolates);
                        }
                    }

                    // save calculated value
                    dp[i][j1][j2] = maxChocolates;
                }
            }
        }
        return dp[0][0][n - 1];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int chocolatePickupsDPOptimized(int arr[][], int m, int n) {
        // we need only two rows to follow
        // i.e prev row to get previous values
        // and current row to save current working row values

        int prevRow[][] = new int[n][n];
        int currRow[][] = new int[n][n];

        // base case: when i==n-1 multiple combos of colA & colB
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                // if both are on same cell
                if (j1 == j2) {
                    prevRow[j1][j2] = arr[m - 1][j1]; // only one cell collected
                } else {
                    prevRow[j1][j2] = arr[m - 1][j1] + arr[m - 1][j2]; // both two cell collected
                }
            }
        }

        // Recurrence relation: from m-2 till 0 with all column combinations of colA and
        // colB
        for (int i = m - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    // current row space to save current row values

                    // put the memoization recurrence as it is
                    int maxChocolates = Integer.MIN_VALUE;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            // if they are going to same cell
                            if (j1 == j2) {
                                // give chocolates to only one
                                value = arr[i][j1];
                            } else {
                                // if they are on different cells, add those cell individually
                                value = arr[i][j1] + arr[i][j2];
                            }

                            // base case
                            if ((j1 + dj1) >= 0 && (j1 + dj1) < n && (j2 + dj2) >= 0 && (j2 + dj2) < n) {
                                value += prevRow[j1 + dj1][j2 + dj2];
                            } else {
                                value +=(int) Math.pow(-10, 9);
                            }
                            maxChocolates = Math.max(value, maxChocolates);
                        }
                    }

                    // save calculated value
                    currRow[j1][j2] = maxChocolates;
                }
            }
            for(int x = 0;x<n;x++){
                for(int y=0;y<n;y++){
                    prevRow[x][y]=currRow[x][y];
                    currRow[x][y]=0;
                }
            }
        }
        return prevRow[0][n-1];
    }

    public static void solve(FastReader sc) {
        int m = sc.nextInt();
        int n = sc.nextInt();

        int arr[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r = sc.nextInt();
                arr[i][j] = r;
            }
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = 0;
        ans = chocolatePickupsRecursion_1(0, 0, n - 1, arr, m, n);
        System.out.println("Brute force: " + ans);

        // there are 3 variables (row, colA, colB) => [M][N][N] : max goes to M ,N
        int dp[][][] = new int[m][n][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        // ans=chocolatePickupsMemoization(0,0,n-1,arr,m,n,dp);
        // System.out.println("DP Memoization:"+ans);

        ans = chocolatePickupsTabulation(arr, m, n);
        System.out.println("DP Tabulation:" + ans);

        ans = chocolatePickupsDPOptimized(arr,m,n);
        System.out.println("DP Optimized:"+ans);
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
