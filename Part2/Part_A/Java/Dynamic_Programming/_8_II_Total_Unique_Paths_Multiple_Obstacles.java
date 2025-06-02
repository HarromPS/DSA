package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _8_II_Total_Unique_Paths_Multiple_Obstacles {
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

    // Only works for Multiple obstacle in grid
    
    /*  
     Problem statement

    -You are given an m x n integer array grid. 
    - There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
    - The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

    - An obstacle and space are marked as 1 or 0 respectively in grid.
    - A path that the robot takes cannot include any square that is an obstacle.
 
    - Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

        Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
        Output: 2
        Explanation: There is one obstacle in the middle of the 3x3 grid above.
        There are two ways to reach the bottom-right corner:
        1. Right -> Right -> Down -> Down
        2. Down -> Down -> Right -> Right

    */

    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1)
    public static int TotalUniqueWaysRecursion_1(int row,int col,int arr[][]){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }

        // if encountered the blocked cell
        if(row>=0 && col>=0 && arr[row][col]==1){
            return 0;
        }

        if(row==0 && col==0){
            return 1;
        }

        // can go up or left 
        int upperWays = TotalUniqueWaysRecursion_1(row-1,col,arr);
        int leftWays = TotalUniqueWaysRecursion_1(row,col-1,arr);  
        
        // total ways can be found from all ways from up or left
        return upperWays + leftWays;
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int TotalUniqueWaysMemoization(int row,int col,int arr[][], int dp[][]){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }

        // if encountered the blocked cell
        if(row>=0 && col>=0 && arr[row][col]==1){
            return 0;
        }

        if(row==0 && col==0){
            return 1;
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        // can go up or left 
        int upperWays = TotalUniqueWaysMemoization(row-1,col,arr,dp);
        int leftWays = TotalUniqueWaysMemoization(row,col-1,arr,dp);  
        
        // total ways can be found from all ways from up or left

        dp[row][col]=upperWays+leftWays;

        return dp[row][col];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int TotalUniqueWaysTabulation(int m,int n,int arr[][]){
        // Base case -> Recurrence Relation
        int dp[][] = new int[m][n];
    
        // starting from 1,1 cell and adding no of ways for each cell 
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(arr[row][col]==1) dp[row][col]=0;
                else if(row==0 && col==0) dp[row][col]=1;
                else{
                    int up=0,left=0;
                    if(row>0) up = dp[row-1][col];
                    if(col>0) left = dp[row][col-1];
                    dp[row][col]=up+left;
                }
            }
        }

        return dp[m-1][n-1];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int TotalUniqueWaysDPOptimized(int m ,int n,int arr[][]){

        // it needs a previous row and previous column values 
        int prevRow[] = new int[n+1];         
       
        // starting from 1,1 to m,n
        for(int row=0;row<m;row++){
            
            // temporary previous row
            int currRow[] = new int[n+1];
            for(int col=0;col<n;col++){
                if(arr[row][col]==1){ 
                    currRow[col]=0;
                }else if(row==0 && col==0){
                    currRow[col]=1;
                }
                else{
                    int up=0,left=0;
                    if(row>0) up=prevRow[col];
                    if(col>0) left=currRow[col-1];
                    currRow[col] = up+left;
                }
            }

            // update previous row, if it is not last row
            for(int i=0;i<n;i++) {
                prevRow[i]=currRow[i];
            }
        }
        // return all ways
        return prevRow[n-1];        
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

        int ans=Integer.MIN_VALUE;
        ans = TotalUniqueWaysRecursion_1(m-1,n-1,arr);
        System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[m+1][n+1];
        for(int i=0;i<=m;i++) { 
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }

        ans = TotalUniqueWaysMemoization(m-1,n-1,arr,dp);
        System.out.println("DP Memoization:"+ans);
        
        ans = TotalUniqueWaysTabulation(m,n,arr);
        System.out.println("DP Tabulation:"+ans);
        
        ans = TotalUniqueWaysDPOptimized(m,n,arr);
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

