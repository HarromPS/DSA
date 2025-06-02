
package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _42_Longest_String_Chain {
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
    You are given an array of words where each word consists of lowercase English letters.

    wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".          

    A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

    Return the length of the longest possible word chain with words chosen from the given list of words.

    words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
     */
    public static boolean isPredecessor(String s1,String s2){       
        int n = s1.length();
        int m = s2.length();
        
        // invalid case 
        if(n-m != 1){
            return false;
        }

        // for other cases
        int i=0,j=0;
        while(i<n){
            if(j<m && s1.charAt(i) == s2.charAt(j)){
                i++;
                j++;
            }else{
                i++;
            }
        }

        // if both reaches the end in a valid condition 
        if(j==m && i==n){
            return true;
        }
        return false;
    }

    public static int Longest_String_Chain_DPOptimized_2(String[] arr) {
        // Sort the strings array by length of strings
        int n = arr.length;
        Arrays.sort(arr, (a,b)->Integer.compare(a.length(), b.length()));

        int dp_2[] = new int[n];

        // initial length of each is 1
        for (int i = 0; i < n; i++) {
            dp_2[i] = 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(arr[i], arr[j]) == true && dp_2[i] < dp_2[j] + 1) {
                    dp_2[i] = dp_2[j] + 1;
                }
            }
            ans=Math.max(ans,dp_2[i]);
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();

        String arr[] = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLine();
        }

        int ans = Longest_String_Chain_DPOptimized_2(arr);
        System.out.println("DP DPOptimized 2:" + ans);
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
