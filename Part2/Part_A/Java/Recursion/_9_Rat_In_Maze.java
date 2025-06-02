package Java.Recursion;

import java.io.*;
import java.util.*;

public class _9_Rat_In_Maze {
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
    public static void shortedCodeFindPaths(int i,int j,int maze[][],int visited[][],int di[],int dj[],String path,int n){
        // base case
        if(i>=n-1 && j>=n-1){
            System.out.println(path);
            return;
        }

        // move directions using a string
        String dir = "DLRU";
        for(int ind=0;ind<dir.length();ind++){
            int nexti = i+di[ind];
            int nextj = j+dj[ind];

            // all boundary checks at once
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && visited[nexti][nextj]==0 && maze[nexti][nextj]==1){
                visited[i][j]=1;
                shortedCodeFindPaths(nexti, nextj, maze, visited, di, dj, path+String.valueOf(dir.charAt(ind)), n);
                visited[i][j]=0;
            }
        }
    }

    public static void findPaths(int i,int j,int maze[][],int visited[][], String path,int n){
        // base condition
        if(i>=n-1 && j>=n-1){
            // print the path
            System.out.println(path);
            return;
        }

        // iterate in all possible 4 directions in lexicographical order and check for path

        // down 
        if(i+1 < n){        // check boundaries
            if(maze[i+1][j]==1 && visited[i+1][j]==0){  // if there is a way & if cell is already not visited
                // mark the current cell visited
                visited[i][j]=1;

                // visit the cell down
                findPaths(i+1, j, maze, visited, path+"D", n);

                // mark cell unvisited after backtrack
                visited[i][j]=0;
            }
        }

        // left
        if(j-1 >= 0){
            if(maze[i][j-1]==1 && visited[i][j-1]==0){
                visited[i][j]=1; 
                findPaths(i, j-1, maze, visited, path+"L", n);
                visited[i][j]=0;
            }
        }

        // right
        if(j+1 <n){
            if(maze[i][j+1]==1 && visited[i][j+1]==0){
                visited[i][j]=1; 
                findPaths(i, j+1, maze, visited, path+"R", n);
                visited[i][j]=0;
            }
        }

        // up
        if(i-1 >= 0){
            if(maze[i-1][j]==1 && visited[i-1][j]==0){
                visited[i][j]=1; 
                findPaths(i-1, j, maze, visited, path+"U", n);
                visited[i][j]=0;
            }
        }
    }
    public static void solve(FastReader sc) {
        // Rat in a maze problem -> rat at 0,0 position (n-1, n-1) is destination
        /* 
            It can move up, down, left, right
            0 - blocked cell / rat cannot move
            1 - rat can move to that cell 
            In a path, no cell can be visited more than once

            find all possible paths in lexicographical order
            "D | L | R | U" -> is a lexicographical order
        */ 

        int maze[][] = 
        {
            {1,0,0,0},
            {1,1,0,1},
            {1,1,0,0},
            {0,1,1,1},
        };

        int visited[][] = 
        {
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };

        int n = 4;

        // put rat in first cell
        visited[0][0]=1;

        // down | left | right | up
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};

        // find the paths if rat is at 0,0 position
        if(maze[0][0]==1){
            // findPaths(0,0,maze,visited,"",n);
            shortedCodeFindPaths(0, 0, maze, visited, di, dj, "", n);
        }
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