package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _11_Closet_Three_Sum {
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
    Given an array, arr of integers, and another number target, 
    find three integers in the array such that their sum is closest to the target. 
    Return the sum of the three integers.

    Note: If there are multiple solutions, return the maximum one.
    Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
    Output: 2
    Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.

    Input: arr[] = [5, 2, 7, 5], target = 13
    Output: 14
    Explanation: There is one triplet with sum 12 and other with sum 14 in the array.
    Triplet elements are 5, 2, 5 and 2, 7, 5 respectively.
    Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
    
     */

    // Brute Force
    // T.C: O(2^n) Get all sums of length 3 using recursion
    // S.c: >> O(n) 
    public static void closet_three_Sum_Brute(int index,ArrayList<Integer> arr,ArrayList<ArrayList<Integer>> seq,ArrayList<Integer> ds) {   
        // base case
        if(index<0){
            seq.add(new ArrayList<>(ds));
            return;
        }
        
        // pick 
        ds.add(arr.get(index));
        closet_three_Sum_Brute(index-1,arr,seq,ds);
        
        // dont pick
        ds.remove(ds.size()-1);
        closet_three_Sum_Brute(index-1,arr,seq,ds);
    }

    public static int Closet_Sum_Brute(ArrayList<Integer> arr, int target){
        
        // get all sequences
        ArrayList<ArrayList<Integer>> seq = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> ds = new ArrayList<>();
        int n = arr.size();
        
        closet_three_Sum_Brute(n-1,arr,seq,ds);
        
        // save all the sums which are less than target to max heap
        PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());

        // save all the sums which are greater than target to min heap
        PriorityQueue<Integer> min = new PriorityQueue<>();

        for(int i=0;i<seq.size();i++){
            int m = seq.get(i).size();
            if(m==3){
                int sum=0;
                for(int j=0;j<m;j++){
                    int val = seq.get(i).get(j);
                    sum+=val;
                }

                // best case if target found itself
                if(sum==target) return sum;
                if(sum<target){
                    max.add(sum);
                }else{
                    min.add(sum);
                }
            }
        }
        
        if(max.isEmpty()==true) return min.peek();
        if(min.isEmpty()==true) return max.peek();
        
        // get the min difference in abs value of top of them

        /*
                     target(13)
        e.g max (12)            min(14)

        abs(max.peek()-target) = (12-13) = 1
        abs(min.peek()-target) = (14-13) = 1 so return min.peek()
         */
        if(Math.abs(max.peek()-target)<Math.abs(min.peek()-target)){
            return max.peek();
        }
        return min.peek();
    }
    // Better: Queue
    // T.C: O(n)
    // S.C: O(n)
    public static int closet_three_Sum_Optimal(ArrayList<Integer> arr, int target){
        int diff=Integer.MAX_VALUE;
        int ans = 0;
        int n = arr.size();
        
        // two pointers 
        Collections.sort(arr);
        int i = 0;
        while(i<=n-3){
            int j= i+1;
            int k = n-1;
        
            while(j<k){
                int sum = arr.get(i)+arr.get(j)+arr.get(k);
                if(sum==target) return sum;
                else if(sum<target){
                    j++;
                }else{
                    k--;
                }
                
                // get the closet sum
                if(Math.abs(sum-target)<diff){
                    diff=Math.abs(sum-target);
                    ans=sum;
                }else if(Math.abs(sum-target)==diff){  // still same diff get max sum
                    ans=Math.max(ans,sum);
                }
            }
            i++;
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int target = sc.nextInt();
        
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<n;i++){
            int r = sc.nextInt();
            arr.add(r);
        }

        // Brute force 
        int ans = Closet_Sum_Brute(arr, target);
        System.out.println("Brute force: "+ans);

        ans = closet_three_Sum_Optimal(arr, target);
        System.out.println("Brute force: "+ans);
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