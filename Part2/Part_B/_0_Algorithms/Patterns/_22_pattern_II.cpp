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
void pattern1(int n,int i){
    for(int j=0;j<n;j++){
        if(j>=i){
            std::cout<<(n-i);
        }else{
            std::cout<<(n-j);
        }
    }
}

/*
4444
3334
2234
1234

*/
void pattern2(int n,int i){
    for(int j=1;j<n;j++){
        if(j>=(n-i)){
            std::cout<<(j+1);
        }else{
            std::cout<<(n-i);
        }
    }
}
/*

4321
4322
4333
4444
*/
void pattern3(int n,int i){
    for(int j=0;j<n;j++){
        if(j>=i){
            std::cout<<(n-i);
        }else{
            std::cout<<(n-j);
        }
    }
}
/*
1234
2234
3334
4444

*/
void pattern4(int n,int i){
    for(int j=1;j<n;j++){
        if(j>=(n-i)){
            std::cout<<(j+1);
        }else{
            std::cout<<(n-i);
        }
    }
}

void solve()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        pattern1(n,i);
        pattern2(n,i);
        std::cout<<std::endl;
    }
    
    for(int i=1;i<n;i++){
        pattern3(n,n-i-1);
        pattern4(n,n-i-1);
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
