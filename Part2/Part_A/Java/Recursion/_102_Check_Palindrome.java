package Java.Recursion;

import java.io.*;
import java.util.*;

public class _102_Check_Palindrome {
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
     * Check if a string is a palindrome 
     * 
     * A sequence which is same when read from front and also from back called as palindrome.
     * 
     * A string on reversal reads the same is called as palindrome.
     * madam
     * true 
     * 
     * abcd
     * false
    */

    // Brute force
    public static boolean Brute_Check_Palindrome(String s){
        int n = s.length();
        int i=0,j=n-1;

        // just have 2 pointers, one from front and one from back 
        // and see it matched then well and good return true after i and j crosses, false otherwise
        while(i<j){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;        
    }
    
    // Recursive way 
    public static boolean Recursive_Check_Palindrome(int i,int j,String s){
        // base case 
        if(i>=j){
            return true;
        }

        // recurrence relation
        if(s.charAt(i) != s.charAt(j)){
            return false;
        }

        boolean ans = Recursive_Check_Palindrome(i+1, j-1, s);
        return ans;
    }


    public static void solve(FastReader sc) {
        String s;
        s = sc.nextLine();
        int n = s.length();

        // Brute force
        boolean ans = Brute_Check_Palindrome(s);
        System.out.println("Brute Palindrome: "+ans);
        
        // Recursive Approach
        ans = Recursive_Check_Palindrome(0, n-1, s);
        System.out.println("Recursive Palindrome: "+ans);
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
        //     solve(sc);
        // }
        solve(sc);
    }
}