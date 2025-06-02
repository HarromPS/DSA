#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// Bottom Up approach: where we assume that dependencies are already solved

/*
for e.g 
To find nth fibonacci number we need n-1 and n-2 which are already solved
*/

int fib(vector<int>& v,int n){

    // to get current fib number 
    int res = 0;

    // iterate upto nth position
    for(int i=1;i<n+1;i++){

        // if position is <=2 only for i=1,2 
        if(i <= 2){
            res = 1;
        }

        // any any time it will calculate n-1 + n-2
        else{
            res = v[i-1] + v[i-2];
        }

        // it is stored in current ith position
        v[i] = res;

    }

    // return the last nth fibonacci number
    return v[n];
}
int main(){
    int n = 5;
    vector<int> v(n+1,0);
    cout<<fib(v,n)<<endl;

    return 0;
}