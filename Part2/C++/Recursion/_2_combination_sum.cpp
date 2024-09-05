#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

/*
Combination sum: 

Given an array [2,3,6,7] and a target sum: 7 find all possible combination which forms the sum
*/

// parameters -> array, target, container vector
void CombinationSum(int index, int target, vector<int>& v,int size,int* arr){
    // base case

    // index reach to the end and target found to be zero, means sum reduced to zero
    if(index == size){
        // check if the target is found after length is reached

        // else even if target is zero and index is not reached, it will go down and try to access out of bound index
        if( target == 0){
            // print the stack
            cout<<"[";
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<"]";
            cout<<endl;
        }
        return;
    }

    // pick up the element if target is still able to reach
    if(target >= arr[index]){
        v.push_back(arr[index]);

        // call the left function call
        CombinationSum(index, target - arr[index], v,size,arr);

        // dont pick, remove out the element when function call is back/returned
        v.pop_back();
    }


    // call right function call to get the next index element
    CombinationSum(index+1,target, v,size,arr);

}
int main(){
    int arr[] = {2,3,6,7};
    int size = sizeof(arr)/sizeof(int);
    int target = 7;
    vector<int> v;

    // so the possible combination for the target sum is: 
    CombinationSum(0, target, v, size, arr);
    return 0;
}