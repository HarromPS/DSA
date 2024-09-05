package Java.Recursion;

public class _4_All_Permutations_without_space {
    public static void solve(int array[], int index){
        // base condition
        if(index>=array.length){
            // print the array
            for(int i=0;i<array.length;i++){
                System.out.print(array[i]+" ");
            }
            System.out.printf("\n");
            return ;
        }

        // iterate from the current index(first index of permutation)
        // perform swap of all elements next to index element with index element at each iteration
        for(int i=index;i<array.length;i++){
            // swap
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;

            // next recursive function call
            solve(array,index+1);

            // retain the current depth positions
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }

    public static void swap(int a,int b){
        
    }

    public static void main(String[] args) {
        int array[]={1,2,3};

        // print all the possible permutations without extra space i.e map
        solve(array,0);
    }
}
