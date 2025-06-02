package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _9_Union_Array {
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
     * Given two sorted arrays of size n and m respectively, find their union. 
     * The Union of two arrays can be defined as the common and distinct elements in the two arrays.
     * Return the elements in sorted order.
     * 
        Input: 
        n = 5, arr1[] = {1, 2, 3, 4, 5}  
        m = 5, arr2 [] = {1, 2, 3, 6, 7}
        Output: 
        1 2 3 4 5 6 7
        Explanation: 
        Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
     * 
     */
    // Brute Force
    // T.C: O(n+m+log n) set operation
    // S.c: O(n+m)       set space(worst case, if unique elements are in both arrays)
    public static ArrayList<Integer> findUnionBrute(int arr1[], int b[], int n, int m) {
        ArrayList<Integer> ans = new ArrayList<>();
        Set<Integer> s = new HashSet<>();

        for(int i=0;i<n;i++){
            s.add(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            if(s.contains(b[i])==false){
                s.add(b[i]);
            }
        }
        
        for(Integer it:s){
            ans.add(it);
        }
        return ans;
    }


    // Better 
    // T.C: O(n+m), S.C:O(n+m)
    public static ArrayList<Integer> findUnionBetter(int arr1[], int arr2[], int n, int m) {
        // add your code here
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            // if matches
            if (arr1[i] == arr2[j]) {
                if (k > 0) {
                    if (ans.get(k - 1) != arr1[i]) {
                        ans.add(arr1[i]);
                        k++;
                    }
                } else {
                    ans.add(arr1[i]);
                    k++;
                }
                i++;
                j++;
            }

            else if (arr1[i] < arr2[j]) {
                if (k > 0) {
                    if (ans.get(k - 1) != arr1[i]) {
                        ans.add(arr1[i]);
                        k++;
                    }
                } else {
                    ans.add(arr1[i]);
                    k++;
                }
                i++;
            }

            else if (arr1[i] > arr2[j]) {
                if (k > 0) {
                    if (ans.get(k - 1) != arr2[j]) {
                        ans.add(arr2[j]);
                        k++;
                    }
                } else {
                    ans.add(arr2[j]);
                    k++;
                }
                j++;
            }
        }

        while (i < n) {
            if (k > 0) {
                if (ans.get(k - 1) != arr1[i]) {
                    ans.add(arr1[i]);
                    k++;
                }
            } else {
                ans.add(arr1[i]);
                k++;
            }
            i++;
        }

        while (j < m) {
            if (k > 0) {
                if (ans.get(k - 1) != arr2[j]) {
                    ans.add(arr2[j]);
                    k++;
                }
            } else {
                ans.add(arr2[j]);
                k++;
            }
            j++;
        }
        return ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[m];
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            a[i] = r;
        }
        for (int i = 0; i < m; i++) {
            int r = sc.nextInt();
            b[i] = r;
        }

        ArrayList<Integer> ans = findUnionBetter(a, b, n, m);
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + " ");
        }
        System.out.println();

        ans = findUnionBrute(a, b, n, m);
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + " ");
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
        // solve(sc);
        // }
        solve(sc);
    }
}