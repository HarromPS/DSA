package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _10_Triangle {
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
    - Given a triangle array, return the minimum path sum from top to bottom.

    - For each step, you may move to an adjacent number of the row below. More formally, 
    - if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
    2 0 0 0 
    3 4 0 0
    6 5 7 0
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 
    */

    // Brute force: TLE T.C: O(2^(m x n)) S.C: (m-1 + n-1)
    // f(i,j)=> signifies no of ways from 0,0 to i,j
    // starting from (m-1, n-1)
    public static int minPathSumTriangleRecursion_1(ArrayList<ArrayList<Integer>> arr,int i,int j,int n){
        // base cases
          // base case: if we are at the last row, return the element at the current position
          if (i >= n ) {
            return 0;
        }
        
        // get the minimum path sum from the next row and next row's diagonal
        int down = minPathSumTriangleRecursion_1(arr, i + 1, j, n);
        int downDiagonal = minPathSumTriangleRecursion_1(arr, i + 1, j + 1, n);  

        // return the current element plus the minimum path sum from the two possible paths
        return arr.get(i).get(j) + Math.min(down, downDiagonal);
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(m x n), S.C: O(m x n) + O(m-1+n-1)
    public static int minPathSumTriangleMemoization(ArrayList<ArrayList<Integer>> arr,int i,int j,int n,int dp[][]){
       // base case: if we are at the last row, return the element at the current position
        if (i >= n ) {
            return 0;
        }

        // check if value is already calculated prevoiusly
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // get the minimum path sum from the next row and next row's diagonal
        int down = minPathSumTriangleMemoization(arr, i + 1, j, n,dp);
        int downDiagonal = minPathSumTriangleMemoization(arr, i + 1, j + 1, n,dp);  

        // save the calculated values
        dp[i][j]=arr.get(i).get(j) + Math.min(down, downDiagonal);

        // return the current element plus the minimum path sum from the two possible paths
        return dp[i][j];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(m x n), S.C: O(m x n) 
    public static int minPathSumTriangleTabulation(ArrayList<ArrayList<Integer>> arr,int n){
        // Base case -> Recurrence Relation
        int dp[][] = new int[n][n];

        // base case: last row is fixed 
        // if(i==n-1) return a[i][j];

        for(int i=0;i<arr.get(n-1).size();i++) dp[n-1][i] = arr.get(n-1).get(i);

        // run from last i.e bottom up (base case: recurrence relation)
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<arr.get(i).size();j++){
                int down = dp[i+1][j];
                int downDiagonal =  dp[i+1][j+1];
                dp[i][j] = arr.get(i).get(j) + Math.min(down,downDiagonal);
            }
        }
       
        return dp[0][0];
    }

    // DP optimized
    // T.C: O(m x n), S.C: O(1)
    public static int minPathSumTriangleDPOptimized(ArrayList<ArrayList<Integer>> arr,int n){
        // we need only two rows to follow 
        // i.e next row and current row 

        int next[] = new int[n];

        // start from last 2nd row i.e base case
        for(int i=n-1;i>=0;i--){
            // current row, take value of current working row
            int curr[] = new int[arr.get(i).size()];
            for(int j=0;j<arr.get(i).size();j++){
                // base case 
                if(i==n-1){
                    curr[j] = arr.get(i).get(j);
                }else {
                    int down = next[j];
                    int downDiagonal = next[j+1];
                    curr[j] = arr.get(i).get(j) + Math.min(down,downDiagonal);
                }
            }
            // update next row
            for(int j=0;j<arr.get(i).size();j++){
                next[j]=curr[j];
            }
        }
        return next[0];
    }
    
    public static void solve(FastReader sc) {
        // int m=sc.nextInt();
        int n=sc.nextInt();

        /* 5 7 3 4 */

        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<n;i++){
            ArrayList<Integer> currArr = new ArrayList<>();
            for(int j=0;j<=i;j++){
                int r=sc.nextInt();
                currArr.add(r);
            }
            arr.add(currArr);
        }

        int ans=minPathSumTriangleRecursion_1(arr,0,0,n);
        System.out.println("Brute force: "+ans);
        
        int dp[][] = new int[n][n];
        for(int i=0;i<n;i++) { 
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }

        // ans = minPathSumTriangleMemoization(arr,0,0,n,dp);
        // System.out.println("DP Memoization:"+ans);
        
        // ans = minPathSumTriangleTabulation(arr,n);
        // System.out.println("DP Tabulation:"+ans);
        
        // ans = minPathSumTriangleDPOptimized(arr,n);
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

