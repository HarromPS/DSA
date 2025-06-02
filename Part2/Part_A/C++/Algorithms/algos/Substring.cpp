#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    string s="hello";
    int start=0;
    int end=3;
    string ans = string(&s[start], &s[end+1]);  // (start, end) end is excluded so +1
    cout<<s<<endl;
    cout<<ans<<endl;
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


