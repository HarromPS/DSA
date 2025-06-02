package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _40_Longest_Increasing_Subsequence {
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
     * Given an integer array nums, return the length of the longest strictly
     * increasing subsequence.
     * 
     * Example 1:
     * 
     * Input: nums = [10,9,2,5,3,7,101,18]
     * Output: 4
     * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
     * length is 4.
     * 
     * another sequence is: 2 5 7 18 or 2 3 7 18
     * 
     * Example 2:
     * 
     * Input: nums = [0,1,0,3,2,3]
     * Output: 4
     * 
     * Example 3:
     * 
     * Input: nums = [7,7,7,7,7,7,7]
     * Output: 1
     * 
     * 
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Longest_Increasing_SubSeq_Recursion(int index, int prevMaxIndex_j, int[] arr, int n) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index < 0) {
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Increasing_SubSeq_Recursion(index - 1, index, arr, n);
            int notPick = 0 + Longest_Increasing_SubSeq_Recursion(index - 1, prevMaxIndex_j, arr, n);

            return Math.max(pick, notPick);
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Increasing_SubSeq_Recursion(index - 1, index, arr, n);
        }

        // dont pick
        int notPick = 0 + Longest_Increasing_SubSeq_Recursion(index - 1, prevMaxIndex_j, arr, n);

        ans = Math.max(pick, notPick);
        return ans;
    }

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Longest_Increasing_SubSeq_Recursion_Shifting_Index(int index, int prevMaxIndex_j, int[] arr,
            int n) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index == 0) {
            if (prevMaxIndex_j == n) {
                return 1;
            }
            if (arr[index] < arr[prevMaxIndex_j]) {
                return 1;
            }
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Increasing_SubSeq_Recursion_Shifting_Index(index - 1, index, arr, n);
            int notPick = 0 + Longest_Increasing_SubSeq_Recursion_Shifting_Index(index - 1, prevMaxIndex_j, arr, n);

            return Math.max(pick, notPick);
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Increasing_SubSeq_Recursion_Shifting_Index(index - 1, index, arr, n);
        }

        // dont pick
        int notPick = 0 + Longest_Increasing_SubSeq_Recursion_Shifting_Index(index - 1, prevMaxIndex_j, arr, n);

        ans = Math.max(pick, notPick);
        return ans;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Longest_Increasing_SubSeq_Memoization(int index, int prevMaxIndex_j, int[] arr, int n,
            int dp[][]) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index < 0) {
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Increasing_SubSeq_Memoization(index - 1, index, arr, n, dp);
            int notPick = 0 + Longest_Increasing_SubSeq_Memoization(index - 1, prevMaxIndex_j, arr, n, dp);

            dp[index][prevMaxIndex_j] = Math.max(pick, notPick);
            return dp[index][prevMaxIndex_j];
        }

        // check if previously solved or not
        if (dp[index][prevMaxIndex_j] != -1) {
            return dp[index][prevMaxIndex_j];
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Increasing_SubSeq_Memoization(index - 1, index, arr, n, dp);
        }

        // dont pick
        int notPick = 0 + Longest_Increasing_SubSeq_Memoization(index - 1, prevMaxIndex_j, arr, n, dp);

        ans = Math.max(pick, notPick);
        dp[index][prevMaxIndex_j] = ans;
        return ans;
    }

    public static int Longest_Increasing_SubSeq_Memoization_Shifting_Index(int index, int prevMaxIndex_j, int[] arr,
            int n, int dp[][]) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index == 0) {
            if (prevMaxIndex_j == n) {
                return 1;
            }
            if (arr[index] < arr[prevMaxIndex_j]) {
                return 1;
            }
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Increasing_SubSeq_Memoization_Shifting_Index(index - 1, index, arr, n, dp);
            int notPick = 0
                    + Longest_Increasing_SubSeq_Memoization_Shifting_Index(index - 1, prevMaxIndex_j, arr, n, dp);

            dp[index][prevMaxIndex_j] = Math.max(pick, notPick);
            return dp[index][prevMaxIndex_j];
        }

        // check if previously solved or not
        if (dp[index][prevMaxIndex_j] != -1) {
            return dp[index][prevMaxIndex_j];
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Increasing_SubSeq_Memoization_Shifting_Index(index - 1, index, arr, n, dp);
        }

        // dont pick
        int notPick = 0 + Longest_Increasing_SubSeq_Memoization_Shifting_Index(index - 1, prevMaxIndex_j, arr, n, dp);

        ans = Math.max(pick, notPick);
        dp[index][prevMaxIndex_j] = ans;
        return ans;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Longest_Increasing_SubSeq_Tabulation(int[] arr, int n) {

        int dp[][] = new int[n][n + 1];

        // base case
        // if (index ==0)
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                dp[0][j] = 1;
            } else if (arr[0] < arr[j]) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // last index
                if (j == n) {
                    int pick = 1 + dp[i - 1][i];
                    int nonPick = 0 + dp[i - 1][j];

                    dp[i][j] = Math.max(pick, nonPick);
                } else {
                    int pick = 0;
                    // check if can be picked
                    if (arr[i] < arr[j]) {
                        pick = 1 + dp[i - 1][i];
                    }
                    int nonPick = 0 + dp[i - 1][j];
                    dp[i][j] = Math.max(pick, nonPick);
                }
            }
        }

        return dp[n - 1][n];
    }

    // DP Optimized
    public static int Longest_Increasing_SubSeq_DPOptimized(int[] arr, int n) {

        int prev[] = new int[n + 1];

        // base case
        // if (index ==0)
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                prev[j] = 1;
            } else if (arr[0] < arr[j]) {
                prev[j] = 1;
            } else {
                prev[j] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) {
            int curr[] = new int[n+1];

            for (int j = i + 1; j <= n; j++) {
                // last index
                if (j == n) {
                    int pick = 1 + prev[i];
                    int nonPick = 0 + prev[j];

                    curr[j] = Math.max(pick, nonPick);
                } else {
                    int pick = 0;
                    // check if can be picked
                    if (arr[i] < arr[j]) {
                        pick = 1 + prev[i];
                    }
                    int nonPick = 0 + prev[j];
                    curr[j] = Math.max(pick, nonPick);
                }
            }
            // update prev
            prev = curr;
        }

        return prev[n];
    }

    // DP Optimized
    // T.C: O(N), O(1)
    public static int Longest_Increasing_SubSeq_DPOptimized_1(int[] arr, int n) {
        
        int prev[] = new int[n + 1];

        // base case
        // if (index ==0)
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                prev[j] = 1;
            } else if (arr[0] < arr[j]) {
                prev[j] = 1;
            } else {
                prev[j] = 0;
            }
        }

        // recurrence relation
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // last index
                if (j == n) {
                    int pick = 1 + prev[i];
                    int nonPick = 0 + prev[j];

                    prev[j] = Math.max(pick, nonPick);
                } else {
                    int pick = 0;
                    // check if can be picked
                    if (arr[i] < arr[j]) {
                        pick = 1 + prev[i];
                    }
                    int nonPick = 0 + prev[j];
                    prev[j] = Math.max(pick, nonPick);
                }
            }
        }

        return prev[n];
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = Longest_Increasing_SubSeq_Recursion(n - 1, n, arr, n);
        System.out.println("Brute Recursion:" + ans);

        int dp[][] = new int[n][n + 1];
        for (int rows[] : dp)
            Arrays.fill(rows, -1);

        ans = Longest_Increasing_SubSeq_Memoization(n - 1, n, arr, n, dp);
        System.out.println("DP Memoization:" + ans);

        ans = Longest_Increasing_SubSeq_Recursion_Shifting_Index(n - 1, n, arr, n);
        System.out.println("Brute Recursion Shifting_Index:" + ans);

        ans = Longest_Increasing_SubSeq_Memoization_Shifting_Index(n - 1, n, arr, n, dp);
        System.out.println("DP Memoization Shifting_Index:" + ans);

        ans = Longest_Increasing_SubSeq_Tabulation(arr, n);
        System.out.println("DP Tabulation:" + ans);

        ans = Longest_Increasing_SubSeq_DPOptimized(arr, n);
        System.out.println("DP DPOptimized:" + ans);

        ans = Longest_Increasing_SubSeq_DPOptimized_1(arr, n);
        System.out.println("DP DPOptimized 1:" + ans);
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
