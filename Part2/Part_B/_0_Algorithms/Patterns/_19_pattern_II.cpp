#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007


// pattern
/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
        
*/

/*

*****
****
***
**
*

*/
void pattern1(int n,int i){
    for(int j=0;j<n;j++){
        if(j<=i){
            std::cout<<"*";
        }else{
            std::cout<<" ";
        }
    }
}

/*

*****
 ****
  ***
   **
    *

*/
void pattern2(int n,int i){
    for(int j=0;j<n;j++){
        if(j>=(n-(n-i))){
            std::cout<<"*";
        }else{
            std::cout<<" ";
        }
    }
}

/*

*
**
***
****
*****

*/
void pattern3(int n,int i){
    for(int j=0;j<n;j++){
        if(j<=i){
            std::cout<<"*";
        }else{
            std::cout<<" ";
        }
    }
    
}

/*
    *
   **
  ***
 ****
*****

*/
void pattern4(int n,int i){
    for(int j=0;j<n;j++){
        if(j>=(n-(n-i))){
            std::cout<<"*";
        }else{
            std::cout<<" ";
        }
    }
}

void solve()
{
    int n;
    std::cin>>n;

    for(int i=0;i<n;i++){
        pattern1(n,n-i-1);
        pattern2(n,i);
        std::cout<<std::endl;
    }

    for(int i=0;i<n;i++){
        pattern3(n,i);
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
