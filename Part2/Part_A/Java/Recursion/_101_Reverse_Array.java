package Java.Recursion;


import java.io.*;
import java.util.*;

public class _101_Reverse_Array {
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
     * Reverse a array
     * 
     * [1 4 5 6 7 2]
     * [2 7 6 5 4 1]
    */

    // Brute force
    public static void Brute_Reverse_Array(int arr[]){
        int n = arr.length;
        int i=0,j=n-1;
        while(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        System.out.println("Reverse array: ");
        for(i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    
    // Recursive way 
    public static void Recursive_Reverse(int i,int j,ArrayList<Integer> arr){
        // base case 
        if(i>=j){
            return;
        }

        // recurrence relation
        int temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);

        Recursive_Reverse(i+1, j-1, arr);
    }


    public static void solve(FastReader sc) {
        int n = sc.nextInt();
        int arr[] = new int[n];

        ArrayList<Integer> a = new ArrayList<>();

        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
            a.add(arr[i]);
        }

        // Brute force
        Brute_Reverse_Array(arr);

        // Recursive Approach
        System.out.println("Recursive Approach:");
        Recursive_Reverse(0, n-1, a);
        for(Integer it: a){
            System.out.print(it+" ");
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