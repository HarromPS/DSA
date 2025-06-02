package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _8_III_Total_Unique_Paths {
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

    - You are given an m x n integer array grid where grid[i][j] could be:

    - 1 representing the starting square. There is exactly one starting square.
    - 2 representing the ending square. There is exactly one ending square.
    - 0 representing empty squares we can walk over.
    - (-1) representing obstacles that we cannot walk over.

    - Return the number of 4-directional walks from the starting square to the ending square, 

    "that walk over every non-obstacle square exactly once."
    Means covers all the zeros

    e.g: 
        Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
        Output: 2
        Explanation: We have the following two paths: 
        1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
        2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
    */

    // Brute force: TLE T.C: O(4^(m x n)) S.C: (m x n)  => trying all 4 directions

    // res -> result of all possible paths covering all zeros and reaching end
    // zeroCount is count of zeros in array and at end all zeros are covered 
    public static int res=0, zeroCount=0;   
    public static void DFS_Backtracking(int arr[][],int i,int j,int m,int n){
        // base cases 

        // if bot goes out of boundary, is already visited (-2), is obstacle (-1) in the cell 
        if(i<0 || j<0 || i>=m || j>=n || arr[i][j]==-2 || arr[i][j]==-1){
            return;
        }

        // if reached the end and covered all zeros 
        if (arr[i][j] == 2) {
            if (zeroCount == 0) { // zeroCount is 0 means we have visited all 0s
                res++;  // found a path
            }
            return;
        }

        // mark the cell as visited 
        int temp = arr[i][j];
        arr[i][j] = -2;

        // decrease zero count if this cell's zero is covered
        if (temp == 0) {
            zeroCount--;
        }

        // try all possible directions
        DFS_Backtracking(arr, i + 1, j, m, n);  // down
        DFS_Backtracking(arr, i - 1, j, m, n);  // up
        DFS_Backtracking(arr, i, j + 1, m, n);  // right
        DFS_Backtracking(arr, i, j - 1, m, n);  // left

        // backtrack: unmark the cell as visited
        arr[i][j] = temp;
        // increase zero count if this cell's zero is uncovered
        if (temp == 0) {
            zeroCount++;
        }
    }
   
    public static void solve(FastReader sc) {
        int m=sc.nextInt();
        int n=sc.nextInt();

        // indexes of starting point
        int x=0,y=0;

        int arr[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r=sc.nextInt();
                if(r==0) zeroCount++;
                if(r==1) x=i;y=j;
                arr[i][j]=r;
            }
        }      

        DFS_Backtracking(arr,x,y,m,n);
        System.out.println("DFS + Backtracking Brute force: "+res);
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

