#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

    A    
   ABA   
  ABCBA  
 ABCDCBA 
ABCDEDCBA

*/

void pattern1(int n){
    int cols=(2*n)-1;
    char ch='A';
    for(int i=0;i<n;i++){
        // left 
        for(int j=0;j<=(cols/2);j++){
            if(j>=(cols/2)-i){
                std::cout<<(char)('A'+j-((cols/2)-i));
            }else{
                std::cout<<" ";
            }
        }

        // right
        for(int j=(cols/2)+1;j<cols;j++){
            int dist=cols/2;
            if(j<=(cols/2)+i){
                std::cout<<(char)(ch+(dist+i-j));
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

void pattern2(int n){
    int cols=(2*n)-1;
    for(int i=0;i<n;i++){
        // space
        for(int j=0;j<(cols/2)-i;j++){
            std::cout<<" ";
        }

        // pattern (increasing and then decreasing)
        int ch=64;
        for(int j=(cols/2)-i;j<=(cols/2)+i;j++){
            if(j<=(cols/2)){
                ch+=1;
                std::cout<<(char)(ch);
            }else{
                ch-=1;
                std::cout<<(char)(ch);
            }
        }

        // space
        for(int j=(cols/2)+i+1;j<cols;j++){
            std::cout<<" ";
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
