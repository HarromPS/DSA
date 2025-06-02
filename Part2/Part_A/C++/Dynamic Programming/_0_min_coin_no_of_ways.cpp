#include<iostream>
#include<stdlib.h>
using namespace std;

/* Coin Problem: 

Coins: {1,4,5}
sum: 13

Solution: 4 ways
1 + 1 + 1 + 1 
1 + 4 
4 + 1 
5 

In this problem, finding how many solutions are possible to make the target sum using the coins

*/

// Solution: Top Down Approach (Recursive)
// move through coins 
int minCoins(int* coin,int sum,int size){
    int ans=0;
    if(sum == 0){
        return 1;
    }

    else{

        // iterating for each coin
        for(int i=0;i<size;i++){
            int remSum = sum-coin[i];

            // skip the subproblem solution where sum is negative
            if(remSum<0){
                continue;
            }

            // add the subroblems return values in current sum answer
            ans = ans + minCoins(coin, remSum, size);
        }
    }   

    return ans;

   
}

int main(){
    int coins[] = {1,4,5};
    int size = sizeof(coins)/sizeof(int);

    int sum = 5; 
    int res = minCoins(coins,sum,size);
    cout<<res<<endl;
    return 0;
}