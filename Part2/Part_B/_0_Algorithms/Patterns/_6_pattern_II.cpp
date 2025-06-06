#include <bits/stdc++.h>
// using namespace std;
#define ll long long
#define mod 1000000007

// pattern
/*

$$$$*$$$$
$$$*$*$$$
$$*$*$*$$
$*$*$*$*$
*$*$*$*$*    

    *    
   * *   
  * * *  
 * * * * 
* * * * *
        
*/

void solve()
{
    int n;
    std::cin>>n;
    int rows=n;
    int cols=(2*n-1);
    for(int row=0;row<n;row++){
        int isEvenRow=(row&1) == 0 ? 1:0;
        int leftStars=((row+1)/2)+1;
        int rightStars=(row+1)-leftStars;

        if(isEvenRow){
            leftStars=((row+1)/2)+1;
            rightStars=(row+1)-leftStars;
        }else{
            leftStars=(row/2)+1;
            rightStars=(row/2)+1;
        }

        // left 
        for(int j=0;j<=(cols/2);j++){
            if(isEvenRow){
                // even column
                if((j&1) == 0 && j>=(cols/2)-((leftStars-1)*2)){
                    std::cout<<"*";
                }else{
                    std::cout<<" ";
                }
            }
            else{
                // odd column
                if((j&1) == 1 && j>=(cols/2)-((leftStars*2)-1)){
                    std::cout<<"*";
                }else{
                    std::cout<<" ";
                }
            }
        }

        for(int j=(cols/2)+1;j<cols;j++){
            if(isEvenRow){
                // even column
                if((j&1) == 0 && j<=(cols/2)+(rightStars*2)){
                    std::cout<<"*";
                }else{
                    std::cout<<" ";
                }
            }
            else{
                // odd column
                if((j&1) == 1 && j<=(cols/2)+((rightStars*2)-1)){
                    std::cout<<"*";
                }else{
                    std::cout<<" ";
                }
            }
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
