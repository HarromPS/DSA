package Java.ArraySet;

import java.io.*;
import java.util.*;

public class All_Subsequnces {
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

    public static void pickNonPickSubseqences(int ind,int arr[],ArrayList<Integer> ds){
        if(ind>=arr.length){
            for(int i=0;i<ds.size();i++){
                System.out.print(ds.get(i)+" ");
            }
            System.out.println();
            return;
        }

        // pick it and make left recursive call
        ds.add(arr[ind]);
        pickNonPickSubseqences(ind+1, arr, ds);
        
        // dont pick and make right recursive call
        ds.remove(ds.size()-1);
        pickNonPickSubseqences(ind+1, arr, ds);
    }

    // pick subsequences -> also generates subsequences but with no duplicates
    public static void pickSubsequences(int ind,int arr[],ArrayList<Integer> ds){
        // base case
        if(ind >= arr.length){
            for(int i=0;i<ds.size();i++){
                System.out.print(ds.get(i)+" ");
            }
            System.out.println();
            return;
        }

        // pick and non pick subsequences
        for(int i=ind;i<arr.length;i++){
            // if(i>ind && arr[i]==arr[i-1]){
            //     continue;   // skip duplicate
            // }
            // pick and call left recursive call
            ds.add(arr[i]);
            pickSubsequences(i+1, arr, ds);
            
            // dont pick
            ds.remove(ds.size()-1);

        }
    }
    public static void solve(FastReader sc) {
        int arr[] = {1,2,3,4};
        ArrayList<Integer> ds=new ArrayList<>();
        pickNonPickSubseqences(0, arr,ds);
        // pickSubsequences(0, arr, ds);
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