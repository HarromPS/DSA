#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 * Given two integers s and d.
 * The task is to find the smallest number such that
 * the sum of its digits is s and the number of digits in the number are d.
 * Return a string that is the smallest possible number.
 * If it is not possible then return -1.
 *
    Input: s = 9, d = 2
    Output: 18
    Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.

    Input: s = 20, d = 3
    Output: 299
    Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
*/

// Brute force:
// T.C: O(10^d x d)
string smallestNumber(int s, int d)
{
    // code here
    if (s < 10 && d <= 1)
    {
        string res = to_string(s);
        return res;
    }

    for (int i = 11; i <= pow(10, d); i++)
    {
        int num = i;
        int sum = 0;
        int digits = 0;
        while (num > 0)
        {
            sum += (num % 10);
            num /= 10;
            digits += 1;
        }
        if (sum == s && digits == d)
        {
            return to_string(i);
        }
    }
    return "-1";
}
// Better
// Expected Time Complexity: O(d)
// Expected Auxiliary Space: O(1)
string smallestNumber_Better(int s, int d)
{
    // code here
    if (s < 10 && d <= 1)
    {
        string res = to_string(s);
        return res;
    }

    // runs from min d digit number to max d digit number
    /*
    sum = 299, d = 3
    start from min 3 digit number -> 10^2 == 100 (min 3 digit number)
    end at max 3 digit number (10^3) == 1000 -1 => 999 (max 3 digit number)
     */
    int min = pow(10, d - 1);
    int max = pow(10, d) - 1;
    for (int i = min; i <= max; i++)
    {
        int num = i;
        int sum = 0;
        int digits = 0;
        while (num > 0)
        {
            sum += (num % 10);
            num /= 10;
            digits += 1;
        }
        if (sum == s && digits == d)
        {
            return to_string(i);
        }
    }
    return "-1";
}

void solve()
{
    int s, d;
    cin >> s >> d;

    cout << "Brute force: " << smallestNumber(s, d) << endl;
    cout << "Optimal approach: " << smallestNumber_Better(s, d) << endl;
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
    // cin >> test;
    // while (test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
