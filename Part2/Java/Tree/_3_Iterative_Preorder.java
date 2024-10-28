package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_3_{
    public int data;
    public TreeNode_3_ left;
    public TreeNode_3_ right;
    public TreeNode_3_(){}
    public TreeNode_3_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _3_Iterative_Preorder {
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
    public static void IterativePreorderTraversal(TreeNode_3_ root){
        ArrayList<Integer> preorder = new ArrayList<>();
        Stack<TreeNode_3_> st=new Stack<TreeNode_3_>();
        st.push(root);

        while(!st.isEmpty()){
            TreeNode_3_ n = st.peek();
            st.pop();

            if(n.right != null) st.push(n.right);
            if(n.left != null ) st.push(n.left);
            preorder.add(n.data);
        }
        
        for(int i=0;i<preorder.size();i++){
            System.out.print(preorder.get(i)+" ");
        }
    }

    public static void solve(FastReader sc) {
        TreeNode_3_ root = new TreeNode_3_(1);
        TreeNode_3_ two = new TreeNode_3_(2);
        TreeNode_3_ three = new TreeNode_3_(3);
        TreeNode_3_ four = new TreeNode_3_(4);
        TreeNode_3_ five = new TreeNode_3_(5);
        TreeNode_3_ six = new TreeNode_3_(6);
        TreeNode_3_ seven = new TreeNode_3_(7);

        root.left = two;
        root.right = five;

        two.left=three;
        two.right=four;

        five.left=six;
        five.right=seven;

        IterativePreorderTraversal(root);
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