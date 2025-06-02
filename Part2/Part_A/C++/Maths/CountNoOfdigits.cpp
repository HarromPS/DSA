#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given a positive integer n, count the number of n digit numbers  that contain at least one digit '7'. 
Since the answer could be large, compute it modulo 10^9+ 7.

Input:
n = 2

Output:
18

Explanation:
2-digit numbers that contain at least one digit '7' are
17, 27, 37, 47, 57, 67, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 87, 97. So, the answer is 18.
*/

long long customPower(long long x, long long n){
    // binary + modular exponentiation
    long long ans = 1;
    while(n>0){
        if(n%2==1){
            ans = (ans*x)%mod;
            n = n-1;
        }else{
            x = (x*x)%mod;
            n = n/2;
        }
    }

    return ans;
}
void solve()
{
    // Approach
    // 1. Instead of counting nos which contains 7 count which do not
    // 2. subtract from total count of numbers of n-digit nos

    // Note: This algo gives count of number of n digit no, that contains at least 1 digit "P": 7 or 8,9,...

    int n;
    cin>>n;

    // modular exponentiation
    long long total_n_digit_numbers = 9 * customPower(10, n-1)%mod;
    long long without_p_currently_is_7 = 8 * customPower(9, n-1)%mod;

    // ensures non negative result + in range
    long long with_p_currently_is_7 = (total_n_digit_numbers - without_p_currently_is_7 + mod)%mod;

    cout<<"The number of n digit numbers  that contain at least one digit '7': "<<with_p_currently_is_7<<endl;

    int a = 59;
    int b = 90;
    cout<<(a-b)<<endl;
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
