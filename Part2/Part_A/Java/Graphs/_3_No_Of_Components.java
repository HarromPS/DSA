package Java.Graphs;

import java.io.*;
import java.util.*;

public class _3_No_Of_Components {
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
     * Given an undirected graph with V vertices. We say two vertices u and v belong
     * to a single province if there is a path from u to v or v to u. Your task is
     * to find the number of provinces.
     * 
     * Note: A province is a group of directly or indirectly connected cities and no
     * other cities outside of the group.
     *
     * 
     * 
     */

    // DFS traveral
    public static void DFS_Traversal(int node, ArrayList<Integer> visited, ArrayList<ArrayList<Integer>> adj_list) {
        // mark node as visited
        visited.set(node,1);
        // System.out.print(node + " ");

        // ask for neighbours
        for (Integer neighbour : adj_list.get(node)) {
            // if not visited call dfs for them and go to depth
            if (visited.get(neighbour) != 1) {
                DFS_Traversal(neighbour, visited, adj_list);
            }
        }
    }

    public static void BFS_Traversal(int n, ArrayList<ArrayList<Integer>> adj_list,int start,ArrayList<Integer> visited) {
        // 1 based indexing

        Queue<Integer> q = new LinkedList<>(); // Queue
        visited.set(start,1); // 1st node is 1
        q.add(start); // Put it in queue

        // take all out until queue is empty
        while (!q.isEmpty()) {
            int node = q.peek();
            q.remove();
            // System.out.print(node + " ");

            // ask for its neighbours
            for (Integer neighbour : adj_list.get(node)) {
                // if neighbours are not visited add it to queue
                if (visited.get(neighbour)!= 1) {
                    q.add(neighbour);
                    visited.set(neighbour,1);
                }
            }
        }
    }

    // Adjancency List
    static public void Number_Of_Provinces(int n, int m, FastReader sc) {
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

        // Number of Provinces
        // find 3 starting points

        int provinces=0;
        ArrayList<Integer> visited = new ArrayList<>();
        for(int i=0;i<n+1;i++) visited.add(0);

        // run a loop for all nodes and find non visited disconnected nodes
        for(int i=1;i<=n;i++){
            // if not visited 
            if(visited.get(i)!=1){
                provinces++;
                // call dfs or bfs
                // BFS_Traversal(n, adj_list, i,visited);
                // DFS_Traversal(i, visited, adj_list);
            }
        }
        System.out.println("Number of Provinces: "+provinces);
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt(); // nodes
        int m = sc.nextInt(); // edges

        Number_Of_Provinces(n, m, sc);

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
