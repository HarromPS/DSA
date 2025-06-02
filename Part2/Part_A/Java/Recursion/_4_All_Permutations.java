package Java.Recursion;
import java.util.ArrayList;


/*
Given an array/string return all possible permutations in any order
[1,2,3] => [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
 */
public class _4_All_Permutations {
    public static ArrayList<Integer> v;

    public static void solve(int arr[],ArrayList<Integer> map){
        // base condition
        if(v.size()==arr.length){
            // print the data structure
            for(int i=0;i<v.size();i++){
                System.out.print(v.get(i)+" ");
            }
            System.out.println();
            return;
        }

        // loop the array and see available element to be picked
        for(int i=0;i<arr.length;i++){
            if(map.get(i)==-1){
                v.add(arr[i]);
                map.set(i,1);
                solve(arr,new ArrayList<>(map));

                // reset the data structure and unmark map for right recursion call
                v.remove(v.size()-1);
                map.set(i,-1);
            }
        }
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3};
        v = new ArrayList<>();
        ArrayList<Integer> map = new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            map.add(-1);
        }

        solve(arr,map);
    }
}
