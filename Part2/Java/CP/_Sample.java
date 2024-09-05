package Java.CP;

import java.util.ArrayList;

public class _Sample {
    public static void _Function(int input1[]){

        ArrayList<Integer> ds = new ArrayList<>();

        solve(0,input1,ds);
        System.out.println(ans);
		// throw new UnsupportedOperationException("MaxORArray(int[] input1,int input2)");
	}

    public static void main(String[] args) {
        int arr[] = {2,1,1,5,4,4,8,1};
        _Function(arr);
    }

    public static int ans = 0, maxXor = 0;

    public static void solve(int index, int arr[], ArrayList<Integer> ds) {
        if (index >= arr.length) {
            int xor = 0;
            for (int i = 0; i < ds.size(); i++) {
                xor |= ds.get(i);
                System.out.print(ds.get(i)+": ");
            }
            if (maxXor <= xor) {
                maxXor = Math.max(maxXor, xor);
                ans = Math.max(ans, arr.length-ds.size());
                }
            System.out.println(xor+" "+ans);
            return;
        }
        for(int i=index;i<arr.length;i++){
            ds.add(arr[i]);
            solve(i+1,arr,ds);
            ds.remove(ds.size()-1);
        }
    }
}
