package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _11_Min_Falling_Path_Sum {
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
    Problem statement

    - Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

    - A falling path starts at any element in the first row and chooses the element in the next row 
    that is either directly below or diagonally left/right. 
    - Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.

    1 -> 4 -> 8

    */

    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1), try all elements of last row
    public static int minFallingPathRecursion_1(int arr[][],int i,int j,int m,int n){
        // base cases
        // if out of boundary
        if (i < 0 || j<0 || j>=n) {
            return Integer.MAX_VALUE;
        }
        
        // base case: if we are at the first row, return the element at the current position
        if (i == 0 && j>=0 && j<n) {
            return arr[i][j];
        }

        int prevLeft = Integer.MAX_VALUE;
        int prev = Integer.MAX_VALUE;
        int prevRight = Integer.MAX_VALUE;

        // get the minimum path sum from the prev left diagonal, prev, prev right diagonal
        if(j-1 >= 0) prevLeft = minFallingPathRecursion_1(arr, i-1, j-1,m,n);    // look left from top of matrix
        if(j+1 < n) prevRight = minFallingPathRecursion_1(arr, i-1, j+1,m,n);    // look right from top of matrix
        prev = minFallingPathRecursion_1(arr, i-1, j,m,n);    // look on j th index from top of matrix

        int minVal = Math.min(prevLeft,Math.min(prev, prevRight));

        // return the current element plus the minimum path sum from the three possible paths
        return arr[i][j] + minVal;
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int minFallingPathMemoization(int arr[][],int i,int j,int m,int n,int dp[][]){
        // base cases
        // if out of boundary
        if (i < 0 || j<0 || j>=n) {
            return Integer.MAX_VALUE;
        }
        
        // base case: if we are at the first row, return the element at the current position
        if (i == 0 && j>=0 && j<n) {
            return arr[i][j];
        }

        // check if the value is already calculated or not
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int prevLeft = Integer.MAX_VALUE;
        int prev = Integer.MAX_VALUE;
        int prevRight = Integer.MAX_VALUE;

        // get the minimum path sum from the prev left diagonal, prev, prev right diagonal
        if(j-1 >= 0) prevLeft = minFallingPathMemoization(arr, i-1, j-1,m,n,dp);    // look left from top of matrix
        if(j+1 < n) prevRight = minFallingPathMemoization(arr, i-1, j+1,m,n,dp);    // look right from top of matrix
        prev = minFallingPathMemoization(arr, i-1, j,m,n,dp);    // look on j th index from top of matrix

        int minVal = Math.min(prevLeft,Math.min(prev, prevRight));

        // save calculated value
        dp[i][j] = arr[i][j] + minVal;
        // return the current element plus the minimum path sum from the three possible paths
        return dp[i][j];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int minFallingPathTabulation(int arr[][],int m,int n){
        // Base case
        // 1st row will be fixed as we can choose any of the element from 1st row
        int dp[][] = new int[m][n];

        // 1st row as it is
        for(int i=0;i<n;i++) dp[0][i]=arr[0][i];

        // start from next row
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                // apply recurrence relation
                int prevLeft = Integer.MAX_VALUE;
                int prevStraight = Integer.MAX_VALUE;
                int prevRight = Integer.MAX_VALUE;

                // conditions 
                if(j+1 < n){     // right diagonal
                    prevRight = dp[i-1][j+1];
                }
                if(j-1 >= 0){     // left diagonal
                    prevLeft = dp[i-1][j-1];
                }
                // straight
                prevStraight = dp[i-1][j];

                int minVal = arr[i][j] + Math.min(Math.min(prevLeft,prevRight),prevStraight);

                // update the value in dp
                dp[i][j] = minVal;
            }
        }

        int ans=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            ans = Math.min(ans, dp[m-1][i]);
        }
        return ans;
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int minFallingPathDPOptimized(int arr[][],int m,int n){
        // we need only two rows to follow 
        // i.e prev row to get previous values
        // and current row to save current working row values

        int prevRow[] = new int[n];

        // saving 1st row
        for(int i=0;i<n;i++) prevRow[i]=arr[0][i];

        // starting from next row
        for(int i=1;i<m;i++){
            // current row to save current row values
            int currRow[] = new int[n];
            for(int j=0;j<n;j++){
                // apply recurrence relation
                int prevLeft = Integer.MAX_VALUE;
                int prevStraight = Integer.MAX_VALUE;
                int prevRight = Integer.MAX_VALUE;

                // conditions 
                if(j+1 < n){     // right diagonal
                    prevRight = prevRow[j+1];
                }
                if(j-1 >= 0){     // left diagonal
                    prevLeft = prevRow[j-1];
                }
                // straight
                prevStraight = prevRow[j];

                currRow[j] = arr[i][j] + Math.min(Math.min(prevLeft,prevRight),prevStraight);
            }

            // update previous row
            for(int j=0;j<n;j++){
                prevRow[j]=currRow[j];
            }
        }
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            ans=Math.min(ans,prevRow[i]);
        }
        return ans;
    }
    
    public static void solve(FastReader sc) {
        int m=sc.nextInt();
        int n=sc.nextInt();

        /* 5 7 3 4 */

        int arr[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r=sc.nextInt();
                arr[i][j]=r;
            }
        }

        // try all ways
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans=Math.min(ans,minFallingPathRecursion_1(arr,m-1,i,m,n));
        }
        System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[m][n];
        for(int i=0;i<m;i++) { 
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }

        for(int i=n-1;i>=0;i--){
            ans=Math.min(ans,minFallingPathMemoization(arr,m-1,i,m,n,dp));
        }
        // System.out.println("DP Memoization:"+ans);
        
        // ans = minFallingPathTabulation(arr,m,n);
        // System.out.println("DP Tabulation:"+ans);
        
        // ans = minFallingPathDPOptimized(arr,m,n);
        // System.out.println("DP Optimized:"+ans);
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
        //     solve(sc);
        // }
        solve(sc);
    }
}

