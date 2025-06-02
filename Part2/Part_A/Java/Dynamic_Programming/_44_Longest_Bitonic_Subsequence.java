package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _44_Longest_Bitonic_Subsequence {
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
     * Longest Bitonic subsequence
     * Given an array of positive integers. Find the maximum length of Bitonic
     * subsequence.
     * A subsequence of array is called Bitonic if it is first strictly increasing,
     * then strictly decreasing. Return the maximum length of bitonic subsequence.
     * 
     * 
     * Input: n = 5, nums[] = [1, 2, 5, 3, 2]
     * Output: 5
     * Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is
     * decreasing so merging both we will get length 5.
     * 
     * Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
     * Output: 6
     * Explanation: The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.
     * 
     * 
     */

   
     // DP Optimized
    // T.C: O(N), O(1)
    // just check the difference between strings

    public static int Longest_Bitonic_Subsequence_DPOptimized_2(int[] arr, int n) {
        int dp[] = new int[n];

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        int ans_inc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
        }

        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(ans_inc<dp[i]){
                ans_inc=dp[i];
                maxIndex = i;
            }
        }

        // dp reset
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        
        // longest desreasing subseq
        int ans_dec = 0;
        for (int i = n-1; i > maxIndex; i--) {
            for (int j = n-1; j > i; j--) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
            ans_dec = Math.max(dp[i],ans_dec);
        }

        
        return ans_inc + ans_dec;
    }

    // Better Striver
    public static int Longest_Bitonic_Subsequence_DPOptimized_Striver(int[] arr, int n) {
        int dp_front[] = new int[n];

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp_front[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp_front[i] = Math.max(dp_front[i],dp_front[j]+1);
                }
            }
        }

        int dp_back[] = new int[n];

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp_back[i] = 1;
        }

        for (int i = n-1; i >=0; i--) {
            for (int j = n-1; j > i; j--) {
                if (arr[i] > arr[j]) {
                    dp_back[i] = Math.max(dp_back[i],dp_back[j]+1);
                }
            }
        }
        
        int ans=0;
        int bitonic[] = new int[n];
        for(int i=0;i<n;i++){
            bitonic[i] = dp_front[i] + dp_back[i] - 1;
            ans = Math.max(ans,bitonic[i]);
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = Longest_Bitonic_Subsequence_DPOptimized_2(arr, n);
        System.out.println("DP DPOptimized 2:" + ans);

        ans = Longest_Bitonic_Subsequence_DPOptimized_Striver(arr, n);
        System.out.println("DP DPOptimized 2:" + ans);

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
