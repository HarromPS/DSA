#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

void gcd2(int a,int b)
{
    int m = min(a, b),g=0;

    for (int i = 1; i <= m; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            g = i;
        }
    }
    long l = (long(a) * long(b)) / g;
    cout << g << " " << l << endl;
}
int main()
{
    cout << gcd(98, 56)<<endl;
    gcd2(98, 56);
    // cout<<gcd(10213,312);
    return 0;
}