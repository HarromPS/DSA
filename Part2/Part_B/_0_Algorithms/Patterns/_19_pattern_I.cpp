#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007


// pattern
/*
        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * *
* * * * * * * * * 
  * * * * * * *  
    * * * * *   
      * * *    
        *
 
        
*/

/*

*****
****
***
**
*

*/
void pattern1(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

/*

*****
 ****
  ***
   **
    *

*/
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=(n-(n-i))){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

/*

*
**
***
****
*****

*/
void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

/*
    *
   **
  ***
 ****
*****

*/
void pattern4(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j>=(n-(n-i))){
                std::cout<<"*";
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
    pattern2(n);
    pattern4(n);
    pattern1(n);
    pattern3(n);
    
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
