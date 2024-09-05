#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
    int n = 15, ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1; // will get 1 or 0 i.e (0 even) & (1 odd)
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    printf("%d", ans);
    return 0;
}