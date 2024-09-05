package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _17_KnapSack_Problem {
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
    You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
    Note that we have only one quantity of each item.
    In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and Input:
    N = 3
    W = 4
    values[] = {1,2,3}
    weight[] = {4,5,1}
    Output: 3
    Explanation: Choose the last item that weighs 1 unit and holds a value of 3. weights associated with N items respectively. Also given an integer W which represents knapsack capacity, 
    find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
    You cannot break an item, either pick the complete item or dont pick it (0-1 property).

     */

    // Brute force: TLE T.C: O(2^n) S.C: (N)
    public static int KnapSack_Recursion_1(int index, int W, int value[], int weight[], int n,int maxValue) {
        // base case
        // if bag capaity gets full or index goes out of boundary
        if(W<=0 || index<0) {
            return maxValue;
        }

        // pick only if there is capicity in th bag
        int pick = 0;
        if(W-weight[index]>=0){
            pick = KnapSack_Recursion_1(index-1, W-weight[index], value, weight, n, maxValue+value[index]);
        }

        // not pick item
        int dontPick = KnapSack_Recursion_1(index-1, W, value, weight, n, maxValue);
        
        return Math.max(pick,dontPick);
    }

    public static int KnapSack_Recursion_2(int index, int W, int value[], int weight[], int n) {
        // base case
        // if bag capaity gets full or index goes out of boundary
        if(W<=0){
            return 0;
        }

        if(index==0){
            if(W-weight[0]>=0){
                return value[index];
            }else{
                return 0;
            }
        }

        // pick only if there is capicity in th bag
        int pick = 0;
        if(W-weight[index]>=0){
            pick = value[index] + KnapSack_Recursion_2(index-1, W-weight[index], value, weight, n);
        }

        // not pick item
        int dontPick = KnapSack_Recursion_2(index-1, W, value, weight, n);
        
        return Math.max(pick,dontPick);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(n x k), S.C: O(n x k)
    public static int KnapSack_Memoization_1(int index, int W, int value[], int weight[], int n,int maxValue, int dp[][]) {
         // base case
        // if bag capaity gets full or index goes out of boundary
        if(W<=0 || index<0) {
            return maxValue;
        }

        // check if the subproblem is already solved or not 
        if(dp[index][W]!=-1){
            return dp[index][W];
        }

        // pick only if there is capicity in th bag
        int pick = 0;
        if(W-weight[index]>=0){
            pick = KnapSack_Memoization_1(index-1, W-weight[index], value, weight, n, maxValue+value[index],dp);
        }

        // not pick item
        int dontPick = KnapSack_Memoization_1(index-1, W, value, weight, n, maxValue,dp);
        
        // save the calculation
        dp[index][W]=Math.max(pick,dontPick);
        return dp[index][W];
    }

    public static int KnapSack_Memoization_2(int index, int W, int value[], int weight[], int n, int dp[][]) {
        // base case
        // if bag capaity gets full or index goes out of boundary
        if(W<=0){
            return 0;
        }

        if(index==0){
            if(W-weight[0]>=0){
                return value[index];
            }else{
                return 0;
            }
        }

        if(dp[index][W]!=-1){
            return dp[index][W];
        }

        // pick only if there is capicity in th bag
        int pick = 0;
        if(W-weight[index]>=0){
            pick = value[index] + KnapSack_Memoization_2(index-1, W-weight[index], value, weight, n,dp);
        }

        // not pick item
        int dontPick = KnapSack_Memoization_2(index-1, W, value, weight, n,dp);
        
        // save the calculation
        dp[index][W]=Math.max(pick,dontPick);
        return dp[index][W];
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(n x k), S.C: O(n x k)
    public static int KnapSack_Tabulation(int W, int value[], int weight[], int n) {
        int dp[][] = new int[n][W+1];
        dp[0][0]=0;

        // base case
        // if bag weight is zero for any given item weight, value is zero
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }

        // base case if index==0
        for(int i=weight[0];i<W+1;i++){
            // if(W-weight[i]>=0){
            //     dp[0][i]=value[0];
            // }else{
            //    0 dp[0][i]=0;
            // }
            dp[0][i]=value[0];
        }

        // recurrence relation
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                // pick 
                int pick = 0;
                if(j - weight[i]>=0){
                    pick = value[i] + dp[i-1][j-weight[i]];
                }

                // dont pick
                int dontpick = 0 + dp[i-1][j];

                dp[i][j] = Math.max(pick,dontpick);
            }
        }
        return dp[n-1][W];
    }

    // DP optimized
    // T.C: O(n x k), S.C:O(1)
    public static int KnapSack_DPOptimized(int W, int value[], int weight[], int n) {
        int prev[] = new int[W+1];
        // base case
        // if bag weight is zero for any given item weight, value is zero
        prev[0]=0;

        // base case if index==0
        for(int i=weight[0];i<W+1;i++){
            prev[i]=value[0];
        }

        // recurrence relation
        for(int i=1;i<n;i++){
            int curr[] = new int[W+1];
            for(int j=0;j<=W;j++){
                // pick 
                int pick = 0;
                if(j - weight[i]>=0){
                    pick = value[i] + prev[j-weight[i]];
                }

                // dont pick
                int dontpick = 0 + prev[j];

                curr[j] = Math.max(pick,dontpick);
            }
            // update previous row
            prev = curr;
        }
        return prev[W];
    }

    public static int KnapSack_DPOptimized_2(int W, int value[], int weight[], int n) {
        int prev[] = new int[W+1];
        // base case
        // if bag weight is zero for any given item weight, value is zero
        prev[0]=0;

        // base case if index==0
        for(int i=weight[0];i<W+1;i++){
            prev[i]=value[0];
        }

        // recurrence relation
        for(int i=1;i<n;i++){
            // we can run from maxWeight 
            // as currRow gets values from j-weight[i]
            // we can store calculated values in prev [j]
            for(int j=W;j>=0;j--){
                // pick 
                int pick = 0;
                if(j - weight[i]>=0){
                    pick = value[i] + prev[j-weight[i]];
                }

                // dont pick
                int dontpick = 0 + prev[j];

                prev[j] = Math.max(pick,dontpick);
            }
        }
        return prev[W];
    }


    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int w = sc.nextInt();

        // same question
        int val[] = new int[n];
        int weight[] = new int[n];
        for (int j = 0; j < n; j++) {
            int r = sc.nextInt();
            val[j] = r;
            r=sc.nextInt();
            weight[j]=r;
        }

        // try all ways
        // initial state: solve(0, 0, n-1) row 0th, 1st cell and last cell
        int ans = KnapSack_Recursion_1(n-1,w,val,weight,n,0 );
        System.out.println("Brute force 1: " + ans);

        ans = KnapSack_Recursion_2(n-1,w,val,weight,n);
        System.out.println("Brute force 2: " + ans);

        int dp[][] = new int[n][w + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                dp[i][j] = -1;

            }
        }

        ans = KnapSack_Memoization_1(n-1,w,val,weight,n,0,dp);
        System.out.println("DP Memoization:" + ans);

        ans = KnapSack_Memoization_2(n-1,w,val,weight,n, dp);
        System.out.println("DP Memoization:" + ans);

        ans = KnapSack_Tabulation(w,val,weight,n);
        System.out.println("DP Tabulation:" + ans);

        ans = KnapSack_DPOptimized(w,val,weight,n);
        System.out.println("DP Optimized 1:" + ans);

        ans = KnapSack_DPOptimized_2(w,val,weight,n);
        System.out.println("DP Optimized 2:" + ans);
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
