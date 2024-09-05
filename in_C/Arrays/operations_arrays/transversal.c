#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Operations on Array 
// 1.Transversal = visiting each & every element of the array 
// 2. Insertion = inserting elements at a given position (i.e at some index)
// 3. Deletion = deleting elements at a given position (at some indexes)
// 4. Searching ..... & more
int main(){
    // 1. Transversal
    
    int total_size; // total reserved size of the array
    printf("Enter the Total size of your array: ");
    scanf("%d",&total_size);
    int used_size;  // total size used 
    printf("Enter the size you are using of your array: ");
    scanf("%d",&used_size);

    int arr[total_size];
    printf("\nTransversing to Set the elements in the array\n");
    for(int i=0;i<used_size;i++)
    {
        printf("%d element: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nTransversing the array\n");
    for(int i=0;i<used_size;i++)
    {
        printf("%d element: %d\n",i+1,arr[i]);
    }
    

    return 0; 
}