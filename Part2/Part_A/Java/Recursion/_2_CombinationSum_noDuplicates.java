package Java.Recursion;

import java.util.ArrayList;

/*
Combination sum: 

Given an array [1,1,1,2,2] and a target sum: 4
find all possible combination which forms the sum
where no repetations are allowed and no duplicate combinations are allowed

Means each element can be used only once or cannot be used at all.
*/

public class _2_CombinationSum_noDuplicates {

    // combination sum function
    static public void combinationSum(int index,int target, ArrayList<Integer> s,int size,int arr[]){
        // base case
        if(target == 0){
            // print the subsequence
            for(int i=0;i<s.size();i++){
                System.out.print(s.get(i)+" ");
            }
            System.out.println();
            return;
        }

        // loop through all the neighbour elements to get the subsequence, 
        // where any index can be picked up as first element of the subsequence

        // starting from current index
        for(int i=index;i<size;i++){
            // check if there are duplicates
            if(i>index && arr[i]==arr[i-1]){

                // skip the index
                continue;
            }

            // check if the target is reachable
            if(arr[i]>target){

                // if this current index is not able to reach the target, how next can be
                // as array is in sorted order
                break;
            }

            // pick 
            s.add(arr[i]);

            // call the pick function (left function call)

            // move to next index, as repetation of same index is not allowed
            combinationSum(i+1,target-arr[i], s,size,arr);

            // dont pick
            s.remove(s.size()-1);
        }
    }

    public static void main(String[] args){
        int arr[] = {1,1,2,1,2};
        int size = arr.length;
        int target = 4;
        ArrayList<Integer> s=new ArrayList<Integer>();
        
        // sort the array
        sortArray(arr,0,size-1);
        
        // call the combination sum function
        combinationSum(0, target, s, size, arr);
    }
    
    public static void printArray(int arr[],int size){
        for(int i=0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    public static int partition(int arr[],int low,int high){
        // declare a pivot element
        int pivot = arr[low];
        
        // tracker indices
        int i = low+1;
        int j = high;

        int temp = 0;

        // iterate until i and j crosses each other and finds the perfect spot for the pivot
        while(i<=j){

            // find element bigger than pivot
            while(i <= j && arr[i] <= pivot){
                i++;
            }

            // find element smaller than pivot
            while(arr[j] > pivot){
                j--;
            }

            if(i<j){
                // swap the i and j
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap the position of j with piovt 
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        // return the index of pivot element for partition as this position is occupied by correct element in position
        return j;
    }

    public static void sortArray(int arr[],int low,int high){
        // quick sort
        if(low<high){
            int partitionIndex = partition(arr,low,high);
            sortArray(arr, low, partitionIndex-1);
            sortArray(arr, partitionIndex+1, high);
        }
    }
}