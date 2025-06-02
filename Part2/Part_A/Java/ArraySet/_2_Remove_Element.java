package Java.ArraySet;

import java.io.*;
import java.util.*;

public class _2_Remove_Element {
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
     * - Given an integer array nums and an integer val, remove all occurrences of
     * val in nums in-place.
     * - The order of the elements may be changed.
     * - Then return the number of elements in nums which are not equal to val.
     * 
     * - Consider the number of elements in nums which are not equal to val be k, to
     * get accepted
     * 
     * - Change the array nums such that the first k elements of nums contain the
     * elements which are not equal to val.
     * - The remaining elements of nums are not important as well as the size of
     * nums.
     * 
     * Return k.
     * 
     * Input: nums = [0,1,2,2,3,0,4,2], val = 2
     * Output: 5, nums = [0,1,4,0,3,_,_,_]
     * Explanation: Your function should return k = 5, with the first five elements
     * of nums containing 0, 0, 1, 3, and 4.
     * Note that the five elements can be returned in any order.
     * It does not matter what you leave beyond the returned k (hence they are
     * underscores).
     * 
     */

    // Brute Force
    // T.C: O(n) iterate whole array
    // S.c: O(n) worst case if there are no elements == k
    public static int Remove_Element_Brute(int arr[], int n, int k) {
        // Not using a set for this problem, as if there are duplicates for elements
        // which are != k
        // which will result losing them

        ArrayList<Integer> ds = new ArrayList<>();

        // add all items which == k
        for (int i = 0; i < n; i++) {
            if (arr[i] != k) {
                ds.add(arr[i]);
            }
        }

        // replace first m elements which are not = k
        int m = ds.size(); // m <= n
        for (int i = 0; i < m; i++) {
            arr[i] = ds.get(i);
        }

        // number of elements removed
        return (n - (n-m)); // total - which are not k = k
    }

    // Optimal Approach
    // T.C: O(n)
    // S.c: O(1) // constant space (inplace computation)
    public static int Remove_Element_Optimal(int arr[], int n, int k) {
        // Two pointer approach
        // put all unwanted elements to the end

        int i = 0; // finds which are k
        int j = n - 1; // finds which are not k (swap k with non k elements)
        while (i < j) {
            while (i < n && arr[i] != k) {
                i++;
            }

            while (j>=0 && arr[j] == k) {
                j--;
            }

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        // total non k elements
        int ans=0;
        for(i=n-1;i>=0;i--){
            if(arr[i]==k){
                ans++;
            }else{
                break;
            }
        }
        return n-ans;
    }

    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            int r = sc.nextInt();
            a[i] = r;
            b[i] = r;
        }

        int m = Remove_Element_Brute(a, n, k);
        for (int i = 0; i < m; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        m = Remove_Element_Optimal(b, n, k);
        for (int i = 0; i < m; i++) {
            System.out.print(b[i] + " ");
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