package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_1_{
    public int data;
    public TreeNode_1_ left;
    public TreeNode_1_ right;
    public TreeNode_1_(){}
    public TreeNode_1_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _1_Tree_Traversals {
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
    public static void PreOrderTraversal(TreeNode_1_ root){
        if(root==null) return;

        System.out.print(root.data+" ");
        PreOrderTraversal(root.left);
        PreOrderTraversal(root.right);
    }

    public static void InOrderTraversal(TreeNode_1_ root){
        if(root==null) return;

        InOrderTraversal(root.left);
        System.out.print(root.data+" ");
        InOrderTraversal(root.right);
    }

    public static void PostOrderTraversal(TreeNode_1_ root){
        if(root==null) return;

        PostOrderTraversal(root.left);
        PostOrderTraversal(root.right);
        System.out.print(root.data+" ");
    }

    public static void solve(FastReader sc) {
        TreeNode_1_ root = new TreeNode_1_(1);
        root.left = new TreeNode_1_(2);
        root.right = new TreeNode_1_(3);
        root.left.right = new TreeNode_1_(5);

        PreOrderTraversal(root);
        System.out.println();
        InOrderTraversal(root);
        System.out.println();
        PostOrderTraversal(root);
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