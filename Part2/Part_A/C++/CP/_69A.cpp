#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int corr[n][3];
    for(int i=0;i<n;i++){
        cin>>corr[i][0]>>corr[i][1]>>corr[i][2];
    }

    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            x += corr[i][0];
            y += corr[i][1];
            z += corr[i][2];
        }
    }
    if(x==0 && y==0 && z==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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
