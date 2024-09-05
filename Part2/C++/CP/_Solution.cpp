#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int mx=0;
    int x = 1;  // for alice
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        if(ip >= mx){
            mx = ip;
        }else{
            if(x==1){
                // not able to pick it up, if alice then she does not win
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
            return;
        }
        // change turn
        x^=1;
    }
    if(x==1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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
