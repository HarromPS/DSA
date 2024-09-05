#include<iostream>
#include<stdlib.h>
using namespace std;

// Coin Problem: 

// Coins: {1,4,5}
// sum: 13


// Solution:

int minIgnoreNone(int a,int b){
    if(a==-1){
        return b;
    }
    if(b==-1){
        return a;
    }

    return min(a,b);
}
int minCoins(int* coin,int sum,int size){
    int answer;
    if(sum==0){
        answer=0;
    }
    else{
        answer = -1;
        for(int i=0;i<size;i++){
            int subproblem = sum - coin[i];
            if(subproblem<0){
                continue;
            }

            answer = minIgnoreNone(answer, minCoins(coin, subproblem, size)+1);
        }
    }
    return answer;
}
int main(){
    int coins[] = {1,4,5};
    int size = sizeof(coins)/sizeof(int);

    // the solution will take a lot of time calculating the solution
    int sum = 149;

    int res = minCoins(coins,sum,size);
    cout<<res<<endl;
    return 0;
}