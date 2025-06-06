#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007


// pattern
/*

4444444
4333334
4322234
4321234
4322234
4333334
4444444
        
*/

/*
4444
4333
4322
4321

*/
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                std::cout<<(n-i);
            }else{
                std::cout<<(n-j);
            }
        }
        std::cout<<std::endl;
    }
}

/*
4444
3334
2234
1234

*/
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=(n-i)){
                std::cout<<(j+1);
            }else{
                std::cout<<(n-i);
            }
        }
        std::cout<<std::endl;
    }
}
/*

4321
4322
4333
4444
*/

void pattern3(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j>=i){
                std::cout<<(n-i);
            }else{
                std::cout<<(n-j);
            }
        }
        std::cout<<std::endl;
    }
}

/*
1234
2234
3334
4444

*/

void pattern4(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j>=(n-i)){
                std::cout<<(j+1);
            }else{
                std::cout<<(n-i);
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
    std::cout<<std::endl;
    pattern2(n);
    std::cout<<std::endl;
    pattern3(n);
    std::cout<<std::endl;
    pattern4(n);
    std::cout<<std::endl;
    
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
