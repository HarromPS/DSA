package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _49_Boolean_Expression {
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
     * You are given an expression 'exp' in the form of a string where operands will
     * be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).
     *
     * Now you have to find the number of ways we can parenthesize the expression
     * such that it will evaluate to TRUE.
     * 
     * 
     * As the answer can be very large, return the output modulo 1000000007.
     * 
     * Note :
     * 
     * ‘T’ will represent the operand TRUE.
     * ‘F’ will represent the operand FALSE.
     * ‘|’ will represent the operator OR.
     * ‘&’ will represent the operator AND.
     * ‘^’ will represent the operator XOR.
     * 
     * Sample Input 1 :
     * 
     * T^T^F
     * 
     * Sample Output 1 :
     * 
     * 0
     * 
     * Explanation For Sample Input 1:
     * 
     * There are total 2 ways to parenthesize this expression:
     * (i) (T^T)^(F) = F
     * (ii) (T)^(T^F) = F
     * Both ways will result in False, so we will return 0.
     * 37658582
     * 
     * 
     */

    // Solving this problem independantly will not work
    // Brute force
    public static int mod = 1000000007;

    public static int Boolean_Exp_Recursion(int i, int j, int isTrue, String arr) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0; // coins gain 0
        }
        // if only either T or F
        if (i == j) {
            // if T needed from this partition & is actually true
            if (isTrue == 1 && arr.charAt(i) == 'T') {
                return 1; // one way
            }
            if (isTrue == 0 && arr.charAt(i) == 'F') {
                return 1;
            }
            return 0;
        }

        int ways = 0;
        // recurrence relation
        // from one operator to next with distance 2
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            // get number of ways we can as T or F from left and right partion
            int Left_True = Boolean_Exp_Recursion(i, ind - 1, 1, arr);
            int Right_True = Boolean_Exp_Recursion(ind + 1, j, 1, arr);
            int Left_False = Boolean_Exp_Recursion(i, ind - 1, 0, arr);
            int Right_False = Boolean_Exp_Recursion(ind + 1, j, 0, arr);

            char operator = arr.charAt(ind);
            // now operators
            if (operator == '&') {
                // if only true if needed from this partition, then
                if (isTrue == 1) {
                    ways = (ways + (Left_True * Right_True) % mod) % mod;
                } else {
                    // if only false needed
                    ways = (ways + ((Left_True * Right_False) + (Left_False * Right_True) + (Left_False * Right_False))
                            % mod) % mod;
                }
            }

            if (operator == '|') {
                if (isTrue == 1) {
                    ways = (ways
                            + ((Left_True * Right_True) + (Left_False * Right_True) + (Left_True * Right_False)) % mod)
                            % mod;
                } else {
                    // if only false needed
                    ways = (ways + (Left_False * Right_False) % mod) % mod;
                }
            }

            if (operator == '^') {
                if (isTrue == 1) {
                    ways = (ways + ((Left_True * Right_False) + (Left_False * Right_True)) % mod) % mod;
                } else {
                    // if only false needed
                    ways = (ways + ((Left_True * Right_True) + (Left_False * Right_False)) % mod) % mod;
                }
            }
        }

        return ways;
    }

    // DP Memoization
    public static int Boolean_Exp_Memoization(int i, int j, int isTrue, String arr, int dp[][][]) {
        // base case
        // if there are no partitions
        if (i > j) {
            return 0; // coins gain 0
        }
        // if only either T or F
        if (i == j) {
            // if T needed from this partition & is actually true
            if (isTrue == 1 && arr.charAt(i) == 'T') {
                return 1; // one way
            }
            if (isTrue == 0 && arr.charAt(i) == 'F') {
                return 1;
            }
            return 0;
        }

        // check if subproblems are already solved
        if (dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }

        int ways = 0;
        // recurrence relation
        // from one operator to next with distance 2
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            // get number of ways we can as T or F from left and right partion
            int Left_True = Boolean_Exp_Memoization(i, ind - 1, 1, arr, dp);
            int Right_True = Boolean_Exp_Memoization(ind + 1, j, 1, arr, dp);
            int Left_False = Boolean_Exp_Memoization(i, ind - 1, 0, arr, dp);
            int Right_False = Boolean_Exp_Memoization(ind + 1, j, 0, arr, dp);

            char operator = arr.charAt(ind);
            // now operators
            if (operator == '&') {
                // if only true if needed from this partition, then
                if (isTrue == 1) {
                    ways = (ways + (Left_True * Right_True) % mod) % mod;
                } else {
                    // if only false needed
                    ways = (ways + ((Left_True * Right_False) + (Left_False * Right_True) + (Left_False * Right_False))
                            % mod) % mod;
                }
            }

            if (operator == '|') {
                if (isTrue == 1) {
                    ways = (ways
                            + ((Left_True * Right_True) + (Left_False * Right_True) + (Left_True * Right_False)) % mod)
                            % mod;
                } else {
                    // if only false needed
                    ways = (ways + (Left_False * Right_False) % mod) % mod;
                }
            }

            if (operator == '^') {
                if (isTrue == 1) {
                    ways = (ways + ((Left_True * Right_False) + (Left_False * Right_True)) % mod) % mod;
                } else {
                    // if only false needed
                    ways = (ways + ((Left_True * Right_True) + (Left_False * Right_False)) % mod) % mod;
                }
            }
        }

        dp[i][j][isTrue] = ways;
        return dp[i][j][isTrue];
    }

    public static int Boolean_Exp_Tabulation_1(String arr) {
        // Write your code here.
        int n = arr.length();
        long dp[][][] = new long[n][n][2];

        // 1. base case
        // all base cases are covered in recurrence relation

        // 2.recurrence relation
        // in recursion i-> 0 to n-1, j-> n-1 to 0
        // in tabulation i-> n-1 to 0, j-> 0 to n-1
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    continue; // skip it
                } else if (i == j) {
                    if (arr.charAt(i) == 'T') {
                        dp[i][j][1] = 1;
                    } else if (arr.charAt(i) == 'F') {
                        dp[i][j][0] = 1;

                    }
                } else {
                    // recurrence relation
                    // from one operator to next with distance 2
                    for (int ind = i + 1; ind <= j - 1; ind += 2) {
                        // get number of ways we can as T or F from left and right partion
                        long Left_True = dp[i][ind - 1][1];
                        long Right_True = dp[ind + 1][j][1];
                        long Left_False = dp[i][ind - 1][0];
                        long Right_False = dp[ind + 1][j][0];

                        char operator = arr.charAt(ind);
                        // now operators
                        if (operator == '&') {
                            // if only true if needed from this partition, then
                            dp[i][j][1] = (dp[i][j][1] + (Left_True * Right_True) % mod) % mod;
                            dp[i][j][0] = (dp[i][j][0] + ((Left_True * Right_False) + (Left_False * Right_True) + (Left_False * Right_False)) % mod) % mod;
                        }

                        if (operator == '|') {
                            dp[i][j][1] = (dp[i][j][1] + ((Left_True * Right_True) + (Left_False * Right_True)+ (Left_True * Right_False)) % mod) % mod;
                            dp[i][j][0] = (dp[i][j][0] + (Left_False * Right_False) % mod) % mod;
                        }

                        if (operator == '^') {
                            dp[i][j][1] = (dp[i][j][1] + ((Left_True * Right_False) + (Left_False * Right_True)) % mod) % mod;
                            dp[i][j][0] = (dp[i][j][0] + ((Left_True * Right_True) + (Left_False * Right_False)) % mod) % mod;
                        }
                    }
                }
            }
        }
        return (int)dp[0][n - 1][1];
    }

    // DP Tabulation
    public static int Boolean_Exp_Tabulation(String arr) {
        int n = arr.length();
        long dp[][][] = new long[n][n][2];

        // 1. base case
        // all base cases are covered in recurrence relation

        // 2.recurrence relation
        // in recursion i-> 0 to n-1, j-> n-1 to 0
        // in tabulation i-> n-1 to 0, j-> 0 to n-1
        // Initializing the dp array
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= n - 1; j++) {
                if (i > j)
                    continue;
                for (int isTrue = 0; isTrue <= 1; isTrue++) {
                    // Base case 1:
                    if (i == j) {
                        if (isTrue == 1)
                            dp[i][j][isTrue] = arr.charAt(i) == 'T' ? 1 : 0;
                        else
                            dp[i][j][isTrue] = arr.charAt(i) == 'F' ? 1 : 0;
                        continue;
                    }

                    // Recurrence logic:
                    long ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind += 2) {
                        long lT = dp[i][ind - 1][1];
                        long lF = dp[i][ind - 1][0];
                        long rT = dp[ind + 1][j][1];
                        long rF = dp[ind + 1][j][0];

                        char operator = arr.charAt(ind);
                        if (operator == '&') {
                            if (isTrue == 1)
                                ways = (ways + (lT * rT) % mod) % mod;
                            else
                                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                        } else if (operator == '|') {
                            if (isTrue == 1)
                                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                            else
                                ways = (ways + (lF * rF) % mod) % mod;
                        } else {
                            if (isTrue == 1)
                                ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                            else
                                ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return (int) dp[0][n - 1][1];
    }

    // // DP Optimized
    // public static int Boolean_arr_Optimized(int coins[], int n) {
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
        String s = sc.nextLine();
        int n = s.length();

        int dp[][][] = new int[n + 1][n + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        // returns number of ways to evaluate expression to be TRUE i.e answer should be
        // true
        // int ans = Boolean_Exp_Recursion(0, n - 1, 1, s); // partition from 0 to n-1 for true i.e 1
        // System.out.println("Brute Force:" + ans);

        // ans = Boolean_Exp_Memoization(0, n - 1, 1, s, dp);
        // System.out.println("DP DPOptimized Sriver:" + ans);

        int ans = Boolean_Exp_Tabulation_1(s);
        System.out.println("DP Tabulation Sriver_1:" + ans);

        ans = Boolean_Exp_Tabulation(s);
        System.out.println("DP Tabulation Sriver:" + ans);

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
