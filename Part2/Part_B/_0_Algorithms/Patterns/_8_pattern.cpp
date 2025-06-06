#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*
* * * * * * * * * 
  * * * * * * *  
    * * * * *   
      * * *    
        *          
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 
        
*/

void pattern1(int n){
    int cols=(2*n)-1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(cols);j++){
            if(j>=(cols/2)-i && j<=(cols/2)+i){
                std::cout<<"* ";
            }else{
                std::cout<<"  ";
            }
        }
        std::cout<<std::endl;
    }
}

void pattern2(int n){
    int cols=(2*n)-1;
    for(int i=1;i<n;i++){
        // space 
        for(int j=0;j<(cols/2)-i;j++){
            std::cout<<"  ";
        }
        // star
        for(int j=(cols/2)-i;j<=(cols/2)+i;j++){
            std::cout<<"* ";
        }
        // space
        for(int j=(cols/2)+i+1;j<cols;j++){
            std::cout<<"  ";
        }
        std::cout<<std::endl;
    }
}

void solve()
{
    int n;
    std::cin>>n;
    pattern1(n);
    pattern2(n);
    
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
