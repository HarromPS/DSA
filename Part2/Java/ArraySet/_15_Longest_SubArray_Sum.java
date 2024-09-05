package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _15_Longest_SubArray_Sum {
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
     * Problem Statement: Longest Sub-Array with Sum K (means consecutive array)

     * Given an array arr containing n integers and an integer k. Your task is to
     * find the length of the longest Sub-Array with the sum of the elements equal
     * to the given value k.
     * 
     * Input :
     * arr[] = {10, 5, 2, 7, 1, 9}, k = 15
     * Output : 4
     * Explanation:
     * The sub-array is {5, 2, 7, 1}.
     * 
     * Input :
     * arr[] = {-1, 2, 3}, k = 6
     * Output : 0
     * Explanation:
     * There is no such sub-array with sum 6.
     * 
     */

    // Brute Force TLE (finding all subarrays)
    // T.C: O(n^2)
    // S.C: O(1)
    public static int Longest_SubArray_Sum_Brute(int[] nums,int k) {
        // By comparing all numbers such that finding its duplicate
        // if any duplicate is not found means it is unique

        int len=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    len=Math.max(len,j-i+1);
                }else if(sum>k){
                    break;
                }
            }
        }
        return len;
    }

    // Better
    // T.C: O(n+log n)
    // S.C: O(n) storing frequencies of each element
    public static int Longest_SubArray_Sum_Better(int[] nums,int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int sum=0,len=0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            sum+=nums[i];
            if(sum==k){
                len=Math.max(len, i+1);
            }
            int rem = sum-k;
            if(mp.containsKey(rem)){
                len = Math.max(len, i-mp.get(rem));
            }
            mp.put(sum, i);
        }
        return len;
    }


    //////////////////////////////////////////
    // for positives and zeros
    // Optimal
    // T.C: O(n logn)    Two pointers
    // S.C: O(1)
    public static int Longest_SubArray_Sum_Optimal(int[] nums,int k) {
       int sum=0;
       int len=0;
       int n=nums.length;
       int l=0,r=0;
       while(r<n && l<=r){
            sum+=nums[r];
            if(sum<=k){
                len=Math.max(len, r-l+1);
            }
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            r++;
       }
       return len;
    }

    // Optimal
    public static int Longest_SubArray_Sum_Optimal_1(int[] nums,int k) {
       int sum=0;
       int len=0;
       int n=nums.length;
       int l=0,r=0;
       while(r<n && l<=r){
            sum+=nums[r];
            if(sum<=k){
                len=Math.max(len, r-l+1);
            }
            if(sum>k){
                sum-=nums[l];
                l++;
            }
            r++;
       }
       return len;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = Longest_SubArray_Sum_Brute(arr,k);
        System.out.println("Brute force: " + ans);

        ans = Longest_SubArray_Sum_Better(arr,k);
        System.out.println("Better approach: " + ans);

        ans = Longest_SubArray_Sum_Optimal(arr,k);
        System.out.println("Optimal approach: " + ans);

        ans = Longest_SubArray_Sum_Optimal_1(arr,k);
        System.out.println("Optimal approach 1: " + ans);
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
        //
        solve(sc);
        // }
    }
}