#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Palindrome
*/

class Solution{
public:
    bool palindrome(int n){
        // Write your code here
        int rev=0;
        int temp=n;
        int x=10;
        while(temp>0){
            rev = temp%10 + rev*x;
            temp/=10;
        }
        temp=n;
        while(temp >0 && rev>0){
            if(temp%10!=rev%10) return false;
            temp/=10;
            rev/=10;
        }
        return true;
    }

};

void solve()
{
    int num;
    cin>>num;
    Solution s;
    bool res = s.palindrome(num);
    cout<<"Optimal 4:"<<res<<endl;

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
