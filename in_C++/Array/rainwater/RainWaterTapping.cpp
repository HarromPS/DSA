#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

/*
Logic:
1) water is filled -> at any index when its left & right building is bigger
2) Preprocessing(Auxillary arrays) -> for every index find its max & min building height
3) water is filled upto the level only upto snmaller building min(left, right)
*/

int rainWatertapping(int arr[],int n){
    int max=0,temp=-1;

    // preprocessing
    int left[n],right[n];

    // left max building
    for(int i=0;i<n;i++){
        if(temp < arr[i]){
            temp=arr[i];
        }
        left[i] = temp;
        cout<<left[i]<<" ";
    }

    cout<<endl;
    temp=-1;
    // right max building
    for(int i=n-1;i>=0;i--){
        if(temp < arr[i]){
            temp=arr[i];
        }
        right[i] = temp;
        cout<<right[i]<<" ";
    }

    // find max water filled
    for(int i=1;i<n-1;i++){
        max += (min(left[i],right[i]) - arr[i]);
    }

    return max;
}
int main(){
    int arr[]={3,1,2,4,0,1,3,2};
    int n=sizeof(arr)/sizeof(int);
    cout<<"\n"<<rainWatertapping(arr,n);
    return 0;
}