#include <iostream>
#include <cstdio>
using namespace std;

bool *seiveOfEratoSthenes(int n)
{
    bool *isPrime = (bool *)calloc(sizeof(bool), n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false; // 0th indexed is marked false
    isPrime[1] = false; // 1 is marked as false

    // starting from 2
    for (int i = 2; i * i <= n; i++)
    { // i*i <= n :- upto sqrt

        for (int j = 2 * i; j <= n; j += i)
        { // start from its 2* no ans false its multiples
            // jump to j+i the index
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (isPrime[i] != 0)
        {
            cout << i << " ";
        }
        // cout<<isPrime[i]<<" ";
    }
    return isPrime;
}
int main()
{

    bool *ans = seiveOfEratoSthenes(12);
    for (int i = 0; i < 12 + 1; i++)
    {
        if (ans[i] != 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}