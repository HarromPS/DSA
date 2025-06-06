#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

1
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1
0 1 0 1 0 1

*/

void pattern1(int n){
    for(int i=0;i<n;i++){
        int toPrint=(i&1)==0?1:0; // if even row start with 1
        for(int j=0;j<=i;j++){
            std::cout<<toPrint<<" ";
            toPrint^=1; // flip it
        }
        std::cout<<std::endl;
    }
}

void solve()
{
    int n;
    std::cin>>n;
    pattern1(n);    
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
