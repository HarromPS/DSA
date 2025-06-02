package Java.Graphs;

import java.io.*;
import java.util.*;

public class _2_DFS {
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
     * DFS:
     * 
     * 1. Depth wise traversal
     * 2. Recursive traversal
     * 
     * steps:
     * 
     * Initial configurations
     * 
     * visited array
     * Mark 1st starting node as visited
     * 
     * 2nd
     * 
     * call dfs recursive function for starting node
     * mark it as visited
     * print it
     * ask for its neighbours
     * if neighbours are not visited 
     * then repeat step 2nd
     *
     */


    // DFS traveral
    public static void DFS_Traversal(int node,int visited[],ArrayList<ArrayList<Integer>> adj_list){
        // mark node as visited
        visited[node] = 1;
        System.out.print(node+" ");

        // ask for neighbours
        for(Integer neighbour: adj_list.get(node)){
            // if not visited call dfs for them and go to depth 
            if(visited[neighbour]!=1){
                DFS_Traversal(neighbour, visited, adj_list);
            }
        }
    }
    
    // Adjancency_List
    public static void DFS(int n, int m, FastReader sc) {
        ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();

        // Initialize adjacency list with empty lists for each vertex
        for (int i = 0; i < n + 1; i++) {
            adj_list.add(new ArrayList<>());
        }
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            
            adj_list.get(v).add(u);
            adj_list.get(u).add(v);
        }
        
        System.out.println("Adjancency_List");
        for (int u = 0; u < adj_list.size(); u++) {
            System.out.print(u + "[ ");
            for (int v = 0; v < adj_list.get(u).size(); v++) {
                System.out.print(adj_list.get(u).get(v) + " ");
            }
            System.out.println("]");
        }
        
        // DFS traversal
        System.out.println("\nDFS Traversal");
        
        // 1 based indexing 
        int visited[] = new int[n+1];
        visited[1]=1;
        DFS_Traversal(1,visited,adj_list);
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt(); // nodes
        int m = sc.nextInt(); // edges

        // adjacency list
        DFS(n,m,sc);

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
