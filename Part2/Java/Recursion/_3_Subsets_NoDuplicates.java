package Java.Recursion;

import java.io.*;
import java.util.*;

public class _3_Subsets_NoDuplicates {
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

    static public void Subsets_NoDuplicates(int index,int arr[],int n,ArrayList<Integer> ds,int sum){
        // base case
        if(sum==0 && index>=0){
            for(int i=0;i<ds.size();i++){
                System.out.print(ds.get(i)+" ");
            }
            System.out.println();
            return;
        }

        if(index<0) return;
        
        // pick and check for duplicates
        for(int i=index;i>=0;i--){
            // check for duplicates
            if(i>index && arr[i]==arr[i-1]){
                continue;   // skip if dulpicate found
            }

            // check if sum is reachble
            if(arr[i]>sum){
                break;
            }

            // pick
            ds.add(arr[i]);
            Subsets_NoDuplicates(i-1, arr, n, ds,sum-arr[i]);

            // dont pick
            ds.remove(ds.size()-1);
        }
    }
    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int sum=sc.nextInt();

        int arr[] = new int[n];
        for(int j=0;j<n;j++){
            int r = sc.nextInt();
            arr[j] = r;
        }

        ArrayList<Integer> ds = new ArrayList<>();
        Subsets_NoDuplicates(n-1,arr,n,ds,sum);
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