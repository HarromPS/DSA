package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _5_Remove_Duplicates {
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
     * 
     * - Given an integer array nums sorted in non-decreasing order,
     * - such that each unique element appears "at most twice".
     * - The relative order of the elements should be kept the same
     * 
     * - Consider the number of unique elements of nums to be k, to get accepted,
     * 
     * - Change the array nums such that the first k elements of nums contain the
     * unique elements in the order
     * - they were present in nums initially.
     * - The remaining elements of nums are not important as well as the size of
     * nums.
     * 
     * Return k.
     * 
     * Input: nums = [1,1,1,2,2,3]
     * Output: 5, nums = [1,1,2,2,3,_]
     * Explanation: Your function should return k = 5, with the first five elements
     * of nums being 1, 1, 2, 2 and 3 respectively.
     * It does not matter what you leave beyond the returned k (hence they are
     * underscores).
     * 
     */

    // Brute Force
    // T.C: O(log n + n)
    // S.c: O(n)
    public static int Remove_DuplicatesBrute(int arr[], int n) {
        // Map frequencies for each element
        // whose freq is <= 2 add it to ans
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            if (mp.containsKey(arr[i]) == true) {
                if (mp.get(arr[i]) == 1) {
                    mp.put(arr[i], mp.get(arr[i]) + 1);
                }
            } else {
                mp.put(arr[i], 1);
            }
        }

        int i = 0;
        for (Map.Entry<Integer, Integer> it : mp.entrySet()) {
            int val = it.getValue();
            while (val > 0) {
                arr[i] = it.getKey();
                i++;
                val--;
            }
        }

        return i;
    }

    // Optimal Approach
    // T.C: O(n)
    // S.c: O(1)
    public static int Remove_Duplicates_Optimal(int arr[], int n) {
        // If the array length is less than or equal to 2, return n as is
        if (n <= 2) return n;

        // Two pointers: one for iterating, another for placing elements
        int j = 1; // Points to the position where the next element should be placed
        int count = 1; // Count occurrences of current element

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }


            // Place the element if its count is less than or equal to 2
            if (count <= 2) {
                System.out.print(j+" ");
                arr[j++] = arr[i];
            }
        }

        // Return the new length of the array
        return j;
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

        int m = Remove_DuplicatesBrute(a, n);
        System.out.println(m);
        for (int i = 0; i < m; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        m = Remove_Duplicates_Optimal(b, n);
        // System.out.println(m);
        // for (int i = 0; i < m; i++) {
        //     System.out.print(a[i] + " ");
        // }
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