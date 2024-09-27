#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Check if a number is prime 
*/

// Brute force:
// T.C: O(10^d x d)
class Solution{
public:
    int isPrime(int n){
        if(n==1) return 0;
        if(n==2 || n==3 || n==5) return 1;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
        return 1;
    }

    int isPrime_2(int n){
        if(n <= 1) return 0;  // 0 and 1 are not prime
        if(n == 2 || n == 3) return 1;
        if(n % 2 == 0 || n % 3 == 0) return 0;
        for(int i = 5; i * i <= n; i += 6){
            if(n % i == 0 || n % (i + 2) == 0) return 0;
        }
        return 1;
    }
};

void solve()
{
    int n;
    cin>>n;
    Solution s;
    int res = s.isPrime(n);
    cout<<(res==1?"Yes":"No")<<endl;
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
