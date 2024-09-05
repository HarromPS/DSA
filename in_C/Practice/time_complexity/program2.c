#include <stdio.h>

// Q2. Find the time complexity of the function in the program below
void function(int n)
{
    int sum = 0, count = 0; // F1 = K1 times 
    int product = 1;        // 

    // complete loop will run n*n times 

    for (int i = 0; i < n; i++)         // loop outside 
    {                                   // f2 = k2 * n times run
       
       
        for (int j = 0; j < n; j++)     // loop inside 
        {                               // f3 = k3 * n times run
            printf("%d , %d\n", i, j);
            count++;
        }
    }

    // f4 = k4 times 
    printf("The program will run for %d times \n", count);
}
/* 
    n= input size 

    The time complexity is given by, 
    T(n)= F1 + F2 + F3 + F4
    T(n)= K1 + K(n*n) + K4
    T(n)= n*n                     ..... neglect k1 and k4 as they are less dominant
                                ..... drop constant k
    Therefore, T(n)= O(n^2);
 */ 
int main()
{
    function(4);
    return 0;
}