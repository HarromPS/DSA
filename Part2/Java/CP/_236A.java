package Java.CP;

import java.io.*;
import java.util.*;

public class _236A {
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

    public static void solve1(FastReader sc) {
        String str = sc.nextLine();
        Map<String,Integer> mp = new HashMap<>();
        for(int i=0;i<str.length();i++){
            if(mp.containsKey(String.valueOf(str.charAt(i)))==true){
                mp.put(String.valueOf(str.charAt(i)), mp.get(String.valueOf(str.charAt(i)))+1);
            }else{
                mp.put(String.valueOf(str.charAt(i)),1);
            }
        }
        int isMale=1;
        for(Map.Entry<String,Integer> it:mp.entrySet()){
            if(it.getValue()%2==0){
                isMale=0;
            }
        }
        if(isMale==1){
            System.out.println("IGNORE HIM!");
        }else{
            System.out.println("CHAT WITH HER!");
        }
    }
    public static void solve(FastReader sc) {
        String str = sc.nextLine();
        Set<String> mp = new HashSet<String>();
        for(int i=0;i<str.length();i++){
            if(!mp.contains(String.valueOf(str.charAt(i)))){
                mp.add(String.valueOf(str.charAt(i)));
            }
        }        
        if(mp.size()%2==0){
            System.out.println("CHAT WITH HER!");
        }else{
            System.out.println("IGNORE HIM!");
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
        //     solve();
        // }
        // solve1(sc);
        solve(sc);
    }
}