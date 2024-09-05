#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Operations on Array 
// 1.Transversal = visiting each & every element of the array 
// 2. Insertion = inserting elements at a given position (i.e at some index)
// 3. Deletion = deleting elements at a given position (at some indexes)
// 4. Searching ..... & more
int main(){
    // 2. Insertion
    // to place a element at a given position in the array 
    
    int total_size; // total reserved size of the array
    printf("Enter the Total size of your array: ");
    scanf("%d",&total_size);
    int used_size;  // total size used 
    printf("Enter the size your are using of your array: ");
    scanf("%d",&used_size);

    int arr[total_size];
    printf("\nTransversing to Set the elements the array\n");
    for(int i=0;i<used_size;i++)
    {
        printf("%d element: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nTransversing to Print the elements the array\n");
    for(int i=0;i<used_size;i++)
    {
        printf("%d element: %d\n",i+1,arr[i]);
    }

    // Case 1 inserting at the last position in the array
    int element,index;
    printf("Element: ");
    scanf("%d",&element);
    printf("\nInserting at the last position in the array\n");
    for(int i=0;i<used_size;i++)
    {
        if(i==used_size)
        {
            used_size+=1;
            arr[used_size]=element;
        }      
    }
    printf("\narray new element: %d\n",arr[used_size]);
    printf("\nTransversing to Print the Modified elements the array\n");

    printf("\nTransversing to Print the Modified elements the array\n");
    for(int i=0;i<used_size;i++)
    {
        printf("%d element: %d\n",i+1,arr[i]);
    }
    
    printf("\nEnter the index and element you want to insert\n");    
    printf("Element: ");
    scanf("%d",&element);
    printf("Index: ");
    scanf("%d",&index);

    used_size++;
    for(int i=0;i<used_size;i++)
    {
        if(i==index)
        {
            used_size++;
            arr[i]=element;
            // arr
        }
        
    }

    return 0; 
}