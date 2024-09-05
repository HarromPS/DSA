package Java.Graphs;

import java.io.*;
import java.util.*;

public class _1_BFS {
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
     * BFS:
     * 
     * 1. Level wise traversal
     * 2. Distance wise traversal
     * 
     * steps:
     * 
     * Initial configurations
     * 
     * Queue
     * visited array
     * Put it in queue
     * Mark 1st starting node as visited
     * 
     * 2nd
     * 
     * take all out until queue is empty
     * take out and print
     * ask for its neighbours
     * if neighbours are not visited add it to queue
     * mark as visited
     * 
     * repeat step 2 until empty
     */


    // BFS traveral
    public static void BFS_Traversal(int n,ArrayList<ArrayList<Integer>> adj_list){
        // 1 based indexing 
    
        Queue<Integer> q = new LinkedList<>();   // Queue
        int[] visited = new int[n+1];     // visited array
        visited[1]=1;       // 1st node is 1
        q.add(1);          // Put it in queue
    
        // take all out until queue is empty
        while(!q.isEmpty()){
            int node = q.peek();
            q.remove();
            System.out.print(node+" ");
    
            // ask for its neighbours
            for(Integer neighbour: adj_list.get(node)){
                // if neighbours are not visited add it to queue
                if(visited[neighbour]!=1){
                    q.add(neighbour);
                    visited[neighbour]=1;
                }
            }
        }
    }
  
    // Adjancency_List
    public static void BFS(int n, int m, FastReader sc) {
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

        // bfs traversal
        System.out.println("\nBFS Traversal");
        BFS_Traversal(n,adj_list);
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt(); // nodes
        int m = sc.nextInt(); // edges

        // adjacency list
        BFS(n,m,sc);

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
