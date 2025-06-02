#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int x=0,y=0,flag=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int n;
            cin>>n;
            if(n==1){
                x=i;
                y=j;
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<(abs(2-x)+abs(2-y))<<endl;
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
