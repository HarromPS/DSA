#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

/*
Factorial
*/

class Solution{
public:
    int factorial_1(int num){
        // using loop

        // edge case 
        if(num<0) return -1;    // factorial of negative nos are not defined
        int ans=1;
        for(int i=1;i<=num;i++){
            ans=ans*i;
        }
        return ans;
    }

    // using recursion
    int factorial_2(int num){
        // edge case 
        if(num<0) return -1;    // factorial of negative nos are not defined

        // base case 
        if(num==0 || num==1) return 1;

        return num*factorial_2(num-1);
    }

};

void solve()
{
    // find factorial of a number 
    int n;
    std::cin>>n;

    Solution s;
    int res=s.factorial_1(n);   // using loop
    std::cout<<res<<std::endl;
    res=s.factorial_2(n);       // without using loop
    std::cout<<res<<std::endl;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    ll test;
    std::cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
