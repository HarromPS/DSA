package Java.LinkedList;

import java.io.*;
import java.util.*;

class Node12{
    public int data;
    public Node12 next;
    public Node12(){
        this.data=-1;
        this.next=null;
    }
    public Node12(int data){
        this.data = data;
        this.next = null;
    }
}

public class _2181_Merge_node12_in_Between_zeros {
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
    
    - You are given the head of a linked list, which contains a series of integers separated by 0's.
    - The beginning and end of the linked list will have Node12.val == 0.

    - For every two consecutive 0's, merge all the node12s lying in between them into a single node12 whose value is the sum of all the merged node12s. 
    - The modified list should not contain any 0's.

    Return the head of the modified linked list.

    e.g Input: head = [0,3,1,0,4,5,2,0]
    Output: [4,11]
    Explanation: 
    The above figure represents the given linked list. The modified list contains
    - The sum of the node12s marked in green: 3 + 1 = 4.
    - The sum of the node12s marked in red: 4 + 5 + 2 = 11.


     */

    
    // Brute Force
    // T.C: O(n+m+log n) set operation
    // S.c: O(n+m)       set space(worst case, if unique elements are in both arrays)
    public static Node12 MergeInBetnZeros_Brute(Node12 head) { 
        ArrayList<Integer> ds = new ArrayList<>();
        Node12 curr = head;
        int mergedSum=0;
        curr=curr.next;
        while(curr!=null){
            while(curr.data!=0){
                mergedSum+=curr.data;
                curr=curr.next;
            }
            ds.add(mergedSum);
            mergedSum=0;
            curr=curr.next;
        }

        Node12 prev = new Node12();
        curr = prev;
        for (int i = 0; i < ds.size(); i++) {
            Node12 newNode12 = new Node12(ds.get(i)); 
            prev.next = newNode12;
            prev = prev.next;
        }
        curr=curr.next;
        return curr;
    }

    // Better
    // T.C: O(n)
    // S.c: O(1)
    public static Node12 MergeInBetnZeros_Better(Node12 head) { 
        Node12 prev = head;
        Node12 i = head;
        Node12 curr = head.next;

        int mergedSum=0;
        while (curr!=null) {
            while (curr!=null && curr.data!=0) {
                mergedSum+=curr.data;            
                curr=curr.next;
            }
            curr.data = mergedSum;
            mergedSum=0;
            prev.next=curr;
            prev=curr;
            curr=curr.next;
        }

        return i.next;
    }

    
    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        Node12 prev = new Node12();
        Node12 head = prev;
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            Node12 newNode12 = new Node12(r); 
            prev.next = newNode12;
            prev = prev.next;
        }

        head=head.next;
        Node12 newNode12 = new Node12();
        newNode12 = MergeInBetnZeros_Brute(head); 
        while (newNode12!=null) {
            System.out.print(newNode12.data+" ");
            newNode12 = newNode12.next;
        }
        System.out.println();
        newNode12 = MergeInBetnZeros_Better(head);
        while (newNode12!=null) {
            System.out.print(newNode12.data+" ");
            newNode12 = newNode12.next;
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