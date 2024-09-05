#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Logic 1
    int n = 3, temp = n;
    int num = 0;
    while (n > 0)
    {
        num = (num * 10) + (n % 2);
        n /= 2;
    }
    printf("%d\n", num);
    n = temp;
    num = 0;
    while (n > 0)
    {
        num = (num * 10) + (n % 2);
        n = n >> 1;
    }
    printf("%d", num);

    // Logic 2
    n = 5, num = 0, temp = 0;
    while (n > 0)
    {
        int bit = n & 1; // will get 1 or 0 i.e (0 even) & (1 odd)
        num = (pow(10, temp) * bit) + num;
        temp++;
        n = n >> 1;
    }
    printf("\n%d", num);
    return 0;
}