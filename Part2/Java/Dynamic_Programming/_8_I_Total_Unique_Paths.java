package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _8_I_Total_Unique_Paths {
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

    - You are present at point ‘A’ which is the top-left cell of an M X N matrix.
    - Your destination is point ‘B’, which is the bottom-right cell of the same matrix. 
    - Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
    - In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, 
    - Your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].

    - To traverse in the matrix, you can either move Right or Down at each step. 
    - For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

    e.g: m = 3, n = 2
        Path 1 = (0, 0) -> (0, 1) -> (1, 1) -> (2, 1)
        Path 2 = (0, 0) -> (1, 0) -> (2, 0) -> (2, 1)
        Path 3 =  (0, 0) -> (1, 0) -> (1, 1) -> (2, 1)

        Hence a total of 3 paths are available, so the output is 3.
    */

    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1)
    public static int TotalUniqueWaysRecursion_1(int row,int col){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }

        // if on first row or col means only one way is there
        if(row==0 || col==0){
            return 1;
        }

        // can go up or left 
        int upperWays = TotalUniqueWaysRecursion_1(row-1,col);
        int leftWays = TotalUniqueWaysRecursion_1(row,col-1);  
        
        // total ways can be found from all ways from up or left
        return upperWays + leftWays;
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1 + n-1)
    public static int TotalUniqueWaysMemoization(int row,int col, int dp[][]){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }

        // if on first row or col means only one way is there
        if(row==0 || col==0){
            return 1;
        }

        // check if previously this cell was explored to find number of ways 
        if(dp[row][col]!=-1){   
            return dp[row][col];
        }   

        // can go up or left 
        int upperWays = TotalUniqueWaysMemoization(row-1,col,dp);
        int leftWays = TotalUniqueWaysMemoization(row,col-1,dp);  
        
        // total ways can be found from all ways from up or left
        // save number of ways from this cell 
        dp[row][col] = upperWays+leftWays;
        return dp[row][col];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int TotalUniqueWaysTabulation(int m,int n){
        // Base case -> Recurrence Relation
        int dp[][] = new int[m+1][n+1];

        // now base case
        // when reached to 0,0 OR on 1st row or column, means a way, So
        for(int i=0;i<=m;i++) dp[i][0]=1;      // whole 1st column
        for(int i=0;i<=n;i++) dp[0][i]=1;      // whole 1st row

        // starting from 1,1 cell and adding no of ways for each cell 
        for(int row=1;row<=m;row++){
            for(int col=1;col<=n;col++){
                // upper + left way
                int ways = dp[row-1][col] + dp[row][col-1];

                // update number of ways each cell holds of all columns in a row
                dp[row][col] = ways;
            }
        }

        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         System.out.print(dp[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        return dp[m-1][n-1];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int TotalUniqueWaysDPOptimized(int m ,int n){

        // it needs a previous row and previous column values 
        int prevRow[] = new int[n+1];    // row contains n+1 column cells
        int prevCol=1;                  // this will hold the value of prev column of current cell 

        for(int i=0;i<n+1;i++) prevRow[i]=1;    // previously for 0th row there is 1 way

        // starting from 1,1 to m,n
        for(int row=1;row<=m;row++){

            // temporary previous row
            int tempPrevRow[] = new int[n+1];
            
            // always prev column's cell contains 1, dp[i][0]=1;
            prevCol=1;

            for(int col=1;col<=n;col++){

                // find number of ways from previous row and col values 
                // previous row's same col cell + prev column's but same rows cell
                int ways = prevRow[col] + prevCol;

                // update previous rows cell & previous column row cell
                tempPrevRow[col] = ways;
                prevCol = ways;
            }

            // update previous row, if it is not last row
            if(row!=m){
                for(int i=1;i<n+1;i++) {
                    prevRow[i]=tempPrevRow[i];
                }
            }
        }
        // return all ways
        return prevRow[n-1];        
    }
    
    // T.C: O(m-1), S.C: O(1)
    static public int moreOptimized(int m,int n){

        int N = (m+n-2);
        int r = m-1;
        double res = 1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;        
        }
        return (int)res;
    }

    public static void solve(FastReader sc) {
        int m=sc.nextInt();
        int n=sc.nextInt();

        int ans=Integer.MIN_VALUE;
        // ans = TotalUniqueWaysRecursion_1(m-1,n-1);
        // System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[m+1][n+1];
        for(int i=0;i<=m;i++) { 
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }

        // ans = TotalUniqueWaysMemoization(m-1,n-1,dp);
        // System.out.println("DP Memoization:"+ans);
        
        // ans = TotalUniqueWaysTabulation(m,n);
        // System.out.println("DP Tabulation:"+ans);
        
        ans = TotalUniqueWaysDPOptimized(m,n);
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
        //     solve(sc);
        // }
        solve(sc);
    }
}

