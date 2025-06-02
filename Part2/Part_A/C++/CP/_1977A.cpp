#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==m){
        cout<<"Yes"<<endl;
        return;
    }
    if(n<m){
        cout<<"No"<<endl;
        return;
    }
    if(n>m){
        if((n%2==0 && m%2==0) || (n%2==1 && m%2==1)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
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

    ll test;
    cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
