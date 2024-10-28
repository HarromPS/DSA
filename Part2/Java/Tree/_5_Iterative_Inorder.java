package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_5_{
    public int data;
    public TreeNode_5_ left;
    public TreeNode_5_ right;
    public TreeNode_5_(){}
    public TreeNode_5_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _5_Iterative_Inorder {
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

    // TC:O(N) SC:O(N) 
    public static void IterativeInorderTraversal(TreeNode_5_ root){
        ArrayList<Integer> inorder = new ArrayList<>();
        Stack<TreeNode_5_> st=new Stack<TreeNode_5_>(); // stack 1

        TreeNode_5_ node = root;
        while(true){
            if(node!=null){
                st.push(node);
                node = node.left;
            }
            else{
                if(st.isEmpty()){ break;}
                node = st.peek();
                st.pop();
                inorder.add(node.data);
                node = node.right;
            }
        }
        for(int i=0;i<inorder.size();i++){
            System.out.print(inorder.get(i)+" ");
        }
    }

    public static void solve(FastReader sc) {
        TreeNode_5_ root = new TreeNode_5_(1);
        TreeNode_5_ two = new TreeNode_5_(2);
        TreeNode_5_ three = new TreeNode_5_(3);
        TreeNode_5_ four = new TreeNode_5_(4);
        TreeNode_5_ five = new TreeNode_5_(5);
        TreeNode_5_ six = new TreeNode_5_(6);
        TreeNode_5_ seven = new TreeNode_5_(7);

        root.left = two;
        root.right = five;

        two.left=three;
        two.right=four;

        five.left=six;
        five.right=seven;

        IterativeInorderTraversal(root);
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