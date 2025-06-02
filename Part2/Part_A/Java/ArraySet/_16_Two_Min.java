package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _16_Two_Min {
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
     Find two minimum element in the array 

     e.g [1 2 3 4 5]
     ans=> 1 2

     e.g [-1 -2 -3 -4 -5 ]
     ans=> -4 -5
     */

   
    // Print subsequence
    // T.C: O(N x N)
    // S.C: O(2 N)
    public static void Two_Minimum(int arr[], int n) {
        if(n==2){
            if(arr[0]<arr[1]){
                System.out.println("Min 1: "+arr[0]+" "+"\nMin 2: "+arr[1]);
            }else{
                System.out.println("Min 1: "+arr[1]+" "+"\nMin 2: "+arr[0]);
            }
            return;
        }
        int min_1 = arr[0];
        int min_2 = Integer.MAX_VALUE;

        for(int i=1;i<n;i++){
            if(arr[i] < min_1){
                min_2 = min_1;
                min_1 = arr[i];
            }
            else if(arr[i] > min_1 && arr[i] < min_2){
                min_2 = arr[i];
            }
        }
        System.out.println("Min 1: "+min_1+" "+"\nMin 2: "+min_2);
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Two_Minimum(arr, n);

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
