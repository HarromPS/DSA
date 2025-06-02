#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// T.C: O(log n base 2)
// S.C: O(1)
double BinaryExponentiation(double x, int n)
{
    // finds the power of a number using exponentiation
    /*
    2^10 = (2 x 2)^5 = (4)^5 => 4 x 256 => 1024

    4^5 = 4 x 4^4 => 4 x 256

    4^4 = (4 x 4)^2 = (16)^2 => 256

    16^2 = (16 x 16)^1 = 256^1 => 256

    256^1 = 256^1 x 256^0 = 256

    /////////////////////////////////////////////

    2^10 = (2)^(5*2) = (2^2)^5 => 4^5

    4^5 = 4 x 4^4 => 4 x (4)^(2*2) => 4 x (4^2)^2 => 4 x (16)^2

    16^2 = (16)^(2*1) = (16^2)^1 => 256^1

    256^1 = 256 * 256^0 = 256

    so do until n is zero

    when n is even {
        multiply x*x
        half n=n/2
    }

    when n is odd{
        save x in ans i.e ans = ans * x
        one minus n=n-1
    }

    */
    // base cases
    if (n == 0)
        return 1;
    if (n == INT_MAX)
    {
        if (x == 1)
        {
            return 1;
        }
        else if (x == -1)
        {
            return -1;
        }
        return 0;
    }
    if (n == INT_MIN)
    {
        if (x == 1 || x == -1)
            return 1;
        return 0;
    }

    long nn = n;
    if (nn < 0)
        nn = nn * -1;

    double ans = 1.0;
    while (nn > 0){
        // if (n & 1 == 1)
        if (nn % 2 == 1){ // means odd
            ans = ans * x;
            nn = nn - 1;
        }else{ // means even
            x = x * x;
            // n = n >> 1; // half
            nn = nn / 2; // half
        }
    }

    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }

    return ans;
}

// T.C: O(n)
// S.C: O(1)
double iterativePow(double x, int n)
{
    // base cases
    if (n == 0)
        return 1;
    if (n == INT_MAX)
    {
        if (x == 1)
        {
            return 1;
        }
        else if (x == -1)
        {
            return -1;
        }
        return 0;
    }
    if (n == INT_MIN)
    {
        if (x == 1 || x == -1)
            return 1;
        return 0;
    }

    // other cases
    int flag = 0;
    if (n < 0)
    {
        // make it positive
        n = -n;
        flag = 1;
    }

    double ans = x;
    for (int i = 1; i < n; i++)
    {
        ans = ans * x;
    }
    if (flag == 1)
    {
        return (1 / ans);
    }
    return ans;
}

// if positive of not
/*
sign right shift operator (>>) shifts bits to right
if number is +ve: fills its trail with 0
if number is -ve: fills its trail with 1

a=5, b=-6
e.g a= 0000 0000 0000 0000 0000 0000 0000 0101 = 5
e.g a= 1111 1111 1111 1111 1111 1111 1111 1010 = 5

    a >> 31
    b >> 31

    a= 0000 0000 0000 0000 0000 0000 0000 0000 = 0
    b= 1111 1111 1111 1111 1111 1111 1111 1111 = -1

    n >> 31
    if(num == 0) "positive"
    else "negative"
 */

void isPositive(int num)
{
    if (num >> 31 == 0)
    {
        cout << "Positive" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }
}

void solve()
{
    // if n and x are negative

    // Power of a number is defined as : pow(x,n)
    // e,g x = 5, n = 2
    // power of x: x^n => pow(5,2): 5^2

    int num = 23;
    isPositive(num);
    num = -32;
    isPositive(num);

    double x, n;
    cin >> x >> n;

    // negative n or x
    double ans = iterativePow(x, n);
    cout << "Iterative negative Power: " << ans << endl;

    ans = BinaryExponentiation(x, n);
    cout << "Binary Exponentiation: " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
