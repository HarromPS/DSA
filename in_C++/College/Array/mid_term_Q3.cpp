#include <iostream>
#include <cstdio>
using namespace std;

/*
    Define Stack in two lines - last in first out ( LIFO )  OR
                                First in last out ( FILO )
    Function to merge two sorted array input1 & input2 are numbers of
    m & n sizes. Create third sorted array
*/

// int i=0;
int Merge(int input1[], int input2[], int size)
{
    int Third_Sorted_array[size];
    for (int i = 0; i < size; i++)
        if (input1[i] < input2[i])
        {
            input1[i] = input2[i];
        }
}
int main()
{

    int input1[] = {1, 2, 3, 4, 5};     // Two Sorted arrays 
    int input2[] = {1, 2, 3, 4, 5};
    int size = sizeof(input1) / sizeof(int) + sizeof(input1) / sizeof(int);

    Merge(input1, input2, size);

    return 0;
}