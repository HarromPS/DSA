package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _45_Number_of_Longest_Increasing_Subsequence {
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
     * Given an integer array nums, return the number of longest increasing
     * subsequences.
     * 
     * Notice that the sequence has to be strictly increasing.
     * Example 1:
     * 
     * Input: nums = [1,3,5,4,7]
     * Output: 2
     * Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1,
     * 3, 5, 7].
     * 
     * Example 2:
     * 
     * Input: nums = [2,2,2,2,2]
     * Output: 5
     * Explanation: The length of the longest increasing subsequence is 1, and there
     * are 5 increasing subsequences of length 1, so output 5.
     * 
     */

    // DP Optimized
    // T.C: O(N), O(1)
    // just check the difference between strings

    // Better Striver
    public static int Number_Of_Longest_Increasing_Subsequence_DPOptimized_Striver(int[] arr, int n) {
        int dp[] = new int[n];
        int count[] = new int[n];   // count the number of LIS till ith index

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            count[i]=1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j]+1) {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }else if(arr[i] > arr[j] && dp[i] == dp[j]+1) { // for same length same dp values, add count it to current val
                    count[i]+=count[j];
                }
            }
        }

        int maxLen=0;
        for (int i = 0; i < n; i++) {
            if(dp[i]>maxLen){
                maxLen=dp[i];
                ans = count[i];
            }
        }

        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int dp[][] = new int[n][n + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        int ans = Number_Of_Longest_Increasing_Subsequence_DPOptimized_Striver(arr, n);
        System.out.println("DP DPOptimized Sriver:" + ans);


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
