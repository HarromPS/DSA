package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _7_Move_Zeros {
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
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.
    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
     */

    // Brute Force
    // T.C: O(n)
    // S.c: O(n)
    public static void Move_Zeros_To_End_Brute(int arr[], int n) {
        // collect all non zero elements & place at the beginning of the array 
        // and remaining zeros at the end
        int nonZeroArray[] = new int[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                nonZeroArray[j]=arr[i];
                j++;
            }
        }

        // fill array with non zero integers
        for(int i=0;i<nonZeroArray.length;i++){
            arr[i] = nonZeroArray[i];
        }
        return ;
    }

    // Optimal Approach
    // T.C: O(n)
    // S.c: O(1)
    public static void Move_Zeros_To_End__Optimal(int arr[], int n) {
        // As we have to send zeros to back, we can do this with algo bubble sort swapping
        // Two pointers
        if(n==1) return;
        int i=0;    // tracks zeros
        int j=1;    // tracks non zeros
        while(i<j && j<n){
            // find zero
            while(i<j && arr[i]!=0){
                i++;
            }
            j=i+1;    // find non zero after tracking a zero, to be swapped
            while(j<n && arr[j]==0){
                j++;
            }
            if(i<j && i<n && j<n){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
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

        Move_Zeros_To_End_Brute(a, n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        Move_Zeros_To_End__Optimal(b, n);
        for (int i = 0; i < n; i++) {
            System.out.print(b[i] + " ");
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
        // solve(sc);
        // }
        solve(sc);
    }
}