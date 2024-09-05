package Java.LinkedList;

import java.io.*;
import java.util.*;

class Node{
    public int data;
    public Node next;
    public Node(){
        this.data=-1;
        this.next=null;
    }
    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class Remove_All_Duplicates {
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
    
    Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), 
    leaving only numbers that appear once in the original list, and return the head of the modified linked list. 
    
    Input: Linked List = 23->28->28->35->49->49->53->53
    Output: 23 35
    Explanation: 

    The duplicate numbers are 28, 49 and 53 which are removed from the list.

     */

    
    // Brute Force
    // T.C: O(n+m+log n) set operation
    // S.c: O(n+m)       set space(worst case, if unique elements are in both arrays)
    public static Node Remove_All_Duplicates_Brute(Node head) {
        if(head==null || head.next==null){
            return head;
        }
        Node start = new Node();
        start.next = head;
        Node prev = start;
        Node curr = head;
        
        while(curr!=null){
            int isDuplicate = 0;
            
            // until next is not null & curr value is there in next free next 
            while(curr.next!=null && curr.data==curr.next.data){
                isDuplicate=1;
                curr.next = curr.next.next;
            }
            
            if(isDuplicate==0){
                prev = curr;
                curr = curr.next;
            }else{
                // means current is also a duplicate
                prev.next = curr.next;
                curr = curr.next;
            }
        }
        Node newNode = start.next;
        return newNode;
    }


    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        Node prev = new Node();
        Node head = prev;
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            Node newNode = new Node(r); 
            prev.next = newNode;
            prev = prev.next;
        }

        head=head.next;
        Node newNode = new Node();
        newNode = Remove_All_Duplicates_Brute(head);
        while (newNode!=null) {
            System.out.print(newNode.data+" ");
            newNode = newNode.next;
        }
        System.out.println();
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