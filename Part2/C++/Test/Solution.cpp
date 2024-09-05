#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    string ans;
    cin>>ans;

    int marks=0;
    map<char,int> mp;
    for(int i=0;i<ans.size();i++){
        if(ans[i]!='?')
            mp[ans[i]]++;
    }

    for(auto it:mp){
        if(it.second == 0) continue;
        if(it.second >= n) marks+=n;
        else marks+=(it.second);
    }
    cout<<marks<<endl;


}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
