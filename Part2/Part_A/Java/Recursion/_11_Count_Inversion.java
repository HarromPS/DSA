package Java.Recursion;

import java.io.*;
import java.util.*;

public class _11_Count_Inversion {
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
    public static void merge(int low,int mid,int high){
        int mergedArr[]=new int[(mid-low+1)+(high-mid)];
        int i=low;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=high){
            if(arr[i]>arr[j]){
                // count the pairs
                pairs = pairs+(mid-i+1);
                mergedArr[k] = arr[j];
                k++;
                j++;
            }else{
                mergedArr[k] = arr[i];
                k++;
                i++;
            } 

        }

        while(i<=mid){
            mergedArr[k]=arr[i];
            k++;
            i++;
        }
        while(j<=high){
            mergedArr[k]=arr[j];
            k++;
            j++;
        }
        k=0;
        for(int x=low;x<=high;x++){
            arr[x]=mergedArr[k];
            k++;
        }
    }
    public static void mergeSort(int low,int high){
        if(low<high){
            int mid = (high+low)/2;
            mergeSort(low, mid);
            mergeSort(mid+1, high);
            merge(low,mid, high);
        }
    }
    public static int pairs=0;
    public static int arr[];
    public static void solve(FastReader sc) {
        // count inversion is a algo which uses merge sort algorithm to find 
        // pairs in an array where i<j && arr[i]>arr[j];

        ArrayList<Integer> a = new ArrayList<>(Arrays.asList(5, 3, 2, 4, 1));
        arr = new int[a.size()];
        for(int x=0;x<a.size();x++){
            arr[x]=a.get(x);
        }
        // first step to write a merse sort code 
        mergeSort(0,a.size()-1);
        System.out.println(pairs);
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