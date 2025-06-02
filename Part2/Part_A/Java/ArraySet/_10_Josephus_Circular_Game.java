package Java.ArraySet;

import java.io.*;
import java.util.*;

class Node{
    int data;
    Node next;

    Node(int val){
        data = val;
        next = null;
    }
};

public class _10_Josephus_Circular_Game {
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
     There are n friends that are playing a game. 
     The friends are sitting in a circle and are numbered from 1 to n in clockwise order. 
     More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

    The rules of the game are as follows:

    Start at the 1st friend.
    Count the next k friends in the clockwise direction including the friend you started at. 
    The counting wraps around the circle and may count some friends more than once.
    The last friend you counted leaves the circle and loses the game.
    If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
    Else, the last friend in the circle wins the game.

    Given the number of friends, n, and an integer k, return the winner of the game.

    e.g Input: n = 5, k = 2
    Output: 3
    Explanation: Here are the steps of the game:
    1) Start at friend 1.
    2) Count 2 friends clockwise, which are friends 1 and 2.
    3) Friend 2 leaves the circle. Next start is friend 3.
    4) Count 2 friends clockwise, which are friends 3 and 4.
    5) Friend 4 leaves the circle. Next start is friend 5.
    6) Count 2 friends clockwise, which are friends 5 and 1.
    7) Friend 1 leaves the circle. Next start is friend 3.
    8) Count 2 friends clockwise, which are friends 3 and 5.
    9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
    
     */

    // Brute Force
    // T.C: O(n) travese link list
    // S.c: O(n) linked list 
    public static int findTheWinner(int n, int k) {   
        // as this is a circular game, we can implement a circular linked list which will solve it
        if(n==1) return 1;
        int i=1;
        Node head = new Node(i);
        Node curr = head;
        i+=1;
        while(i<=n){
            Node newNode = new Node(i);
            curr.next = newNode;
            curr = curr.next;
            i++;
        }
        curr.next = head;
        curr = head;

        // start deleting the nodes
        int temp=k;
        while(n>1){
            temp--;
            while(temp>0){
                temp--;
                head=head.next;
            }
            // delete curr node
            head.data = head.next.data;
            head.next = head.next.next;
            temp=k;
            n--;
        }

        return head.data;
    }

    // Better: Queue
    // T.C: O(n)
    // S.C: O(n)
    public static int findTheWinner_Better(int n,int k){
        // move k in modulus
        Queue<Integer> q = new LinkedList<>();
        for(int i=1;i<=n;i++){
            q.add(i);
        }

        int temp=k;
        while(n>1){
            temp--;
            while(temp>0){
                temp--;
                int front = q.poll();
                q.add(front);
            }
            q.poll();
            n--;
            temp=k;
        }
        System.out.println(q.peek());
        return q.peek();
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        findTheWinner(n, k);
        findTheWinner_Better(n, k);
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