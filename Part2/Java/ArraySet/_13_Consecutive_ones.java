package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _13_Consecutive_ones {
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
     * Given a binary array nums, return the maximum number of consecutive 1's in
     * the array.
     *
     * Example 1:
     * 
     * Input: nums = [1,1,0,1,1,1]
     * Output: 3
     * Explanation: The first two digits or the last three digits are consecutive
     * 1s. The maximum number of consecutive 1s is 3.
     * 
     * Example 2:
     * 
     * Input: nums = [1,0,1,1,0,1]
     * Output: 2
     * 
     */

     public static int findMaxConsecutiveOnes(int []nums) {
        int ans=0;
        int i=0;
        int n=nums.length;
        while(i<n){
            int count=0;
            // find 0
            while(i<n && nums[i]!=0){
                count++;
                i++;
            }
            ans=Math.max(ans,count);
            count=0;
            i++;
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int arr[]=new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = findMaxConsecutiveOnes(arr);
        System.out.println("Ans: " + ans);
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
        //
        solve(sc);
        // }
    }
}