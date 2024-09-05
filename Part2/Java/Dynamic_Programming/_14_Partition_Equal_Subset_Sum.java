package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _14_Partition_Equal_Subset_Sum {
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
     * You are given an array 'arr' containing 'n' non-negative integers.
     * 
     * Your task is to partition this array into two subsets such that the absolute
     * difference between subset sums is minimum.
     * 
     * You just need to find the minimum absolute difference considering any valid
     * division of the array elements.
     * 
     * Input:
     * N = 4
     * arr[] = {1,2,3,4}
     * Output: 10
     * Explanation: Here there exists a subset with
     * abs( {1,4} - {2,3} ) => 0
     * 
     */

    // public static int ans = (int)1e8;
    // Brute force: TLE T.C: O(2^n) S.C: (N)
    // public static int partitionSubsetSumRecursion_1(int index, int arr[], int
    // sum, int n,int total) {
    // // base cases
    // if (index == 0){
    // // get the min abs difference of the sum
    // // System.out.print(Math.abs(sum-(total-sum))+" ");
    // ans = Math.min(ans, Math.abs(sum-(total-sum)));
    // return ans;
    // }

    // if(index<0){
    // return (int)1e8;
    // }

    // // generate subsequences
    // // pick
    // sum = sum + arr[index];
    // int leftMin = partitionSubsetSumRecursion_1(index - 1, arr, sum, n, total);

    // // dont pick
    // sum = sum - arr[index];
    // int rightMin = partitionSubsetSumRecursion_1(index - 1, arr, sum, n, total);

    // return Math.min(leftMin, rightMin);
    // }

    // // DP: better-> Memoization (required answer to base case then back)
    // // T.C: O(n x k), S.C: O(n x k)
    // public static int partitionSubsetSumMemoization(int index, int arr[], int
    // sum, int n,int total, int dp[][]) {
    // if (index == 0){
    // // get the min abs difference of the sum
    // // System.out.print(Math.abs(sum-(total-sum))+" ");
    // ans = Math.min(ans, Math.abs(sum-(total-sum)));
    // return ans;
    // }

    // if(index<0){
    // return (int)1e8;
    // }

    // if(dp[index][sum]!=-1){
    // return dp[index][sum];
    // }
    // // generate subsequences
    // // pick
    // sum = sum + arr[index];
    // int leftMin = partitionSubsetSumRecursion_1(index - 1, arr, sum, n, total);

    // // dont pick
    // sum = sum - arr[index];
    // int rightMin = partitionSubsetSumRecursion_1(index - 1, arr, sum, n, total);

    // dp[index][sum] = Math.min(leftMin, rightMin);
    // return dp[index][sum];

    // }

    public static boolean partitionSubsetSumRecursion_1_Striver(int index, int target, int arr[], int n) {
        // base cases
        // if case satisfies condition
        if (target == 0) {
            return true;
        }

        if (index >= n || target < 0) {
            return false;
        }

        // generate subsequences

        // pick
        target = target - arr[index];
        boolean r = partitionSubsetSumRecursion_1_Striver(index + 1, target, arr, n);

        if (r == true)
            return true;

        // dont pick
        target = target + arr[index];
        r = partitionSubsetSumRecursion_1_Striver(index + 1, target, arr, n);
        if (r == true)
            return true;

        return false;
    }

    public static boolean partitionSubsetSum_Memoization_Striver(int index, int target, int arr[], int n) {
        // base cases
        // if case satisfies condition
        if (target == 0) {
            return true;
        }

        if (index >= n || target < 0) {
            return false;
        }

        // generate subsequences

        // pick
        target = target - arr[index];
        boolean r = partitionSubsetSumRecursion_1_Striver(index + 1, target, arr, n);

        if (r == true)
            return true;

        // dont pick
        target = target + arr[index];
        r = partitionSubsetSumRecursion_1_Striver(index + 1, target, arr, n);
        if (r == true)
            return true;

        return false;
    }

    public static boolean subsetSumMemoization(int index, int target, int arr[], int n, int dp[][]) {

        // base cases
        // if case satisfies condition
        if (target == 0) {
            return true;
        }

        if (index == 0){
            return (arr[0] == target);
        }

        if (index < 0 || target < 0) {
            return false;
        }

        // check if prevoiusly calculated
        if (dp[index][target] != -1) {
            return (dp[index][target] == 0 ? false : true);
        }

        // generate subsequences
        // pick
        // dont pick
        boolean dontPick = subsetSumMemoization(index - 1, target, arr, n, dp);
        
        boolean pick=false;
        if (arr[index] <= target){
            pick = subsetSumMemoization(index - 1, target-arr[index], arr, n, dp);
        }

        dp[index][target] = (pick || dontPick) ? 1 : 0;

        return pick || dontPick;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static boolean subsetSumTabulation(int arr[], int n, int target) {
        int dp[][] = new int[n][target + 1];
        // base case

        // initially whole dp is false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0; // false
            }
        }

        // if target = 0, possible value of i is 0 to n-1
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // when only 1st element is considered, 2 ways, either is equal to target
        // or is included in subsequence, so index == 0, if arr[0]<=target return true
        if (arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        // start from index 1 till n
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // pick
                boolean pick = false;
                if (j - arr[i] >= 0) {
                    pick = (dp[i - 1][j - arr[i]] == 1 ? true : false);
                }
                boolean nonPick = (dp[i - 1][j] == 1 ? true : false);
                dp[i][j] = (pick || nonPick == true ? 1 : 0);
            }
        }
        return (dp[n - 1][target] == 1 ? true : false);

    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int[] subsetSumDPOptimized(int arr[], int n, int k) {
        // we only need 2 arrays to keep track of
        // previous and current

        int prev[] = new int[k + 1];

        // base case if target is 0
        prev[0] = 1;

        // start from 0 th index, 1st element
        for (int index = 0; index < n; index++) {
            // current row i.e when i==0 base case, if arr[0]<=target curr[arr[0]] = 1;
            int currRow[] = new int[k + 1];
            currRow[0] = 1;
            for (int target = 0; target <= k; target++) {
                // 1st row, 1st element is considered
                if (index == 0) {
                    // if 1st element is equal to target -> (index,target) = true
                    // if arr[0] <= target, means it is included in subsequence
                    if (arr[0] <= k) {
                        currRow[arr[0]] = 1;
                    }
                } else {
                    // copy paste recurrence relation
                    boolean pick = false;
                    if (target - arr[index] >= 0) {
                        pick = (prev[target - arr[index]] == 1 ? true : false);
                    }

                    boolean nonPick = (prev[target] == 1 ? true : false);
                    currRow[target] = (pick || nonPick == true ? 1 : 0);
                }
            }
            // update previous row
            prev = currRow;
        }
        
        // return (prev[k] == 1 ? true : false);
        System.out.println(prev[k] == 1 ? true : false);
        return prev;       
    }

    public static int partitionSumOptimized(int arr[],int total,int dp[],int n){
        // find possible sums i.e all the subset sums s1 which are possible between 0 to total 
        // find correponding s2, remaining elements sum from (abs(total-s1)) 
        // find min abs sum between s1 and s2
        
        int ans = (int)1e8;
        for(int i=0;i<=total;i++){
            if(dp[i]==1){
                int s1 = i;
                int s2 = Math.abs(total-s1);
                ans = Math.min(ans, Math.abs(s1-s2));
            }
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        // int k = sc.nextInt();

        int total = 0;
        int arr[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            arr[j] = r;
            total += r;
        }
        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        // int res = partitionSubsetSumRecursion_1(n-1, arr, 0,n,total);
        // System.out.println("Brute force: " + ans+" "+res);

        // ans=partitionSubsetSumMemoization(n-1, arr, 0,n,total,dp);
        // System.out.println("DP Memoization:"+ans);

        // boolean r = partitionSubsetSumRecursion_1_Striver(0, total, arr, n);
        // System.out.println("Brute force Striver:" + r);
        
        // r = partitionSubsetSum_Memoization_Striver(0, total, arr, n);
        // System.out.println("\nDP Memoization Striver:" + r);

        int dp[][] = new int[n + 1][total + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= total; j++) {
                dp[i][j] = -1;

            }
        }

        boolean ans = subsetSumMemoization(n-1,total,arr,n,dp);
        System.out.println("DP Memoization:"+ans);

        ans = subsetSumTabulation(arr,n,total);
        System.out.println("DP Tabulation:" + ans);

        dp[n-1] = subsetSumDPOptimized(arr, n, total);
        System.out.println("DP Optimized:" + ans);

        int res = partitionSumOptimized(arr,total,dp[n-1],n);
        System.out.println("Min Abs Diff: "+res);
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
