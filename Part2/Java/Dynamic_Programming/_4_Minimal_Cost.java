package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _4_Minimal_Cost {
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
    - There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: 
    - Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on.
    - Find the minimum possible total cost incurred before the Geek reaches Stone n.

     e.g Examples :
        Input: n = 5, k = 3 heights = {10, 30, 40, 50, 20}
        Output: 30
        Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
     */

    // Brute force: O(n^2)  => collect all the energies then compare the minimum energy
    public static void minimalCostRecursion_1(ArrayList<Integer> minCost, int currCost,int n,ArrayList<Integer> heights,int k){

        // base case
        if(n<=0) {
            minCost.add(currCost);
            return;
        }

        for(int i=1;i<=k;i++){
            // if jump on ist stone
            if(n-i>=0){
                int jumpCost = currCost+Math.abs(heights.get(n)-heights.get(n-i));
                minimalCostRecursion_1(minCost, jumpCost, n-i, new ArrayList<>(heights),k);
            }         
        }        
    }
    
    // Brute force: O(2^(n-1))
    public static int minimalCostRecursion_2(int currCost,int n,ArrayList<Integer> heights,int k){

        // base case
        if(n<=0) {
            return currCost;
        }

        int ans = Integer.MAX_VALUE;
        for(int i=1;i<=k;i++){
            // if jump on ist stone and we do not jump beyond the beginning of array
            if(n-i>=0){
                int jumpCost = currCost+Math.abs(heights.get(n)-heights.get(n-i));
                ans = Math.min(ans, minimalCostRecursion_2(jumpCost, n-i, heights,k));
            }         
        }
        return ans;
    }

    
    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(N), S.C: O(N)+O(N) -> recursive stack

    public static int minimalCost(int currCost, int n, ArrayList<Integer> dp, ArrayList<Integer> heights,int k){
        // base case 
        if(n<=0) {
            return currCost;
        }

        // step 3: dont solve subproblems, 1st check if it is already solved
        if(dp.get(n)!=-1){

            // then return solved value
            return dp.get(n);
        }

        // step 2: store value of subproblem computed (this step converts recursion to memoization)
        int ans = Integer.MAX_VALUE;
        for(int i=1;i<=k;i++){
            // if jump on ist stone and we do not jump beyond the beginning of array
            if(n-i>=0){
                int jumpCost = currCost+Math.abs(heights.get(n)-heights.get(n-i));
                ans = Math.min(ans, minimalCost(jumpCost, n-i, new ArrayList<>(dp), heights,k));
            }         
        }
        dp.set(n, ans);
        return ans;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(N), S.C: O(N), reduced recursive call stack extra space 
    public static int minimalCostTabulation(int n, ArrayList<Integer> heights,int k){
        
        int dp[] = new int[n+1];

        // base case
        // 1st stair cost is 0 as, man hasn't made any jump
        dp[0]=0;

        
        // start calculaing cost from 1st stair
        for(int i=1;i<n;i++){
            // recurrence relation
            
            int ans = Integer.MAX_VALUE;
            for(int j=1;j<=k;j++){
                if(i - j >=0){
                    int jumpCost = dp[i-j] + Math.abs(heights.get(i) - heights.get(i-j));
                    ans = Math.min(ans, jumpCost);
                }
            }
            // store the calculated cost
            dp[i] = ans;
        }
        return dp[n-1];
    }

    // DP optimized
    // T.C: O(N), S.C: O(1)

    public static int minimalCostDPOptimized(int n, ArrayList<Integer> heights){
        // using 2 variables

        if(n<=1) return 0;

        // base case: assuming at least 2 stair
        int secondStairEnergyLoss = 0;      // 0th index stair
        int prevStairEnergyLoss = Math.abs(heights.get(1)-heights.get(0));  // 1st index stair

        for(int i=2;i<n;i++){
            int currentStairEnergyLoss = Math.min(prevStairEnergyLoss + Math.abs(heights.get(i) - heights.get(i-1)), secondStairEnergyLoss + Math.abs(heights.get(i) - heights.get(i-2)) );
           secondStairEnergyLoss = prevStairEnergyLoss;
           prevStairEnergyLoss = currentStairEnergyLoss;
        }
        return prevStairEnergyLoss;
    }
    public static void solve(FastReader sc) {
        
        // DP: 1. Memoization technique -> where we store the values of the subproblems calculated during recursion 
        
        // Step 1: create a storage to store subproblem values -> Max of N where we solve highest subproblem

        int n=sc.nextInt();
        int k=sc.nextInt();

        ArrayList<Integer> heights = new ArrayList<>();
        for(int i=0;i<n;i++) {
            int h = sc.nextInt();
            heights.add(h);
        }        
        
        ArrayList<Integer> minCosts = new ArrayList<>();
        int ans=Integer.MAX_VALUE;
        
        // fun(4)=>n-1
        minimalCostRecursion_1(minCosts, 0,n-1,new ArrayList<>(heights),k);

        // wrest the minimum energy from all possible energy 
        for (int cost : minCosts) {
            ans = Math.min(ans, cost);
        }
        System.out.println("Minimum cost Brute Force 1: " + ans);
        minCosts.clear();

        ans=minimalCostRecursion_2(0,n-1,heights,k);
        System.out.println("Brute force method 2: "+ans);
        
        // DP starts here
        ArrayList<Integer> dp = new ArrayList<>();
        
        // initialize storage for == n 
        for(int i=0;i< (n+1) ;i++) dp.add(-1);    // initially -1
        
        int res = minimalCost(0,n-1, new ArrayList<>(dp), heights,k);
        System.out.println("DP Memoization: "+res);
        
        System.out.println("DP Tabulation: "+minimalCostTabulation(n,heights,k));
        
        
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


