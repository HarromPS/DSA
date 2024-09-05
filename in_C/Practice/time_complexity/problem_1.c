#include <stdio.h>

// TIME COMPLEXITY
// Q1. Find the time complexity of the function in the program below

void function(int arr[], int length) // one method to pass array in a function
{
    int sum = 0;     //  f1 = k1 time
    int product = 1; //

    for (int i = 0; i < length; i++) //  f2 = k2 * length times
    {                                //
        sum += arr[i];               //
        product += arr[i];           //
    }
    printf("The sum is: %d\n", sum);         //  f3 = k3 times
    printf("The product is: %d\n", product); //
}

// The time complexity is given by
/*
    length = input size

    T(length)= F1 + F2 + F3
    T(length)= K1 + K2 * length + K3
    T(length)= n               ..... neglect k1 and k2 as they are less dominant
                               ..... drop constant k2
    Therefore, T(n)= O(length)
*/

int main()
{
    int arr[] = {1, 2, 3};
    function(arr, 3);
    
    return 0;
}