#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

1      1
12    21
123  321
12344321

*/

void pattern1(int n){
    for(int i=0;i<n;i++){
        // left pattern
        for(int j=0;j<n;j++){
            if(j<=i){
                std::cout<<(j+1);
            }else{
                std::cout<<" ";
            }
        }

        // right pattern
        for(int j=0;j<n;j++){
            if(j>=(n-i-1)){
                std::cout<<(n-j);
            }else{
                std::cout<<" ";
            }
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
