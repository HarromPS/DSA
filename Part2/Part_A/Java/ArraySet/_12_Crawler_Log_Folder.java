package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _12_Crawler_Log_Folder {
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

    public static int minOperations(String[] logs) {
        int ans=0;
        int n = logs.length;
        for(int i=0;i<n;i++){
            if("./".equals(logs[i])){
                continue;
            }else if("../".equals(logs[i])){
                if(ans>0){  // is at main folder remain there
                    ans--;
                }
            }else{
                ans++;
            }
        }
        return ans;
    }
    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        String logs[]=new String[n];

        for(int i=0;i<n;i++){
            logs[i] = sc.nextLine();
        }

        int ans = minOperations(logs);
        if("../".equals(logs[2])){
            System.out.println("Yes");
        }
        System.out.println("Ans: "+ans);
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