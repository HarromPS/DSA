#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
using namespace std;

/*
Combination sum: 

Given an array [1,1,1,2,2] and a target sum: 4
find all possible combination which forms the sum

Note: it can use each element only once, also there should be no duplicate combinations
Lexicographical sorted order

Note: sort the array before hand
*/

void CombinationSum(int index,int target,vector<int>& v,int size,int* arr){
    // base case
    if(target == 0){
        // print the combination
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // set<int> s;

    // add all vector element
    // for(int i=0;i<v.size();i++){
    //     s.insert(v[i]);
    // }

    // loop the elements to pick or not pick 
    for(int i=index; i<size;i++){
        // check if the sequence is duplicate or not, check if the occurance is there 
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }

        // if target is unreachable
        if(arr[i] > target){
            break;
        }
        // pick or not pick
        
        // pick 
        v.push_back(arr[i]);

        // call the pick function
        CombinationSum(i+1,target - arr[i], v,size,arr);

        // dont pick
        v.pop_back();
        }
}

int main(){
    int arr[] = {1,1,1,2,2};
    int size = sizeof(arr)/sizeof(int);
    int target = 4;

    vector<int> s;
    CombinationSum(0,target,s,size,arr);
    return 0;
}