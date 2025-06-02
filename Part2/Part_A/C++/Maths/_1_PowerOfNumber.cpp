#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long iterativePower(long x,long n){
    if(x==1) return 1;  // if number is 1 
    if(n==0) return 1;  // if raised to is 0
    if(n==1) return x;  // if raised to is 1
    long ans = (long)x;

    /*
        e.g x=5, n=3
        x=5
        n=1,    x=5*5=25
        n=2,    x=25*5=125

        therefore, pow(5,3) => 125
    */
    for(int i = 1; i < n; i++){
        ans = ans*x;  // multiply with previous number
    }
    return ans;
}


long recursivePower(int x,int n){
    if(x==1) return 1;  // 1^n is 1
    if(x==0) return 0;  // 0^n is 0 
    if(n==0) return 1;  // x^0 is 1

    // for all other cases
    if(n==1){
        return (long)x;
    }

    return (long)(recursivePower(x,n-1)*x);
}
void solve()
{
    // Power of a number is defined as : pow(x,n)
    // e,g x = 5, n = 2
    // power of x: x^n => pow(5,2): 5^2

    // 2 ways 

    int x=0,n=0;
    cin>>x>>n;

    // 1. iterative
    long ans = iterativePower(x,n);
    cout<<"Iterative power: "<<ans<<endl;

    // 2. recursive
    ans = recursivePower(x,n);
    cout<<"Recursive Power: "<<ans<<endl;

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
