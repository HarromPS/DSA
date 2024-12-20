#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Kth largest factor of N
ip: 12 , so factors are: (1,2,3,4,6,12)
3rd largest is : 4,hence is answer 
*/

int KthLargestFactor(int n,int k){
    // start from last
    k--;
    for(int i=n-1;i>=1 && k>0;i--){
        if(n%i==0){
            k--;
        }
        if(k==0) return i;
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int res=KthLargestFactor(n,k);
    cout<<res<<endl;

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
