#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int x,y;
    cin>>x>>y;
    if(x<=y){
        cout<<x<<" "<<y<<endl;
    }
    else{
        cout<<y<<" "<<x<<endl;
    }
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
