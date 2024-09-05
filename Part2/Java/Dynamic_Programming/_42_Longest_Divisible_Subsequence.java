package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _42_Longest_Divisible_Subsequence {
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
     * Largest Divisible Subset

     * Given a set of distinct positive integers nums, return the largest subset
     * answer such that every pair (answer[i], answer[j]) of elements in this subset
     * satisfies:
     * 
     * answer[i] % answer[j] == 0, or
     * answer[j] % answer[i] == 0
     * 
     * If there are multiple solutions, return any of them.
     * 
     * 
     * 
     * Example 1:
     * 
     * Input: nums = [1,2,3]
     * Output: [1,2]
     * Explanation: [1,3] is also accepted.
     * 
     * Example 2:
     * 
     * Input: nums = [1,2,4,8]
     * Output: [1,2,4,8]
     * 
     */

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Longest_Divisible_SubSeq_Recursion(int index, int prevMaxIndex_j, int[] arr, int n) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index < 0) {
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Divisible_SubSeq_Recursion(index - 1, index, arr, n);
            int notPick = 0 + Longest_Divisible_SubSeq_Recursion(index - 1, prevMaxIndex_j, arr, n);

            return Math.max(pick, notPick);
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Divisible_SubSeq_Recursion(index - 1, index, arr, n);
        }

        // dont pick
        int notPick = 0 + Longest_Divisible_SubSeq_Recursion(index - 1, prevMaxIndex_j, arr, n);

        ans = Math.max(pick, notPick);
        return ans;
    }

    // Brute force: Recursive ways
    // T.C: O(N^2), S.C:(N)
    public static int Longest_Divisible_SubSeq_Recursion_Shifting_Index(int index, int prevMaxIndex_j, int[] arr,
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
            int pick = 1 + Longest_Divisible_SubSeq_Recursion_Shifting_Index(index - 1, index, arr, n);
            int notPick = 0 + Longest_Divisible_SubSeq_Recursion_Shifting_Index(index - 1, prevMaxIndex_j, arr, n);

            return Math.max(pick, notPick);
        }

        int ans = 0;
        // recurrence relation
        // iterate to all the subsequences

        // check first if we can pick it up
        int pick = 0;
        if (arr[index] < arr[prevMaxIndex_j]) {
            pick = 1 + Longest_Divisible_SubSeq_Recursion_Shifting_Index(index - 1, index, arr, n);
        }

        // dont pick
        int notPick = 0 + Longest_Divisible_SubSeq_Recursion_Shifting_Index(index - 1, prevMaxIndex_j, arr, n);

        ans = Math.max(pick, notPick);
        return ans;
    }

    // DP Memoization
    // T.C: O(N), S.C:(N+N)
    public static int Longest_Divisible_SubSeq_Memoization(int index, int prevMaxIndex_j, int[] arr, int n,
            int dp[][]) {
        // we have to find a strictly increasing subsequence

        // base case
        if (index < 0) {
            return 0;
        }

        if (prevMaxIndex_j == n) {
            // picking last or not, as last index will be MAX
            int pick = 1 + Longest_Divisible_SubSeq_Memoization(index - 1, index, arr, n, dp);
            int notPick = 0 + Longest_Divisible_SubSeq_Memoization(index - 1, prevMaxIndex_j, arr, n, dp);

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
            pick = 1 + Longest_Divisible_SubSeq_Memoization(index - 1, index, arr, n, dp);
        }

        // dont pick
        int notPick = 0 + Longest_Divisible_SubSeq_Memoization(index - 1, prevMaxIndex_j, arr, n, dp);

        ans = Math.max(pick, notPick);
        dp[index][prevMaxIndex_j] = ans;
        return ans;
    }

    public static int Longest_Divisible_SubSeq_Memoization_Shifting_Index(int index, int prevMaxIndex_j, int[] arr,
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
            int pick = 1 + Longest_Divisible_SubSeq_Memoization_Shifting_Index(index - 1, index, arr, n, dp);
            int notPick = 0
                    + Longest_Divisible_SubSeq_Memoization_Shifting_Index(index - 1, prevMaxIndex_j, arr, n, dp);

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
            pick = 1 + Longest_Divisible_SubSeq_Memoization_Shifting_Index(index - 1, index, arr, n, dp);
        }

        // dont pick
        int notPick = 0 + Longest_Divisible_SubSeq_Memoization_Shifting_Index(index - 1, prevMaxIndex_j, arr, n, dp);

        ans = Math.max(pick, notPick);
        dp[index][prevMaxIndex_j] = ans;
        return ans;
    }

    // DP Tabulation
    // T.C: O(N), S.C:(N+N)
    public static int Longest_Divisible_SubSeq_Tabulation(int[] arr, int n) {

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
    public static int Longest_Divisible_SubSeq_DPOptimized(int[] arr, int n) {

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
            int curr[] = new int[n + 1];

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
    public static int Longest_Divisible_SubSeq_DPOptimized_1(int[] arr, int n) {

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

    public static int Longest_Divisible_SubSeq_DPOptimized_2(int[] arr, int n) {

        int dp[] = new int[n];
        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            int curr = dp[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0) {
                    curr = Math.max(curr, dp[i] + dp[j]);
                }
            }
            // update dp
            dp[i] = curr;
        }

        // traverse and find longest length
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[i]);
        }

        ///////////////////////////////////////////////////////

        // Sort it first 
        Arrays.sort(arr);

        int dp_2[] = new int[n];
        int prevIndex[] = new int[n];

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp_2[i] = 1;
            prevIndex[i] = -1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] % arr[j]) ==0 && dp_2[i] < dp_2[j] + 1) {
                    dp_2[i] = dp_2[j] + 1;
                    prevIndex[i] = j;
                }
            }
        }

        // track traverse

        ans = 0;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp_2[i] > ans) {
                ans = dp_2[i];
                lastIndex = i;
            }
        }

        // for(Integer it:prevIndex){
        // System.out.print(it+" ");
        // }
        // System.out.println();

        Stack<Integer> stack = new Stack<>();

        // print the sequence in index lexicographical order
        while (lastIndex != -1) {
            stack.push(arr[lastIndex]);
            lastIndex = prevIndex[lastIndex];
        }

        System.out.println("Longest Divisible Subsequence: ");

        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
        System.out.println();

        return ans;
    }

    public static int lower_bound(int arr[], int key) {
        int n = arr.length;
        int l = 0, h = n - 1;
        while (l < h) {
            int mid = (l + h) / 2;
            if (key <= arr[mid]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        // if key > n (means it is not present) return n
        // if key < 0 (means it is not present) return 0
        if (l < n && key > arr[l]) {
            l++;
        }
        return l;
    }

    public static int Longest_Divisible_SubSeq_DPOptimized_Binary_Search(int[] arr, int n) {
        // intution is to get only the length of the longest increasing subsequence

        // sort it before
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.get(temp.size() - 1)) {
                temp.add(arr[i]);
            } else {
                // find the place where we can place the element such that increasing sequence
                // is formed
                int index = lower_bound(arr, arr[i]);
                temp.add(arr[index]);
            }
        }
        return temp.size();
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // int ans = Longest_Divisible_SubSeq_Recursion(n - 1, n, arr, n);
        // System.out.println("Brute Recursion:" + ans);

        // int dp[][] = new int[n][n + 1];
        // for (int rows[] : dp)
        //     Arrays.fill(rows, -1);

        // ans = Longest_Divisible_SubSeq_Memoization(n - 1, n, arr, n, dp);
        // System.out.println("DP Memoization:" + ans);

        // ans = Longest_Divisible_SubSeq_Recursion_Shifting_Index(n - 1, n, arr, n);
        // System.out.println("Brute Recursion Shifting_Index:" + ans);

        // ans = Longest_Divisible_SubSeq_Memoization_Shifting_Index(n - 1, n, arr, n, dp);
        // System.out.println("DP Memoization Shifting_Index:" + ans);

        // ans = Longest_Divisible_SubSeq_Tabulation(arr, n);
        // System.out.println("DP Tabulation:" + ans);

        // ans = Longest_Divisible_SubSeq_DPOptimized(arr, n);
        // System.out.println("DP DPOptimized:" + ans);

        // ans = Longest_Divisible_SubSeq_DPOptimized_1(arr, n);
        // System.out.println("DP DPOptimized 1:" + ans);

        int ans = Longest_Divisible_SubSeq_DPOptimized_2(arr, n);
        System.out.println("DP DPOptimized 2:" + ans);

        // ans = Longest_Divisible_SubSeq_DPOptimized_Binary_Search(arr, n);
        // System.out.println("DP DPOptimized Binary Search 3:" + ans);
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
