package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_6_{
    public int data;
    public TreeNode_6_ left;
    public TreeNode_6_ right;
    public TreeNode_6_(){}
    public TreeNode_6_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

class Pair_<T, U> {
    public final T first;
    public final U second;

    public Pair_(T first, U second) {
        this.first = first;
        this.second = second;
    }
}

public class _6_All_traversals {
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
    public static void All_In_One_Traversals(TreeNode_6_ root){
        ArrayList<Integer> preorder = new ArrayList<>();
        ArrayList<Integer> inorder = new ArrayList<>();
        ArrayList<Integer> postorder = new ArrayList<>();

        Stack<Pair_<TreeNode_6_,String>> st = new Stack<>(); // stack 1

        // st.push(new Pair_<TreeNode_6_, String>(root, "preorder"));
        st.push(new Pair_<>(root,"preorder"));
        
        while(!st.isEmpty()){
            Pair_<TreeNode_6_, String> n = st.peek();
            st.pop();

            if(n.second == "preorder"){
                preorder.add(n.first.data);
                st.push(new Pair_<>(n.first, "inorder"));
                if(n.first.left!=null){
                    st.push(new Pair_<>(n.first.left, "preorder"));
                }
            }
            else if(n.second == "inorder"){
                inorder.add(n.first.data);
                st.push(new Pair_<>(n.first,"postorder"));
                if(n.first.right!=null){
                    st.push(new Pair_<>(n.first.right, "preorder"));
                }
            }
            else if(n.second == "postorder"){
                postorder.add(n.first.data);
            }
        }
        for(int i=0;i<inorder.size();i++){
            System.out.println(preorder.get(i)+" "+inorder.get(i)+" "+postorder.get(i));
        }
    }

    public static void solve(FastReader sc) {
        TreeNode_6_ root = new TreeNode_6_(1);
        TreeNode_6_ two = new TreeNode_6_(2);
        TreeNode_6_ three = new TreeNode_6_(3);
        TreeNode_6_ four = new TreeNode_6_(4);
        TreeNode_6_ five = new TreeNode_6_(5);
        TreeNode_6_ six = new TreeNode_6_(6);
        TreeNode_6_ seven = new TreeNode_6_(7);

        root.left = two;
        root.right = five;

        two.left=three;
        two.right=four;

        five.left=six;
        five.right=seven;

        All_In_One_Traversals(root);
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