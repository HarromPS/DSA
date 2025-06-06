#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

A 
A B 
A B C 
A B C D 
A B C D E 


*/

void pattern1(int n){
    char toPrint=65;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            std::cout<<toPrint<<" ";
            toPrint+=1;
        }
        toPrint=65;        
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
