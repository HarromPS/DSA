package Java.Recursion;

import java.io.*;
import java.util.*;


public class _10_Kth_permutation {
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
    public static ArrayList<Integer> findKthPemutation(int n,int k){
        int fact = 1;
        ArrayList<Integer> v = new ArrayList<>();
        for(int i=1;i<n;i++){
            fact *= i;
            v.add(i);
            }
        v.add(n);
            
        ArrayList<Integer> ans = new ArrayList<>();
        k=k-1;
        while(true){
            ans.add(v.get(k/fact));
            v.remove(k/fact);
            if(v.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/v.size();
        }
        return ans;
    }
    public static void solve(FastReader sc) {
        int n=4;
        int k=17;
        ArrayList<Integer> ans = new ArrayList<>();
        ans = findKthPemutation(n,k);
        for(int i=0;i<ans.size();i++){
            System.out.print(ans.get(i)+" ");
        }
        System.out.println();
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