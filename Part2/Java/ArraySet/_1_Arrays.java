package Java.ArraySet;
// Implementation of array data structure
// package Java.Arrays;

class Solution {
    public int arr[];
    public int totalSize;
    public int usedSize;

    // initialize the array with a size
    public void initializeArray(int size){
        this.arr = new int[size];
        this.totalSize = size;
        this.usedSize = 0;
    }

    // Operations on array

    // O(N)
    // 1. Traversal
    public void traverseArray(){
        System.out.println();
        for(int i=0;i<this.usedSize;i++){
            System.out.print(this.arr[i]+" ");
        }
        System.out.println("\n");
    }

    // O(1)
    // 2. Insertion
    public void insertArray(int element){
        if(this.usedSize >= this.totalSize){
            System.out.println("FAILED-INSERTED\nARRAY IS FULL");
        }
        else{
            this.arr[this.usedSize++] = element;
            System.out.println("SUCCESS-INSERTED");
        }
    }

    // O(N)
    // 3. Deletion (deletes first instance an element)
    public int deleteElement(int target){
        int index = -1,flag=0;
        for(int i=0;i<=this.usedSize;i++){
            if(this.arr[i] == target){
                index = i;
                break;
            }
        }

        int res = this.arr[index];
        if(index != -1 && index<this.usedSize){
            for(int i=index;i<this.usedSize;i++){
                this.arr[i] = this.arr[i+1];
                index = i;
            }
            this.arr[index+1] = 0;
            flag = 1;
        }
        else{
            this.arr[index] = 0;
            flag = 1;
        }

        if(flag == 1){
            System.out.println("SUCCESS DELETED");
            return res;
        }
        System.out.println("FAILED DELETED");
        return -1;
    }

    // O(N)
    // 4. Searching a particular element
    public int searchElement(int element){
        int flag = -1;
        for(int i=0;i<this.usedSize;i++){
            if(this.arr[i] == element){
                flag = i;
                break;
            }
        }
        if(flag != -1){
            System.out.println("FOUND AT INDEX:"+flag);
            return flag;
        }
        System.out.println("NOT FOUND");
        return flag;
    }

}
public class _1_Arrays {

    public static void main(String[] args){
        Solution a = new Solution();
        a.initializeArray(10);
        a.insertArray(1);
        a.insertArray(2);
        a.traverseArray();
        a.insertArray(3);
        a.insertArray(4);
        a.traverseArray();

        a.deleteElement(3);
        a.traverseArray();

        a.searchElement(2);
    }

}