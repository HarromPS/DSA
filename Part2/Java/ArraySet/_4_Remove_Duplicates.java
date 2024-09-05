package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _4_Remove_Duplicates {
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
    
    - Given an integer array nums sorted in non-decreasing order,
    - remove the duplicates in-place such that each unique element appears only once. 
    - The relative order of the elements should be kept the same.
    - Then return the number of unique elements in nums.

    - Consider the number of unique elements of nums to be k, to get accepted, 

    - Change the array nums such that the first k elements of nums contain the unique elements in the order 
    - they were present in nums initially.
    - The remaining elements of nums are not important as well as the size of nums.
        
    Return k.

    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).
    */

    // Brute Force
    // T.C: O(nlog n + n) set operation n long n (insertion)
    // S.c: O(n)       set space(worst case, if unique elements are in both arrays)
    public static int Remove_DuplicatesBrute(int arr[],int n) {
        Set<Integer> s = new HashSet<>();
        for(int i=0;i<n;i++){
            if(s.contains(arr[i])==false){
                s.add(arr[i]);
            }
        }
        // replace unique elements from set
        int i=0;
        for(Integer it:s){
            arr[i]=it;
            i++;
        }
        return s.size();        
    }
    
    // Optimal Approach
    // T.C: O(n) 
    // S.c: O(1) 
    public static int Remove_DuplicatesBrute_2(int arr[],int n) {
        // Two pointer approach
        int i=0,j=1;
        while(j<n){
            if(arr[i]!=arr[j]){
                arr[i+1] = arr[j];
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i+1; // unique elements
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

        int m=Remove_DuplicatesBrute(a,n);
        System.out.println(m);
        for (int i = 0; i < m; i++) {
            System.out.print(a[i]+" ");
        }
        System.out.println();
        m = Remove_DuplicatesBrute_2(b, n);
        for (int i = 0; i < m; i++) {
            System.out.print(b[i]+" ");
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