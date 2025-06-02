package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _9_Min_Path_Sum {
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

    - Given a m x n grid filled with non-negative numbers, 
    - find a path from top left to bottom right, 
    - which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
    */


    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1)
    public static int minPathSumRecursion_1(int row,int col,int arr[][]){
        // base cases
        // if goes out of boundaries
        if(row<0 || col<0) {    
            // return 0;   // dont return 0 as min(0,some value) will return 0 
            return Integer.MAX_VALUE;
        }

        if(row==0 && col==0){
            return arr[0][0];
        }

        // can go up or left, return the minimum of the total cost from up & left
        int costFromUp = minPathSumRecursion_1(row-1,col,arr);
        int costFromLeft = minPathSumRecursion_1(row,col-1,arr);  
        
        // total ways can be found from all ways from up or left
        return (Math.min(costFromUp, costFromLeft)+arr[row][col]);
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int minPathSumMemoization(int row,int col,int arr[][], int dp[][]){
       // base cases
        // if goes out of boundaries
        if(row<0 || col<0) {    
            // return 0;   // dont return 0 as min(0,some value) will return 0 
            return Integer.MAX_VALUE;
        }

        if(row==0 && col==0){
            return arr[0][0];
        }

        // check if min path sum calculated previously in recursion
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        // can go up or left
        int costFromUp = minPathSumMemoization(row-1,col,arr,dp);
        int costFromLeft = minPathSumMemoization(row,col-1,arr,dp);  
        
        // save the calculated min path cost
        dp[row][col] = Math.min(costFromLeft,costFromUp) + arr[row][col];

        // return the minimum of the total cost from up & left
        return dp[row][col];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int minPathSumTabulation(int m,int n,int arr[][]){
        // Base case -> Recurrence Relation
        int dp[][] = new int[m][n];

        // base case
        dp[0][0] = arr[0][0];

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0){
                    dp[row][col]=arr[row][col];
                }else{
                    int up=Integer.MAX_VALUE, left = Integer.MAX_VALUE;
                    if(row>0) up = arr[row][col]+dp[row-1][col];
                    if(col>0) left = arr[row][col]+dp[row][col-1];
                    dp[row][col] = Math.min(up, left);
                }
                // dp[row][col] = arr[row][col] + Math.min(dp[row-1][col], dp[row][col-1]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.print(dp[i][j]+" ");
            }
            System.out.println();
        }
        return dp[m-1][n-1];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int minPathSumDPOptimized(int m ,int n,int arr[][]){

        // it needs a previous row and previous column values to start with
        int prevRow[] = new int[n];         
      
        // starting from 1,1 to m,n
        for(int row=0;row<m;row++){
            
            // temporary previous row
            int currRow[] = new int[n];

            for(int col=0;col<n;col++){
                // base case
                if(row==0 && col==0){
                    currRow[0]=arr[row][col];
                }
                else{
                    int up = Integer.MAX_VALUE, left = Integer.MAX_VALUE;
                    // when row==1 prev row becomes curr row
                    if(row>0){
                        up = arr[row][col] + prevRow[col];
                    }
                    // talks about current row
                    if(col>0){
                        left = arr[row][col] + currRow[col-1];
                    }
                    currRow[col] = Math.min(up,left);
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
        // ans = minPathSumRecursion_1(m-1,n-1,arr);
        // System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[m][n];
        for(int i=0;i<m;i++) { 
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }

        // ans = minPathSumMemoization(m-1,n-1,arr,dp);
        // System.out.println("DP Memoization:"+ans);
        
        ans = minPathSumTabulation(m,n,arr);
        System.out.println("DP Tabulation:"+ans);
        
        ans = minPathSumDPOptimized(m,n,arr);
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

