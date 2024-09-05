#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    // Dynamic memory allocation ==> can be changed
    int n;
    printf("Enter the size of your array: ");
    scanf("%d", &n);

    // Allocating memory for "n" size
    int *A;

    // *A is a pointer & will points to the memory allocated
    // A stores the address of &A[0] == A
    A = (int *)malloc(n * sizeof(int));

    int *ptr; // *ptr is a variable which stores the address of other
                 // variables and values both using (*) == dereferencing operator

    ptr=A;      // ptr storing address of 1st element of A ==> &A[0]
    //OR
    ptr=&A[0];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of array: ", i + 1);
        // Storing values at the address of A[i]
        scanf("%d", &A[i]);
    }
    // *(A) <==> *(address)
    printf("Displaying values '*A' with A++ \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d element is: %d\n", i + 1, *(A));
        A++;
    }

    printf("Displaying values with other pointer '*(ptr)=*A' ==> ptr=A \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d element is: %d\n", i + 1, *(ptr));
        ptr++;
    }
    // OR
    printf("Displaying addresses of 'A[i]'\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d element is: %d\n", i + 1, A[i]);
    }
    printf("\n");
    printf("Displaying addresses of '&A[i]'\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d's address is: %d\n", i + 1, &A[i]);
    }

    return 0;
}