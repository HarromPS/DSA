package Java.Graphs;

import java.io.*;
import java.util.*;

public class _0_Graph_Representation {
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
     * An undirected graph is a graph where edges are bidirectional, with no
     * direction associated with them, i.e, there will be an undirected edge. In an
     * undirected graph, the pair of vertices representing any edge is unordered.
     * Thus, the pairs (u, v) and (v, u) represent the same edge.
     * 
     * A directed graph is a graph where all the edges are directed from one vertex
     * to another, i.e, there will be a directed edge. It contains an ordered pair
     * of vertices. It implies each edge is represented by a directed pair <u, v>.
     * Therefore, <u, v> and <v, u> represent two different edges.
     * 
     * Representation of Graphs
     */

    // adjacency matrix
    static public void Adjancency_Matrix(int n,int m,FastReader sc){
        int adj_mat[][] = new int[n+1][n+1];    // n x n
        for(int i=0;i<m;i++){
            // iterate and fill matrix from a list 
            int u = sc.nextInt();
            int v = sc.nextInt();

            adj_mat[u][v] = 1;
            adj_mat[v][u] = 1;
        }

        System.out.println("Adjacency Matrix");
        for(int u=0;u<n+1;u++){
            for(int v=0;v<n+1;v++){
                System.out.print(adj_mat[u][v]+" ");
            }
            System.out.println();
        }
    }
    
    // Adjancency_List
    public static void Adjancency_List(int n,int m,FastReader sc){
        ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
        
        // Initialize adjacency list with empty lists for each vertex
        for (int i = 0; i < n+1; i++) {
            adj_list.add(new ArrayList<>());
        }

        for(int i=0;i<m;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            
            adj_list.get(v).add(u);
            adj_list.get(u).add(v);
        }
        
        System.out.println("Adjancency_List");
        for(int u=0;u<adj_list.size();u++){
            System.out.print(u+"[ " );
            for(int v=0;v<adj_list.get(u).size();v++){
                System.out.print(adj_list.get(u).get(v)+" ");
            }
            System.out.println("]");
        }
    }

    // Weighted_Matrix
    public static void Weighted_Matrix(int n,int m,FastReader sc){
        // {node - (node, weight)}
        ArrayList<ArrayList<ArrayList<Integer>>> adj_list = new ArrayList<>();
        for(int i=0;i<n+1;i++){
            adj_list.add(new ArrayList<>());
        }

        for(int i=0;i<m;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int wt = sc.nextInt();

            ArrayList<Integer> edge = new ArrayList<>();
            edge.add(v);
            edge.add(wt);

            adj_list.get(u).add(edge);

            edge = new ArrayList<>();            
            edge.add(u);
            edge.add(wt);
            adj_list.get(v).add(edge);

        }

        System.out.println("Adjacency List with Weights:");
        for (int u = 0; u < adj_list.size(); u++) {
            System.out.print(u + ": ");
            for (ArrayList<Integer> edge : adj_list.get(u)) {
                System.out.print("(" + edge.get(0) + ", " + edge.get(1) + ") ");
            }
            System.out.println();
        }

    }
    public static void solve(FastReader sc) {
        int n = sc.nextInt();   // nodes
        int m = sc.nextInt();   // edges

        // // adjacency matrix
        // Adjancency_Matrix(n,m, sc);
        
        // adjacency list
        // Adjancency_List(n,m,sc);

        // // weighted grpah matrix
        Weighted_Matrix(n,m,sc);

        // // weighted graph list
        // Weighted_List(n,m,sc);
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

/*
5 6

1 2
1 3
2 4
2 5
3 4
4 5

1 2
1 3
2 4
2 5
3 4
4 5

1 2 2
1 3 3
2 4 1
2 5 6
3 4 4
4 5 3

1 2 2
1 3 3
2 4 1
2 5 6
3 4 4
4 5 3
 */