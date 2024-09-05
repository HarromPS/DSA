#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // Static memory allocation ==> cannot be changed
    int A[3];
    int *ptr[3]; // *ptr is a variable which stores the address of other
              // variables and values both using (*) == dereferencing operator

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the %d element of array: ", i + 1);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d element is: %d & its address is: %d( +4 )\n", i + 1,A[i],&A[i]);
    }

    ptr[0] = A; // ptr stores address of A
             // OR
    ptr[0] = &A[0];
    ptr[1] = &A[1];
    ptr[2] = &A[2];
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
     printf("%d element is: %d & its address is: %d( +4 )\n", i + 1,ptr[i],&ptr[i]);
    }

    // " A " <==> " &A[0] " ==> Name of the array is the address of
    // its 1st element

    // Address will be same
    printf("The address of'A' <==> '&A' is: %d\n", &A);
    printf("The address of'&A[0]' is: %d( +4 )\n", &A[0]);
    printf("The address of'&A[1]' is: %d( +4 )\n", &A[1]);
    printf("The address of'&A[2]' is: %d( +4 )\n", &A[2]);

    return 0;
}