package Java.Tree;

import java.io.*;
import java.util.*;

class TreeNode_7_{
    public int data;
    public TreeNode_7_ left;
    public TreeNode_7_ right;
    public TreeNode_7_(){}
    public TreeNode_7_(int val){
        this.data=val;
        this.left=null;
        this.right=null;
    }
}

class Pair{
    public int hd;
    public TreeNode_7_ node;
    public Pair(int hd,TreeNode_7_ node){
        this.hd=hd;
        this.node=node;
    }
}

public class _7_Vertical_Order {
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

    //Function to find the vertical order traversal of Binary Tree.
    public static ArrayList <Integer> verticalOrder(TreeNode_7_ root)
    {
        // add your code here
        ArrayList<Integer> ans=new ArrayList<>();
        Queue<Pair> q=new ArrayDeque<>();
        Map<Integer,ArrayList<Integer>> map=new TreeMap<>();
        
        q.add(new Pair(0,root));
        while(!q.isEmpty())
        {
            Pair curr= q.poll();
            if(map.containsKey(curr.hd)){
                map.get(curr.hd).add(curr.node.data);
            }
            else {
                ArrayList<Integer> temp=new ArrayList<>();
                temp.add(curr.node.data);
                map.put(curr.hd,temp);
            }
            if(curr.node.left!=null){
                q.add(new Pair((curr.hd)-1,curr.node.left));
            }
            if(curr.node.right!=null){
                q.add(new Pair((curr.hd)+1,curr.node.right));
            }
        }
        
        for(Map.Entry<Integer,ArrayList<Integer>> entry: map.entrySet()){
            ans.addAll(entry.getValue());
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        TreeNode_7_ root = new TreeNode_7_(1);
        TreeNode_7_ two = new TreeNode_7_(2);
        TreeNode_7_ three = new TreeNode_7_(3);
        TreeNode_7_ four = new TreeNode_7_(4);
        TreeNode_7_ five = new TreeNode_7_(5);
        TreeNode_7_ six = new TreeNode_7_(6);
        TreeNode_7_ seven = new TreeNode_7_(7);

        root.left = two;
        root.right = five;

        two.left=three;
        two.right=four;

        five.left=six;
        five.right=seven;

        ArrayList <Integer> ans = verticalOrder(root);
        for(int i=0;i<ans.size();i++){
            System.out.print(ans.get(i)+" ");
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
        // solve(sc);
        // }
        solve(sc);
    }
}