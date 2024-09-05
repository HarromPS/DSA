package Java.Dynamic_Programming;

import java.io.*;
import java.util.*;

public class _50_Palindrome_Partitioning_II {
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
     * Given a string s, partition s such that every
     * substring
     * of the partition is a
     * palindrome
     * .
     * 
     * Return the minimum cuts needed for a palindrome partitioning of s.
     * 
     * 
     * 
     * Example 1:
     * 
     * Input: s = "aab"
     * Output: 1
     * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
     * cut.
     * 
     * Example 2:
     * 
     * Input: s = "a"
     * Output: 0
     * 
     * Example 3:
     * 
     * Input: s = "ab"
     * Output: 1
     * 
     * 
     */

    // function to check if a string is a palindrome
    public static boolean isPalindrome(int i, int j, String s) {
        while (i < j) {
            // if not a palindrome
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        // this is a palindrome
        return true;
    }
    // Solving this problem independantly will not work
    // Brute force

    public static int Palindrome_Partitioning_2_Recursion(int i, String arr, int n) {
        // base case
        // if there are no partitions
        if (i == n) {
            return 0;
        }

        int ans = Integer.MAX_VALUE;
        // recurrence relation
        // loop till n-1 and check for the palindromes and make partitions
        for (int j = i; j < n; j++) {
            // check for the palindrome
            if (isPalindrome(i, j, arr) == true) {
                // perform the partition
                int cost = 1 + Palindrome_Partitioning_2_Recursion(j + 1, arr, n);
                ans = Math.min(ans, cost);
            }
        }

        return ans;
    }

    // DP Memoization
    public static int Palindrome_Partitioning_2_Memoization(int i, String arr, int n, int dp[]) {
        // base case
        // if there are no partitions
        if (i == n) {
            return 0; // coins gain 0
        }

        // if subproblems are already solved return it
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = Integer.MAX_VALUE;
        // recurrence relation
        // loop till n-1 and check for the palindromes and make partitions
        for (int j = i; j < n; j++) {
            // check for the palindrome
            if (isPalindrome(i, j, arr) == true) {
                // perform the partition
                int cost = 1 + Palindrome_Partitioning_2_Memoization(j + 1, arr, n, dp);
                ans = Math.min(ans, cost);
            }
        }

        dp[i] = ans;
        return dp[i];
    }

    public static int Palindrome_Partitioning_2_Tabulation_1(String arr) {
        int n = arr.length();
        int dp[] = new int[n+1];

        // base case
        dp[n]=0;

        // index i ->n-1 to 0, j from i to 0
        for(int i=n-1;i>=0;i--){
            int ans = Integer.MAX_VALUE;
            for(int j=i;j<n;j++){
                if(isPalindrome(i, j, arr)==true){
                    int cost = 1 + dp[j+1];
                    ans = Math.min(ans,cost);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }

    public static void solve(FastReader sc) {
        String s = sc.nextLine();
        int n = s.length();

        int dp[] = new int[n];
        Arrays.fill(dp, -1);

        // uses the concept of (Front Partitioning)

        int ans = Palindrome_Partitioning_2_Recursion(0, s, n)-1;
        System.out.println("Brute force:" + ans);

        ans = Palindrome_Partitioning_2_Memoization(0, s, n, dp)-1;
        System.out.println("DP Tabulation Sriver_1:" + ans);

        ans = Palindrome_Partitioning_2_Tabulation_1(s);
        System.out.println("DP Tabulation Sriver_1:" + ans);

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
