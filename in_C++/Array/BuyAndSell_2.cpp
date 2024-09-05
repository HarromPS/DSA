#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

// Buy & sell stocks for only one share multiple days & get max profit
int buy_sell(int arr[],int n){
    // iterate all the prices and chaek if price of next day is greater than current
    int max=0;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            max+=abs(arr[i] - arr[i-1]);
        }
    }
    return max;
}
int main(){
    int arr[] = {5,2,7,3,6,1,2,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<buy_sell(arr,n)<<endl;
    return 0;
}