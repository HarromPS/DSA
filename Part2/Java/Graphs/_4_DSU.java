package Java.Graphs;

import java.io.*;
import java.util.*;

public class _4_DSU {
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
    
    DSU - Disjoint Union Data structrue O(4 x alpha)

    - it is not a graph data structure 
    - it is a different data structure

    - use cases: 
        - check if a node is connected to another node in constant time 
        - using bfs or dfs it takes O(n + e) time complexity, linear 
        - dynamic graphs where number of nodes keeps changing
    
    - performed using:
        - find parent function(finding the ultimate parent of a node) O(log n) as a brute and O(4 x alpha) if optimized called path compression
        - union by rank(max height of the component) function O(4 x alpha) -- O(constant)
        - union by size(max nodes in the component) function

    - questions asked: 
        - parent of this node
        - number of nodes in a components 
        - number of components
        - union of two nodes(draw an edge between two nodes)

    - initial configurations:
        - needs a parent array
        - rank array with size as number of nodes for union by rank
        - size array with size as number of nodes for union by size

    - union algo:
        - find ultimate parent of u and v
        - find rank of ultimate parents pu pv
        - connect smaller rank to larger rank always
    
    - why attatch smaller to larger 
        - it takes smaller time to do path compression
        - so first to keep it shrinked 
        - second to make sure the time taken and finding the parent is as minimal as possible

    - why union by size
        - as rank does not downgrade the height of the component
        - as we can use union by size i.e how big is this component 

    */


    public static class DisjointSetUnionByRank{
        List<Integer> rank = new ArrayList<>();
        List<Integer> parent = new ArrayList<>();

        // initialize the rank and parent array
        public DisjointSetUnionByRank(int n){
            for(int i=0;i<=n;i++){
                this.rank.add(0);
                this.parent.add(i);
            }
        }

        // find ultimate parent of a node 
        public int findUltimateParent(int node){
            if(node == this.parent.get(node)){
                return node;
            }

            int ulp = this.findUltimateParent(this.parent.get(node));
            this.parent.set(node,ulp);
            return ulp;
        }

        // perform union by rank 
        public void unionByRank(int u,int v){
            int ulp_u = this.findUltimateParent(u); // ultimate parents of u and v
            int ulp_v = this.findUltimateParent(v);

            if(ulp_u == ulp_v) return;  // belongs to same component

            if(this.rank.get(ulp_v) < this.rank.get(ulp_u)){
                // v has smaller rank than u, so smaller attatches to larger 
                this.parent.set(ulp_v, ulp_u);
            }
            else if(this.rank.get(ulp_u) < this.rank.get(ulp_v)){
                this.parent.set(ulp_u, ulp_v);
            }
            else{
                // same rank 
                this.parent.set(ulp_u, ulp_v);
                int rankU = this.rank.get(ulp_u);
                this.rank.set(ulp_u,rankU+1);
            }
        }
    }

    
    public static class DisjointSetUnionBySize{
        List<Integer> size = new ArrayList<>();
        List<Integer> parent = new ArrayList<>();

        // initialize the size and parent array
        public DisjointSetUnionBySize(int n){
            for(int i=0;i<=n;i++){
                this.size.add(1);
                this.parent.add(i);
            }
        }

        // find ultimate parent of a node 
        public int findUltimateParent(int node){
            if(node == this.parent.get(node)){
                return node;
            }

            int ulp = this.findUltimateParent(this.parent.get(node));
            this.parent.set(node,ulp);
            return ulp;
        }

        // perform union by rank 
        public void unionBySize(int u,int v){
            int ulp_u = this.findUltimateParent(u); // ultimate parents of u and v
            int ulp_v = this.findUltimateParent(v);

            if(ulp_u == ulp_v) return;  // belongs to same component

            if(this.size.get(ulp_v) < this.size.get(ulp_u)){
                // v has smaller size than u, so smaller attatches to larger 
                this.parent.set(ulp_v, ulp_u);
                this.size.set(ulp_u, this.size.get(ulp_v) + this.size.get(ulp_u));
            }
            else{
                // same size 
                this.parent.set(ulp_u, ulp_v);
                this.size.set(ulp_v, this.size.get(ulp_v) + this.size.get(ulp_u));
            }
        }
    }

    public static void solve(FastReader sc) {
        // Example
        DisjointSetUnionByRank ds = new DisjointSetUnionByRank(7);
        ds.unionByRank(1,2);
        ds.unionByRank(2,3);
        ds.unionByRank(4,5);
        ds.unionByRank(6,7);
        ds.unionByRank(6,5);

        // if 3 and 7 belongs to same parent or not 
        if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
            System.out.println("Same Parent");
        }
        else{
            // do their union 
            ds.unionByRank(3,7);
            System.out.println("Not yet ... ");
            if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
                System.out.println("Same Parent");
            }
        }

        // Example
        DisjointSetUnionBySize ds2 = new DisjointSetUnionBySize(7);
        ds2.unionBySize(1,2);
        ds2.unionBySize(2,3);
        ds2.unionBySize(4,5);
        ds2.unionBySize(6,7);
        ds2.unionBySize(6,5);

        // if 3 and 7 belongs to same parent or not 
        if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
            System.out.println("Same Parent");
        }
        else{
            // do their union 
            ds2.unionBySize(3,7);
            System.out.println("Not yet ... ");
            if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
                System.out.println("Same Parent");
            }
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
        // }
        solve(sc);
    }
}