package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_2_{
    public int data;
    public TreeNode_2_ left;
    public TreeNode_2_ right;
    public TreeNode_2_(){}
    public TreeNode_2_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _2_LevelOrder {
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
    Tree - non linear data structure
    */


    // Tree Traversals

    // TC:O(N) SC:O(N) auxillary space of tree
    public static void levelOrderTraversal(TreeNode_2_ root){
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        Queue<TreeNode_2_> q=new LinkedList<TreeNode_2_>();

        // initially add root to queue
        q.add(root);
        while(!q.isEmpty()){
            // get all the nodes out 
            ArrayList<Integer> level=new ArrayList<>();
            int n=q.size();
            for(int i=0;i<n;i++){
                if(q.peek().left!=null) q.add(q.peek().left);
                if(q.peek().right!=null) q.add(q.peek().right);
                
                level.add(q.poll().data);
            }
            // finally add to the answer 
            ans.add(level);
        }

        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.get(i).size();j++){
                System.out.print(ans.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }


    public static void solve(FastReader sc) {
        TreeNode_2_ root = new TreeNode_2_(1);
        root.left = new TreeNode_2_(2);
        root.right = new TreeNode_2_(3);
        root.left.right = new TreeNode_2_(5);

        levelOrderTraversal(root);
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