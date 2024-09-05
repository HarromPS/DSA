package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _2_Climbing_Stairs {
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
    
    You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
    Each time, you can climb either one step or two steps.
    You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

   
     */

    // Brute force: O(2^(n-1))
    public static void climbingStairsRecursion_1(int n){
        if(n==0) {
            count++;
            return;
        }
        if(n<0) return;
        climbingStairsRecursion_1(n-1);
        climbingStairsRecursion_1(n-2);
    }

    // Brute force: O(2^(n-1))
    public static int climbingStairsRecursion_2(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        return climbingStairsRecursion_2(n-1) + climbingStairsRecursion_2(n-2);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(N), S.C: O(N)+O(N) -> recursive stack

    public static int climbingStairs(int n, ArrayList<Integer> dp){
        // base case 
        if(n==0) {
            return 1;
        }

        // if steps go beyond 
        if(n<0) return 0;

        // step 3: dont solve subproblems, 1st check if it is already solved
        if(dp.get(n)!=-1){

            // then return solved value
            return dp.get(n);
        }

        // step 2: store value of subproblem computed (this step converts recursion to memoization)
        int res = climbingStairs(n-1, new ArrayList<>(dp)) + climbingStairs(n-2, new ArrayList<>(dp));
        dp.set(n, res);

        return dp.get(n);
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(N), S.C: O(N)
    public static int climbingStairsTabulation(int n){
        if(n<=1) return 1;
        int dp[] = new int[n+1];


        // base case
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<n+1;i++){
            // recurrence relation
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    // DP optimized
    // T.C: O(N), S.C: O(1)

    public static int climbingStairsDPOptimized(int n){
        // using 2 variables

        if(n<=1) return 1;

        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int next = prev + prev2;
            prev2 = prev;
            prev = next;
        }
        return prev;
    }
    public static void solve(FastReader sc) {
        
        // DP: 1. Memoization technique -> where we store the values of the subproblems calculated during recursion 
        
        // Step 1: create a storage to store subproblem values -> Max of N where we solve highest subproblem

        int n=0;
        n = sc.nextInt();
        ArrayList<Integer> dp = new ArrayList<>();

        // initialize storage for == n 
        for(int i=0;i< (n+1) ;i++) dp.add(-1);    // initially -1

        int res = climbingStairs(n, new ArrayList<>(dp));

        climbingStairsRecursion_1(n);
        System.out.println("Brute force method 1: "+count);
        System.out.println("Brute force method 2: "+climbingStairsRecursion_2(n));
        System.out.println("DP Memoization: "+res);
        System.out.println("DP Tabulation: "+climbingStairsTabulation(n));
        System.out.println("DP Optimized: "+climbingStairsDPOptimized(n));
        
        
    }
    public static int count=0;

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
