#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    // Calculate prefix sum array
    // formula: A[i] = A[i]+A[i-1];

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // calculate prefix sum
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        arr[i] = arr[i]+arr[i-1];
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    // calculate ranges
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x!=0){
            cout<<arr[y]-arr[x-1]<<" ";
        }else{
            cout<<arr[y]<<" ";
        }
    }

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
