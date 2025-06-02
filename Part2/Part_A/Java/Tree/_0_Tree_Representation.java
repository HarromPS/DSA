package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_0_{
    public int data;
    public TreeNode_0_ left;
    public TreeNode_0_ right;
    public TreeNode_0_(){}
    public TreeNode_0_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _0_Tree_Representation {
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

    public static void printTree(TreeNode_0_ root){
        if(root==null) return;
        System.out.print(root.data+" ");
        printTree(root.left);
        printTree(root.right);
    }

    public static void solve(FastReader sc) {
        TreeNode_0_ root = new TreeNode_0_(1);
        root.left = new TreeNode_0_(2);
        root.right = new TreeNode_0_(3);
        root.left.right = new TreeNode_0_(5);
        printTree(root);
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