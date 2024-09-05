#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// IN C language "structures" are used for ADT implementation
// Implementation of ADT of Array Data type.
// Creating my custom datatype to classify data structures

// Structure of myArray
struct myArray
{
    // Set Of Values with NO RESERVED MEMORY
    int total_size;
    int used_size;
    int *ptrA; 
};

// Creating a Function to create my Array which returns nothing
void createArray(struct myArray *ptr, int Tsize, int Usize)
{
    // Parameterized with pointer of the struct myArray type
    // i.e (struct myArray A;) by passing its address to the function

    // Accessing the members of the struct myArray using :
    // Dereferencing (*) & Dot (.) OR Arrow operator (->)

    // RESERVING THE MEMORY BLOCK FOR total_size, used_size & ptr of struct
    // DYNAMICALLY FROM HEAP
    (*ptr).total_size = Tsize; // (*) & (.) operator
    ptr->used_size = Usize;    // (->) operator

    // Dynamic Memory allocation from HEAP memory
    // int* ptr=(int *)malloc(sizeof(int)*Usize);
    // Similarly ;

    // Updating its pointer itself that's why function is not returning anything
    (*ptr).ptrA = (int *)malloc(sizeof(int) * Usize);
}

// Creating a Show function to display the memory reserved/allocated
void Show(struct myArray *ptr)
{
    for (int i = 0; i < ptr->used_size; i++)
    {
        printf("%d element :: %d\n", i + 1, (ptr->ptrA)[i]);
    }
}

// Creating a Set function to initialize the members of the object *ptr
void Set(struct myArray *ptr)
{
    int n = 0;
    for (int i = 0; i < ptr->used_size; i++)
    {
        printf("Enter %d element\n::", i + 1);
        scanf("%d", &(ptr->ptrA)[i]);

        // Both are OK
        // scanf("%d", &n);
        // (ptr->ptrA)[i] = n;
    }
}

int main()
{
    // Creating an instance/example/case/sample of the myArray datatype
    // struct myArray

    struct myArray A;
    // Calling Create my Array function
    createArray(&A, 5, 2);

    printf("WE are now in Set Function\n");
    Set(&A);

    printf("WE are now in Display Function\n");
    Show(&A);

    free(A.ptrA);
    return 0;
}
