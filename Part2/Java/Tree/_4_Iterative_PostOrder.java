package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_4_{
    public int data;
    public TreeNode_4_ left;
    public TreeNode_4_ right;
    public TreeNode_4_(){}
    public TreeNode_4_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

public class _4_Iterative_PostOrder {
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
    public static void IterativePostorderTraversalUsing_2_Stack(TreeNode_4_ root){
        ArrayList<Integer> postorder = new ArrayList<>();
        Stack<TreeNode_4_> st1=new Stack<TreeNode_4_>(); // stack 1
        Stack<TreeNode_4_> st2=new Stack<TreeNode_4_>(); // stack 1
        st1.push(root);

        while(!st1.isEmpty()){
            TreeNode_4_ n = st1.peek();
            st1.pop();

            if(n.left != null ) st1.push(n.left);
            if(n.right != null) st1.push(n.right);
            st2.push(n);
        }
        
        while(!st2.empty()){
            postorder.add(st2.peek().data);
            st2.pop();
        }

        for(int i=0;i<postorder.size();i++){
            System.out.print(postorder.get(i)+" ");
        }
    }


    public static void IterativePostorderTraversalUsing_1_Stack(TreeNode_4_ root){
        ArrayList<Integer> postorder = new ArrayList<>();
        Stack<TreeNode_4_> st=new Stack<TreeNode_4_>(); // stack 1

        TreeNode_4_ curr = root;
        TreeNode_4_ temp = null;

        while(curr!=null || !st.isEmpty()){
            if(curr!=null){
                st.push(curr);
                curr=curr.left;
            }
            else{
                temp = st.peek().right;
                if(temp==null){
                    temp=st.peek();
                    st.pop();
                    postorder.add(temp.data);
                    while(!st.isEmpty() && temp==st.peek().right){
                        temp=st.peek();
                        st.pop();
                        postorder.add(temp.data);
                    }
                }else{
                    curr = temp;
                }
            }
        }

        for(int i=0;i<postorder.size();i++){
            System.out.print(postorder.get(i)+" ");
        }
    }

    public static void solve(FastReader sc) {
        TreeNode_4_ root = new TreeNode_4_(1);
        TreeNode_4_ two = new TreeNode_4_(2);
        TreeNode_4_ three = new TreeNode_4_(3);
        TreeNode_4_ four = new TreeNode_4_(4);
        TreeNode_4_ five = new TreeNode_4_(5);
        TreeNode_4_ six = new TreeNode_4_(6);
        TreeNode_4_ seven = new TreeNode_4_(7);

        root.left = two;
        root.right = five;

        two.left=three;
        two.right=four;

        five.left=six;
        five.right=seven;

        IterativePostorderTraversalUsing_2_Stack(root);
        System.out.println();
        IterativePostorderTraversalUsing_1_Stack(root);
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