package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _51_Partition_Array {
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
     * Given an integer array arr, partition the array into (contiguous) subarrays
     * of length at most k. After partitioning, each subarray has their values
     * changed to become the maximum value of that subarray.
     * 
     * Return the largest sum of the given array after partitioning. Test cases are
     * generated so that the answer fits in a 32-bit integer.
     * 
     * Example 1:
     * 
     * Input: arr = [1,15,7,9,2,5,10], k = 3
     * Output: 84
     * Explanation: arr becomes [15,15,15,9,10,10,10]
     * 
     * Example 2:
     * 
     * Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
     * Output: 83
     * 
     */

    // function to check if a string is a palindrome
    public static boolean isPalindrome(int i, int j, String s) {
        while (i < j) {
            // if not a palindrome
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        // this is a palindrome
        return true;
    }
    // Solving this problem independantly will not work
    // Brute force

    public static int Partition_Array_Recursion(int i, int[] arr, int n, int k) {
        // base case
        // if there are no partitions
        if (i >= n) {
            return 0;
        }

        int ans = Integer.MIN_VALUE;
        int maxEle = Integer.MIN_VALUE; // max value of the partitioned array
        int len = 0; // len of the current partition

        // recurrence relation
        // loop till n-1 and make partitions
        for (int ind = i; ind < Math.min(n, k + i); ind++) {
            len++; // increase in length
            maxEle = Math.max(maxEle, arr[ind]);
            int sum = (maxEle * len) + Partition_Array_Recursion(ind + 1, arr, n, k);
            ans = Math.max(ans, sum);
        }

        return ans;
    }

    // DP Memoization
    public static int Partition_Array_Memoization(int i, int[] arr, int n, int dp[],int k) {
        // base case
        // if there are no partitions
        if (i >= n) {
            return 0;
        }

        // check if problems are previosly solved 
        if(dp[i]!=-1){
            return dp[i];
        }

        int ans = Integer.MIN_VALUE;
        int maxEle = Integer.MIN_VALUE; // max value of the partitioned array
        int len = 0; // len of the current partition

        // recurrence relation
        // loop till n-1 and make partitions
        for (int ind = i; ind < Math.min(n, k + i); ind++) {
            len++; // increase in length
            maxEle = Math.max(maxEle, arr[ind]);
            int sum = (maxEle * len) + Partition_Array_Memoization(ind + 1, arr, n, dp, k);
            ans = Math.max(ans, sum);
        }

        dp[i]=ans;
        return dp[i];
    }

    // DP Tabulation
    public static int Partition_Array_Tabulation_1(int[] arr,int k) {
        int n = arr.length;
        int dp[] = new int[n + 1];

        // base case
        dp[n] = 0;

        
        // recurrence relation
        // loop till n-1 and make partitions
        for(int i=n-1;i>=0;i--){

            int ans = Integer.MIN_VALUE;
            int maxEle = Integer.MIN_VALUE; // max value of the partitioned array
            int len = 0; // len of the current partition

            for (int ind = i; ind < Math.min(n, k + i); ind++) {
                len++; // increase in length
                maxEle = Math.max(maxEle, arr[ind]);
                int sum = (maxEle * len) + dp[ind + 1];
                ans = Math.max(ans, sum);
            }
            dp[i]=ans;
        }

        return dp[0] ;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int dp[] = new int[n];
        Arrays.fill(dp, -1);

        // uses the concept of (Front Partitioning)

        int ans = Partition_Array_Recursion(0, arr, n, k);
        System.out.println("Brute force:" + ans);

        ans = Partition_Array_Memoization(0, arr, n, dp, k);
        System.out.println("DP Tabulation Sriver_1:" + ans);

        ans = Partition_Array_Tabulation_1(arr, k);
        System.out.println("DP Tabulation Sriver_1:" + ans);

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
