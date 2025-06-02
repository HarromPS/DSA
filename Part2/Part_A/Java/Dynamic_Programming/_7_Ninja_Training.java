package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _7_Ninja_Training {
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
    - Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (
    - Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day.
    - As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
    - Can you help Ninja find out the maximum merit points Ninja can earn?

    You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
    Your task is to calculate the maximum number of merit points that Ninja can earn.

    For Example: 
    Input: nums = [
                        [10 50 1]
                        [5 100 11]
                   ]
    Output: 110

    1st day -> choose 10 (index 0) activity
    2nd day -> choose 100 (index 1) activity [cannot choose index 0 as already chose previous day, but can choose on 3rd day]
    */

    // Brute force: T.C:O(n x m), S.C: O(N) recursive stack 
    public static int NinjaTrainingRecursion_1(int matrix[][],int NextDayMeritIndex,int prevDayMeritIndex){
        // base case
        if(NextDayMeritIndex >= matrix.length){
            return 0;
        }

        // iterate through all activities and check max merit point and it is not same activity as previous day

        int m = matrix[0].length;
        int currentDayIndex = NextDayMeritIndex;
        int maxMerit = Integer.MIN_VALUE;

        for(int activity=0;activity<m;activity++){
            // check max merit 
            if(activity!=prevDayMeritIndex){
                // Recursively calculate the merit points with current Day merit & the next days
                int merit = matrix[currentDayIndex][activity] + NinjaTrainingRecursion_1(matrix, currentDayIndex + 1, activity);
                // Update the maximum merit points
                maxMerit = Math.max(maxMerit, merit);
            }
        }
        return maxMerit;
    }
        
    // DP: better-> Memoization (required answer to base case then back)
    // Striver method-> (N-1) to 0
    public static int NinjaTrainingMemoization(int matrix[][],int currentDayIndex,int lastDayIndex,int dp[][]){

        // base case
        if(currentDayIndex==0){
            // return the max merit except last day activity
            int maxMerit = Integer.MIN_VALUE;
            for(int activity = 0;activity<3;activity++){
                if(activity!=lastDayIndex){ // if activity is not done on last day
                    maxMerit=Math.max(maxMerit, matrix[currentDayIndex][activity]);
                }
            }
            return maxMerit;
        }

        // check if value is already calculated
        if(dp[currentDayIndex][lastDayIndex]!=-1){
            return dp[currentDayIndex][lastDayIndex];
        }

        // if not first day
        int maxMerit = Integer.MIN_VALUE;
        for(int activity=0;activity<3;activity++){
            if(activity!=lastDayIndex){ 
                int merit = matrix[currentDayIndex][activity] + NinjaTrainingMemoization(matrix, currentDayIndex-1, activity,dp);
                maxMerit = Math.max(maxMerit,merit);
            }
        }

        // store calculated merit score
        dp[currentDayIndex][lastDayIndex]=maxMerit;
        return maxMerit;
    }

    // DP Tabulation-> base case to required answer
    public static int NinjaTrainingTabulation(int arr[][]){
        int n = arr.length;
        int dp[][] = new int[n][4];
        
        // base case, cuurent day 0
        (dp[0][0]) = Math.max(arr[0][1],arr[0][2]);
        (dp[0][1]) = Math.max(arr[0][0],arr[0][2]);
        (dp[0][2]) = Math.max(arr[0][0],arr[0][1]);
        (dp[0][3]) = Math.max(arr[0][0], Math.max(arr[0][1],arr[0][2]));

        // if it is not a base case -> start from day 1 till n-1 
        for(int currentDay=1;currentDay<n;currentDay++){
            // last day -> height of recursive tree
            for(int lastDay=0;lastDay<4;lastDay++){

                dp[currentDay][lastDay]=0;
                for(int activity=0;activity<3;activity++){
                    if(activity!=lastDay){
                        int merit = arr[currentDay][activity] + (dp[currentDay-1][activity]);
                        (dp[currentDay][lastDay]) = Math.max((dp[currentDay][lastDay]),merit);
                    }
                }
            }
        }
        return (dp[n-1][3]);
    }

    // DP optimized
    public static int NinjaTrainingDPOptimized(int arr[][]){
        int n = arr.length;

        int dp[][] = new int[2][4];
        
        // base case, cuurent day 0
        (dp[0][0]) = Math.max(arr[0][1],arr[0][2]);
        (dp[0][1]) = Math.max(arr[0][0],arr[0][2]);
        (dp[0][2]) = Math.max(arr[0][0],arr[0][1]);
        (dp[0][3]) = Math.max(arr[0][0], Math.max(arr[0][1],arr[0][2]));

        // base case, if there is only one day
        if(n==1){
            return dp[0][3];
        }

        // if it is not a base case -> start from day 1 till n-1 
        for(int currentDay=1;currentDay<n;currentDay++){
            // last day -> height of recursive tree
            for(int lastDay=0;lastDay<4;lastDay++){
                dp[1][lastDay]=0;

                for(int activity=0;activity<3;activity++){
                    if(activity!=lastDay){
                        int merit = arr[currentDay][activity] + (dp[0][activity]);
                        (dp[1][lastDay]) = Math.max((dp[1][lastDay]),merit);
                        
                    }
                }
            }
            // update the two variables 
            for(int i=0;i<4;i++){
                dp[0][i] = dp[1][i];
            }
        }
        return (dp[1][3]);        
    }
    

    public static void solve(FastReader sc) {
        int n=sc.nextInt();
        int m=3;

       int arr[][] = new int[n][3];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                arr[i][j] = sc.nextInt();
            }
        }       

        int maxMerit=Integer.MIN_VALUE;
        // for(int i=0;i<m;i++){
        //     // get merit from day 1
        //     maxMerit = Math.max(NinjaTrainingRecursion_1(arr, 1, i)+arr[0][i],maxMerit);
        // }
        // System.out.println("\nBrute Force 1: " +maxMerit);
        
        int dp[][] = new int[n][m+1];
        for(int i=0;i<n;i++) {
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }

        
        // maxMerit = NinjaTrainingMemoization(arr, n-1, 3, dp);
        // System.out.println("DP Memoization:"+maxMerit);
        
        // maxMerit = NinjaTrainingTabulation(arr);
        // System.out.println("DP Tabulation:"+maxMerit);
        
        maxMerit = NinjaTrainingDPOptimized(arr);
        System.out.println("DP Optimized:"+maxMerit);
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

