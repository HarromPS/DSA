package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _62_Largest_Connected_group {
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
    Problem statement: Maximum Connected group
    
    You are given a square binary grid. 
    A grid is considered binary if every value in the grid is either 1 or 0. 
    You can change at most one cell in the grid from 0 to 1. 
    You need to find the largest group of connected  1's. 
    Two cells are said to be connected 
    if both are adjacent(top, bottom, left, right) to each other and both have the same value.
     
    */

    /*
    SOLUTION:

    find all the possible groups  
    
     */

    // Brute force: TLE T.C: O(4^n x m) S.C: >> (n+m)
    public static int Longest_Connected_Groups_Recursion_Striver(int i, int j, int mat[][],int n,int m) {
        // base case 
        if(i<0 || j<0 || i>=n || j>=m) {
            return 0;
        }

        // if the cell is already visited
        if(visited[i][j]==1){
            return 0;
        }

        // if cell is changed
        if(mat[i][j]==0){
            if(mark[0][0]!=-1 && mark[0][1]!=-1){
                return 0;
            }else{
                mark[0][0]=i;
                mark[0][1]=j;
            }
            mat[i][j]=1;
        }

        visited[i][j]=1;

        // explore all directions
        // up
        int up = Longest_Connected_Groups_Recursion_Striver(i-1, j, mat, n, m);
        int left = Longest_Connected_Groups_Recursion_Striver(i, j-1, mat, n, m);
        int right = Longest_Connected_Groups_Recursion_Striver(i, j+1, mat, n, m);
        int down = Longest_Connected_Groups_Recursion_Striver(i+1, j, mat, n, m);

        // when all directions are explored
        // check if this cell was changed from 0 -> 1
        int flag=0;
        if(mark[0][0]==i && mark[0][1]==j){
            mark[0][0]=-1;
            mark[0][1]=-1;

            flag=1;
            mat[i][j]=0;    // it could have been changed
        }

        // if current cell is 1 means it is a part of connected cell 
        int ans = up+left+down+right;
        if(flag==1 || mat[i][j]==1) {
            ans+=1;
        }
       return ans;
     
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)

    // we say -1 0 1 2 .. n-1
    // n = n-1, so 2 = 1, 1 = 2 ..., 1=0
    // so i changes i-1 and j changes to j-1
    public static int Longest_Connected_Groups_Memoization_Shifting_Index_Striver(int i, int j,
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
            int res = 1 + Longest_Connected_Groups_Memoization_Shifting_Index_Striver(i - 1,
                    j - 1, str1, str2, dp);
            dp[i][j] = res;
            return dp[i][j];
        }

        // if characters are not matched
        // check by moving 1 index left on both strings
        int move_i = 0 + Longest_Connected_Groups_Memoization_Shifting_Index_Striver(i - 1, j,
                str1, str2, dp);

        int move_j = 0 + Longest_Connected_Groups_Memoization_Shifting_Index_Striver(i, j - 1,
                str1, str2, dp);

        dp[i][j] = Math.max(move_i, move_j);
        return dp[i][j];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int Longest_Connected_Groups_Tabulation(int n, int m, String str1, String str2) {

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
    public static int Longest_Connected_Groups_DPOptimized(int n, int m, String str1,
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

    public static int visited[][];
    public static int mark[][];
    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();

        int mat[][]=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=sc.nextInt();
            }
        }

        visited = new int[n][m];
        mark = new int[1][2];

        // stores the index of changed cell
        mark[0][0]=-1;
        mark[0][1]=-1;
        
        int ans = Longest_Connected_Groups_Recursion_Striver(n-1,m-1,mat,n,m);
        System.out.println("Brute force Striver:" + ans);
        
        int dp[][] = new int[n + 1][m + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        // ans = Longest_Connected_Groups_Memoization_Shifting_Index_Striver(n, m, str1, str2,dp);
        // System.out.println("DP Memoization Shifing index:" + ans);

        // // CHECK OPTIMIZED : TRICK
        // ans = Longest_Connected_Groups_Tabulation(n, m, str1, str2);
        // System.out.println("DP Tabulation:" + ans);

        // ans = Longest_Connected_Groups_DPOptimized(n, m, str1, str2);
        // System.out.println("DP Optimized 1:" + ans);

        // ans = Longest_Connected_Groups_DPOptimized_2(targetN, price, n);
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
