package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _14_Single_Number_I {
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
     * Given a non-empty array of integers nums, every element appears twice except
     * for one. Find that single one.
     * 
     * You must implement a solution with a linear runtime complexity and use only
     * constant extra space.
     * 
     * Example 1:
     * 
     * Input: nums = [2,2,1]
     * Output: 1
     * 
     * Example 2:
     * 
     * Input: nums = [4,1,2,1,2]
     * Output: 4
     * 
     * Example 3:
     * 
     * Input: nums = [1]
     * Output: 1
     * 
     * 
     */

    // Brute Force TLE
    // T.C: O(n^2)
    // S.C: O(1)
    public static int singleNumber_Brute(int []nums) {
        // By comparing all numbers such that finding its duplicate
        // if any duplicate is not found means it is unique

        int n=nums.length;
        for(int i=0;i<n;i++){
            int flag=1; // means there is no duplicate of this indexed element
            for(int j=0;j<n;j++) {
                // not comparing the number by itself
                if(i!=j && nums[i]==nums[j]){
                    flag=0; // duplicate found except current index
                }
            }
            if(flag==1){
                return nums[i];
            }
        }
        return 0;
    }

    // Better 
    // T.C: O(n+log n)
    // S.C: O(n)    storing frequencies of each element
    // & whose freq is 1 means it is only one in array
    public static int singleNumber_Better(int []nums) {
        // By comparing all numbers such that finding its duplicate
        // if any duplicate is not found means it is unique

        int n=nums.length;
        Map<Integer,Integer> freqMap = new HashMap<>();
        for(int i=0;i<n;i++){
            if(freqMap.containsKey(nums[i])==true) freqMap.put(nums[i],freqMap.get(nums[i])+1);
            else freqMap.put(nums[i], 1);
        }
        
        for(Map.Entry<Integer,Integer> it: freqMap.entrySet()){
            if(it.getValue()==1) return it.getKey();
        }
        return 0;
    }

    // Optimal 
    // T.C: O(n)
    // S.C: O(1)
    // XOR -> same xor 0 and non same some value other than 0
    public static int singleNumber_Optimal(int []nums) {
        int n=nums.length;
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = singleNumber_Brute(arr);
        System.out.println("Brute force: " + ans);

        ans = singleNumber_Better(arr);
        System.out.println("Better approach: " + ans);

        ans = singleNumber_Optimal(arr);
        System.out.println("Optimal approach: " + ans);
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