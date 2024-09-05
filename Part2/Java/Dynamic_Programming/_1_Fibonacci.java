package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _1_Fibonacci {
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

    // Brute force: O(2^(n-1))
    public static int fibRecursion(int n){
        if(n<=1) return n;
        return fibRecursion(n-1) + fibRecursion(n-2);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(N), S.C: O(N)+O(N) -> recursive stack

    public static int fib(int n, ArrayList<Integer> dp){
        // base case 
        if(n<=1) {
            return n;
        }

        // step 3: dont solve subproblems, 1st check if it is already solved
        if(dp.get(n)!=-1){

            // then return solved value
            return dp.get(n);
        }

        // step 2: store value of subproblem computed (this step converts recursion to memoization)
        int res = fib(n-1, new ArrayList<>(dp)) + fib(n-2, new ArrayList<>(dp));
        dp.set(n, res);

        return dp.get(n);
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(N), S.C: O(N)
    public static int fibTabulation(int n){
        if(n<=1) return n;
        int dp[] = new int[n+1];


        // base case
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<n+1;i++){

            // recurrence relation
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    // DP optimized
    // T.C: O(N), S.C: O(1)

    public static int fibDPOptimized(int n){
        // using 2 variables

        if(n<=1) return n;

        int prev=1;
        int prev2=0;
        int next=0;
        for(int i=2;i<=n;i++){
            next = prev + prev2;
            prev2 = prev;
            prev = next;
        }
        return next;
    }
    public static void solve(FastReader sc) {
        
        // DP: 1. Memoization technique -> where we store the values of the subproblems calculated during recursion 
        
        // Step 1: create a storage to store subproblem values -> Max of N where we solve highest subproblem

        int n=0;
        n = sc.nextInt();
        ArrayList<Integer> dp = new ArrayList<>();

        // initialize storage for == n 
        for(int i=0;i< (n+1) ;i++) dp.add(-1);    // initially -1

        int res = fib(n, new ArrayList<>(dp));

        System.out.println("Brute force: "+fibRecursion(n));
        System.out.println("DP Memoization: "+res);
        System.out.println("DP Tabulation: "+fibTabulation(n));
        System.out.println("DP Optimized: "+fibDPOptimized(n));


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