package Java.Recursion;

import java.util.ArrayList;

// implementation of all possible subsequence of array list
public class _1_Subarrays {

    public static ArrayList<Integer> given;


    // this is a standard recursion problem
    static public void getAllPossibleLists(int index,int n,ArrayList<Integer> arr){
        // Base case
        if(index >= n){

            // print the subsequence
            for(int i=0;i<arr.size();i++){
                System.out.print(arr.get(i)+" ");
            }
            System.out.println();
            return;
        }

        // pick the array element, added to the subsequence
        arr.add(given.get(index));

        // move the list forward by add index and a function call
        getAllPossibleLists(index+1, n, arr);

        // dont pick the same array, not added to the subsequence
        arr.remove(arr.size() -1);

        // again move the list forward with a function call
        getAllPossibleLists(index+1, n, arr);
    }

    public static void main(String[] args){
        given = new ArrayList<Integer>();

        int lst[] = {3,2,1};
        for(int i=0;i<lst.length;i++){
            given.add(lst[i]);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        getAllPossibleLists(0, lst.length, ans);
    }

}