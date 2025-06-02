package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _3_Frog_Jump {
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
    - There is a frog on the '1st' step of an 'N' stairs long staircase.
    - The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
    - If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
    
    - If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
    - Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

     e.g heights: [ 10 20 30 10 ]  
                 if chooses: 10 -> 20 -> 30 -> 10
                                10    10    20    => 40 (absolute energy)

                 if chooses: 10 -> 20 -> 10
                                10    10          => 20 (absolute energy) MIN

                 if chooses: 10 -> 30 -> 10
                                20    20          => 40 (absolute energy)
     */

    // Brute force: O(n^2)  => collect all the energies then compare the minimum energy
    public static void frogJumpRecursion_1(int ind, ArrayList<Integer> minEnergy, int currEnergy,int n,ArrayList<Integer> heights){

        // base case
        if(ind >= n) {
            minEnergy.add(currEnergy);
            return;
        }
        // if jumps directly 1st stair
        if(ind-1>=0){
            frogJumpRecursion_1(ind+1, minEnergy, currEnergy+Math.abs(heights.get(ind)-heights.get(ind-1)), n, heights);
        }
        
        // if jumps directly 2nd stair
        if(ind-2>=0){
           frogJumpRecursion_1(ind+2, minEnergy, currEnergy+Math.abs(heights.get(ind)-heights.get(ind-2)), n, heights);        
        }
    }


    // Brute force: O(2^(n-1))
    public static int frogJumpRecursion_2(int ind,ArrayList<Integer> heights){
        // base case
        if(ind==0) {
            return 0;
        }
        // if jumps directly 1st stair
        int left = frogJumpRecursion_2(ind-1, heights) + Math.abs(heights.get(ind)-heights.get(ind-1));

        // if jumps directly 2nd stair
        int right=0;
        if(ind>1){
            right = frogJumpRecursion_2(ind-2, heights) + Math.abs(heights.get(ind)-heights.get(ind-1));
        }
        
        return Math.min(left, right);
    }

    // DP: better-> Memoization (required answer to base case then back)
    // T.C: O(N), S.C: O(N)+O(N) -> recursive stack

    public static int frogJump(int n, ArrayList<Integer> dp, ArrayList<Integer> heights){
        // base case 
        if(n==0) {
            return 0;
        }

        // step 3: dont solve subproblems, 1st check if it is already solved
        if(dp.get(n)!=-1){

            // then return solved value
            return dp.get(n);
        }

        // step 2: store value of subproblem computed (this step converts recursion to memoization)
        // if jumps directly 1st stair
        int left = frogJump(n-1,dp, heights) + Math.abs(heights.get(n)-heights.get(n-1));

        // if jumps directly 2nd stair
        int right=0;
        if(n>1){
            right = frogJump(n-2,dp, heights) + Math.abs(heights.get(n)-heights.get(n-1));
        }

        int res = Math.min(left, right);
        dp.set(n, res);
        return res;
    }

    // DP Tabulation-> base case to required answer
    // T.C: O(N), S.C: O(N), reduced recursive call stack extra space 
    public static int frogJumpTabulation(int n, ArrayList<Integer> heights){
        
        int dp[] = new int[n];

        // base case
        // 1st stair energy loss is 0 as, frog hasn't made any jump
        dp[0]=0;

        // start calculaing energy loss from 1st stair
        for(int i=1;i<n;i++){
            // recurrence relation

            // 1 stair jump
            int left = dp[i-1] + Math.abs(heights.get(i) - heights.get(i-1));

            // 2 stair jump
            int right=Integer.MAX_VALUE;
            if(i>1){
                right = dp[i-2] + Math.abs(heights.get(i) - heights.get(i-2));
            }

            // store the calculated energy
            dp[i] = Math.min(left,right);
        }
        return dp[n-1];
    }

    // DP optimized
    // T.C: O(N), S.C: O(1)

    public static int frogJumpDPOptimized(int n, ArrayList<Integer> heights){
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

        int n=0;
        n = sc.nextInt();
        ArrayList<Integer> heights = new ArrayList<>();
        for(int i=0;i<n;i++) {
            int h = sc.nextInt();
            heights.add(h);
        }        
        
        ArrayList<Integer> minEnergies = new ArrayList<>();
        frogJumpRecursion_1(1, minEnergies, 0,n, heights);
        frogJumpRecursion_1(2, minEnergies, 0,n, heights);

        // wrest the minimum energy from all possible energy 
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<minEnergies.size();i++){
            ans=Math.min(minEnergies.get(i),ans);
        }
        System.out.println("Brute force method 1: "+ans);
        minEnergies.clear();
        
        // frogJumpRecursion_1_Again(0, minEnergies,0, n,heights);
        // ans=Integer.MAX_VALUE;
        // for(int i=0;i<minEnergies.size();i++){
        //     ans=Math.min(minEnergies.get(i),ans);
        //     System.out.println(minEnergies.get(i)+" ");
            
        // }
        // System.out.println("Brute force method 1 Again: "+ans);

        ans=frogJumpRecursion_2(n-1,heights);
        System.out.println("Brute force method 2: "+ans);
        
        // DP starts here
        ArrayList<Integer> dp = new ArrayList<>();
        
        // // initialize storage for == n 
        for(int i=0;i< (n+1) ;i++) dp.add(-1);    // initially -1
        
        int res = frogJump(n-1, dp, heights);
        System.out.println("DP Memoization: "+res);
        
        System.out.println("DP Tabulation: "+frogJumpTabulation(n,heights));
        System.out.println("DP Optimized: "+frogJumpDPOptimized(n,heights));
        
        
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

