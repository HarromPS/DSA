package Java.Recursion;

public class _3_Subset_Sum {
    public static int sum=0;
    public static void solve(int index,int arr[],int tempSum){
        // base condition
        if(index>=arr.length){
            sum += tempSum;
            System.out.print(tempSum+" ");
            return;
        }

        // pick up the element
        tempSum+=arr[index];

        // pick up function call
        solve(index+1, arr,tempSum);

        // dont pick up element
        tempSum-=arr[index];

        // dont pick function call
        solve(index+1, arr, tempSum);
    }
    public static void main(String[] args) {
        int arr[] = {3,2,1};
        int tempSum=0;
        solve(0,arr,tempSum);
        System.out.println("\n"+sum);
    }
}
