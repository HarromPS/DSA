package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _8_II_Total_Unique_Paths {
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

    // Only works for 1 obstacle in grid
    
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
    public static int TotalUniqueWaysRecursion_1(int row,int col,int rowBlock, int colBlock){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }

        // if encountered the blocked cell
        if(row==rowBlock && col==colBlock){
            return 0;
        }

        // if block is on top row or leftmost column return 0, i.e no way
        // if on first row or col means only one way is there
        if((row==0 && rowBlock>row) || (col==0 && colBlock>col)){
            return 1;
        }

        // can go up or left 
        int upperWays = TotalUniqueWaysRecursion_1(row-1,col,rowBlock,colBlock);
        int leftWays = TotalUniqueWaysRecursion_1(row,col-1,rowBlock,colBlock);  
        
        // total ways can be found from all ways from up or left
        return upperWays + leftWays;
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int TotalUniqueWaysMemoization(int row,int col,int rowBlock,int colBlock, int dp[][]){
        // base cases

        // if goes out of boundaries
        if(row<0 || col<0) {    
            return 0;
        }
    
        // if encountered the blocked cell
         if(row==rowBlock && col==colBlock){
            return 0;
        }

        // if block is on top row or leftmost column return 0, i.e no way
        // if on first row or col means only one way is there
        if((row==0 && rowBlock>row) || (col==0 && colBlock>col)){
            return 1;
        }

        // check if previously this cell was explored to find number of ways 
        if(dp[row][col]!=-1){   
            return dp[row][col];
        }   

        // can go up or left 
        int upperWays = TotalUniqueWaysMemoization(row-1,col,rowBlock,colBlock,dp);
        int leftWays = TotalUniqueWaysMemoization(row,col-1,rowBlock,colBlock,dp);  
        
        // total ways can be found from all ways from up or left
        // save number of ways from this cell 
        dp[row][col] = upperWays+leftWays;
        return dp[row][col];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int TotalUniqueWaysTabulation(int m,int n,int rowBlock,int colBlock){
        // Base case -> Recurrence Relation
        int dp[][] = new int[m+1][n+1];
        dp[0][0]=1;

        // now base case
        // when reached to 0,0 OR on 1st row or column, means a way, So

        // if blockage on top row OR leftmost columns
        int isOnTopRow=(rowBlock==0?1:0);
        int isOnLeftMost=(colBlock==0?1:0);

        for(int i=1;i<=m;i++){
            if(isOnLeftMost==1){
                if(i<rowBlock){
                    dp[i][0]=1;
                }else{
                    dp[i][0]=0;
                }
            }else{
                dp[i][0]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(isOnTopRow==1){
                if(i<colBlock){
                    dp[0][i]=1;
                }else{
                    dp[0][i]=0;
                }
            }else{
                dp[0][i]=1;
            }
                    
        }
        // starting from 1,1 cell and adding no of ways for each cell 
        for(int row=1;row<=m;row++){
            for(int col=1;col<=n;col++){
                int ways=0;
                if(row==rowBlock && col==colBlock){
                    ways=0;
                }else{
                    // upper + left way
                    ways = dp[row-1][col] + dp[row][col-1];                                        
                }
                // update number of ways each cell holds of all columns in a row
                dp[row][col] = ways;
            }
        }

        return dp[m-1][n-1];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int TotalUniqueWaysDPOptimized(int m ,int n,int rowBlock,int colBlock){

        // it needs a previous row and previous column values 
        int prevRow[] = new int[n+1];         
       
        // starting from 1,1 to m,n
        for(int row=0;row<m;row++){
            
            // temporary previous row
            int tempPrevRow[] = new int[n+1];
            for(int col=0;col<n;col++){
                if(row==rowBlock && col==colBlock){
                    tempPrevRow[col]=0;
                }else if(row==0 && col==0){
                    tempPrevRow[col]=1;
                }
                else{
                    int up=0,left=0;
                    if(row>0) up=prevRow[col];
                    if(col>0) left=tempPrevRow[col-1];
                    tempPrevRow[col] = up+left;
                }
            }

            // update previous row, if it is not last row
            for(int i=0;i<n;i++) {
                prevRow[i]=tempPrevRow[i];
            }
        }
        // return all ways
        return prevRow[n-1];        
    }
    
    public static void solve(FastReader sc) {
        int m=sc.nextInt();
        int n=sc.nextInt();

        /* 5 7 3 4 */

        int rowBlock=sc.nextInt();
        int colBlock=sc.nextInt();

        // if there is no blockage then 
        if(rowBlock==-1 && colBlock==-1){
            rowBlock=Integer.MAX_VALUE;
            colBlock=Integer.MAX_VALUE;
        }

        int ans=Integer.MIN_VALUE;
        ans = TotalUniqueWaysRecursion_1(m-1,n-1,rowBlock,colBlock);
        System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[m+1][n+1];
        for(int i=0;i<=m;i++) { 
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }

        ans = TotalUniqueWaysMemoization(m-1,n-1,rowBlock,colBlock,dp);
        System.out.println("DP Memoization:"+ans);
        
        ans = TotalUniqueWaysTabulation(m,n,rowBlock,colBlock);
        System.out.println("DP Tabulation:"+ans);
        
        ans = TotalUniqueWaysDPOptimized(m,n,rowBlock,colBlock);
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

