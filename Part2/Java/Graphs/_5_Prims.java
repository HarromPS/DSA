package Java.Graphs;

import java.io.*;
import java.util.*;

public class _5_Prims {
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
     * Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges
     * 
     * Prims Algo | PQ | MST | VIS
     * 
     * Given a weighted, undirected, and connected graph with V vertices and E
     * edges,
     * your task is to find the sum of the weights of the edges in the Minimum
     * Spanning Tree (MST) of the graph.
     * The graph is represented by an adjacency list, where each element adj[i] is a
     * vector containing vector of integers.
     * Each vector represents an edge, with the first integer denoting the endpoint
     * of the edge and the second integer denoting the weight of the edge
     * 
     * - visited array
     * - mst edges
     * - path sum
     * - priority queue for min edge on top
     * 
     */

    public static void solve(FastReader sc){
        int n=sc.nextInt();
        int m=sc.nextInt();

        List<List<int[]>> adj = new ArrayList<>();
        for(int i=0;i<n;i++) adj.add(new ArrayList<>());
        for(int i=0;i<m;i++)[
            int u=sc.nextInt();
            int v=sc.nextInt();
            int wt=sc.nextInt();

            adj.get(u).add(new int[] {v,wt});
            adj.get(v).add(new int[] {u,wt});
        ]
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
        // }
        solve(sc);
    }
}