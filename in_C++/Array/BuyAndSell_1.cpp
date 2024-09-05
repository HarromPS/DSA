#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

// Buy & sell stocks for only one share for single day & get max profit
int buy_sell(int arr[],int n){
    // iterate all the prices and check for min so far & get max profit
    int max=0;
    int minSoFar=arr[0];
    for(int i=1;i<n;i++){
        if(minSoFar > arr[i]){
            minSoFar = arr[i];
        }
        if(max < abs(arr[i] - minSoFar)){
            max = abs(arr[i] - minSoFar);
        }
    }
    return max;
}
int main(){
    int arr[] = {3,1,4,8,7,2,3};
    int n = sizeof(arr)/sizeof(int);
    cout<<buy_sell(arr,n)<<endl;
    return 0;
}