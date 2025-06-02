package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _3_IsSorted_Rotated {
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
    
    Given an array nums, return true if the array was originally sorted in non-decreasing order, 
    then rotated some number of positions (including zero). Otherwise, return false.

    There may be duplicates in the original array.

    Note: An array A rotated by x positions results in an array B of the same length such 
    that A[i] == B[(i+x) % A.length], where % is the modulo operation.
     * 
     * 
     * e.g
     * Example 1:

    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

    Example 2:

    Input: nums = [2,1,3,4]
    Output: false
    Explanation: There is no sorted array once rotated that can make nums.

     */

    public static void reverse(int arr[],int start,int end){
        while(start<=end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    // Brute Force
    // T.C: O(n+m+log n) set operation
    // S.c: O(n+m)       set space(worst case, if unique elements are in both arrays)
    public static void isSorted_Rotated_Brute(int arr[],int n) {
        // check if the array is sorted 
        int flag=1; // assume if array is sorted
        int unSortedIndex=0;
        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]){
                flag=0;
                unSortedIndex=i;
            }
        }
        if(flag==1){
            System.out.println("Sorted");
            return;
        }

        // if flag is changed means rotated, we need unsorted index, so we can check if array was rotated or not
        // now apply the left array rotation algo to check if array was rotated 
        reverse(arr,0,unSortedIndex-1);
        reverse(arr, unSortedIndex, n-1);
        reverse(arr, 0, n-1);

        // again check if array is found sorted, if yes, means it was rotated
        flag=1;
        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]){
                flag=0;
            }
        }
        if(flag==1){
            System.out.println("Sorted + Rotated");
        }else{
            System.out.println("Unsorted");
        }
    }

    // Another Brute
    public static boolean isSorted_Rotated_Brute_2(int arr[],int n) {
        int isSorted = -1;
        for(int i=1;i<n;i++){ if(arr[i]<arr[i-1]) {isSorted=i;}}
        if(isSorted!=-1){
            int flag = 1;
            for(int i=1;i<isSorted;i++){ if(arr[i]<arr[i-1]) {flag=0;}}
            for(int i=isSorted+1;i<n;i++){ if(arr[i]<arr[i-1]) {flag=0;}}

            int maxEle=Integer.MIN_VALUE;
            for(int i=0;i<n;i++) if(maxEle<arr[i]) maxEle=arr[i];
            if(arr[((isSorted+n)-1)%n] == maxEle && arr[0] >= arr[n-1] && flag==1){ 
                return true;
            }else{
                return false;
            }
        }
        return true;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            a[i] = r;
            b[i] = r;
        }

        isSorted_Rotated_Brute(a,n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i]+" ");
        }

        boolean bruteAns = isSorted_Rotated_Brute_2(b, n);
        System.out.println(bruteAns);
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