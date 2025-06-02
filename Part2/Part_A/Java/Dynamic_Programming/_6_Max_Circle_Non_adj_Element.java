package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _6_Max_Circle_Non_adj_Element {
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
    You are given an array/list of ‘N’ integers arranged in a circle. 
    You are supposed to return the maximum sum of the subsequence with the constraint 
    that no two elements are adjacent in the given array/list.
    
    Note: A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list,
        leaving the remaining elements in their original order.

        Input: nums = [2,3,2]
        Output: 3
        Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
        because they are adjacent houses.

    */

    // // Brute force: T.C:O(2^n), S.C: O(N) recursive stack 
    // public static int maxSumAdjElementsCircleRecursion_1(int arr[],int n){
    //     // base cases
    //     if(n==0) return arr[n]; // if chosen 2nd index, then 0th is picked and 1st index is not picked
    //     if(n<0) return 0;   // if negative index, return 0

    //     // if picked current index, cannot pick adj element (n-1), but element next to adj can be picked i.e (n-2) 
    //     int picked = arr[n] + maxSumAdjElementsCircleRecursion_1(arr, n-2);

    //     // if current not picked, then 0 is added to max sum, can pick adj element (n-1)
    //     int notPicked = 0 + maxSumAdjElementsCircleRecursion_1(arr, n-1); 

    //     // return max of picked and not picked elements
    //     return Math.max(picked, notPicked);              
    // }
    
    
    // // DP: better-> Memoization (required answer to base case then back)
    // // T.C: O(N), S.C: O(N)+O(N)
    // public static int maxSumAdjElementsCircleMemoization(int arr[],int n,int dp[]){
    //     // base cases
    //     if(n==0) return arr[0];
    //     if(n<0) return 0;

    //     // check if there is a solution for subproblem
    //     if(dp[n]!=-1) return dp[n];

    //     // calculate the value of subproblem
    //     int pick = arr[n]+maxSumAdjElementsCircleMemoization(arr, n-2, dp);
    //     int nonPick = 0 + maxSumAdjElementsCircleMemoization(arr, n-1, dp);

    //     // store value in dp
    //     dp[n] = Math.max(pick,nonPick);
    //     return dp[n];
    // }

    // // DP Tabulation-> base case to required answer
    // // T.C: O(N), S.C: O(N);
    // public static int maxSumAdjElementsCircleTabulation(int arr[]){
    //     int dp[] = new int[arr.length+1];

    //     // base case
    //     dp[0]=arr[0];

    //     for(int i=1;i<arr.length;i++){
    //         // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
    //         int pick = arr[i];
    //         if(i>1) pick+=dp[i-2];
    //         // if dont pick current, then can pick prev
    //         int nonPick = 0+dp[i-1];

    //         dp[i]= Math.max(pick,nonPick);
    //     }
    //     return dp[arr.length-1];
    // }

    // DP optimized
    // T.C: O(N), S.C : O(1)
    public static int maxSumAdjElementsCircleDPOptimized(int nums[],int start,int end){
        int prev=nums[start],prev2=0;  
        for(int i=start+1;i<end;i++){   
            // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
            int pick = nums[i];
            if(i>1) pick+=prev2; 
            // if dont pick current, then can pick prev
            int nonPick = 0+prev;
            int curri = Math.max(pick,nonPick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }

    static public int rob(int[] nums) {
        // if only one element
        if(nums.length==1) return nums[0];

        // as 1st and last element cant be considered simultaneously, so
        int withFirst = maxSumAdjElementsCircleDPOptimized(nums,0,nums.length-1); // without last
        int withLast = maxSumAdjElementsCircleDPOptimized(nums,1,nums.length);    // without first
        return Math.max(withFirst, withLast);
    }

    public static void solve(FastReader sc) {
        int n=sc.nextInt();

       int arr[] = new int[n];
        for(int i=0;i<n;i++) {
            arr[i] = sc.nextInt();
        }        
        // int maxSum = maxSumAdjElementsCircleRecursion_1(arr,n-1);
        // System.out.println("Brute Force 1:"+maxSum);
        
        // int dp[] = new int[arr.length+1];
        // for(int i=0;i<arr.length+1;i++) dp[i]=-1;
        // maxSum = maxSumAdjElementsCircleMemoization(arr, n-1, dp);
        // System.out.println("DP Memoization:"+maxSum);
        
        // maxSum = maxSumAdjElementsCircleTabulation(arr);
        // System.out.println("DP Tabulation:"+maxSum);
        
        int maxSum = rob(arr);
        System.out.println("DP Optimized:"+maxSum);
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

