package Java.Algorithms;

import java.io.*;
import java.util.*;

public class Sqrt {
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
     * 
     * Given an integer n, find the square root of n. If n is not a perfect square,
     * then return the floor value.
     * 
     * Floor value of any number is the greatest Integer which is less than or equal
     * to that number
     * 
     * Input: n = 5
     * Output: 2
     * Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is
     * 2.
     * 
     * Input: n = 4
     * Output: 2
     * Explanation: Since, 4 is a perfect square, so its square root is 2.
     * 
     */

    // T.C: O(long n)
    // S.C: O(1)
    public static void solve(FastReader sc) {
        long n = sc.nextLong();
        long low = 0;
        long high = n;
        long ans = 0;
        while(low<=high){
            long mid = (low+high)/2;
            if(mid*mid == n){
                ans=mid;
                break;
            }else if(mid*mid > n){
                high=mid-1;
            }else{
                low=mid+1;
                ans=mid;
            }
        }
        System.out.println("Sqrt is: "+ans);
    }

    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        FastReader sc = new FastReader(System.in);
        int test = sc.nextInt();
        while (test-- > 0) {
        solve(sc);
        }
        // solve(sc);
    }
}