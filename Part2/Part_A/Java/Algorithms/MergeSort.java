package Java.Algorithms;

import java.io.*;
import java.util.*;

public class MergeSort {
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
    * Given an array of integers nums, sort the array in ascending order and return
    * it.
    * 
    * You must solve the problem without using any built-in functions in O(nlog(n))
    * time complexity and with the smallest space complexity possible.
    * 
    * Input: nums = [5,2,3,1]
    * Output: [1,2,3,5]
    * Explanation: After sorting the array, the positions of some numbers are not
    * changed (for example, 2 and 3), while the positions of other numbers are
    * changed (for example, 1 and 5).
    * 
    * Example 2:
    * 
    * Input: nums = [5,1,1,2,0,0]
    * Output: [0,0,1,1,2,5]
    * Explanation: Note that the values of nums are not necessairly unique.
    */
    
    public static void merge(int low,int mid,int high,ArrayList<Integer> arr){
        int i = low;
        int j= mid+1;
        ArrayList<Integer> temp = new ArrayList<>();

        while(i<mid+1 && j<high+1){
            if(arr.get(i) < arr.get(j)){
                temp.add(arr.get(i));
                i++;
            }else{
                temp.add(arr.get(j));
                j++;
            }
        }

        while(i<=mid){
            temp.add(arr.get(i));
            i++;
        }

        while(j<=high){
            temp.add(arr.get(j));
            j++;
        }

        j=0;
        for(i=low;i<=high;i++){
            arr.set(i,temp.get(j));
            j++;
        }
    }
    public static void mergeSort(int low,int high,ArrayList<Integer> arr){
        if(low<high){
            int mid = (low+high)/2;
            mergeSort(low,mid,arr);
            mergeSort(mid+1,high,arr);
            merge(low,mid,high,arr);
        }
    }
    
    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            arr.add(a);
        }
        System.out.println("Before sort:");
        for(int i=0;i<n;i++){
            System.out.print(arr.get(i)+" ");
        }
        System.out.println();
        
        mergeSort(0,n-1,arr);

        System.out.println("After sort:");
        for(int i=0;i<n;i++){
            System.out.print(arr.get(i)+" ");
        }
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