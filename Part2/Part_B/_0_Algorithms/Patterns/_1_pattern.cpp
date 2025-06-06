#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

* * * 
* * * 
* * * 

*/

void solve()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
}

int main() 
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif

    // ll test;
    // std::cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
