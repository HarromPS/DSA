#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// return the count of total subsequences

int printS(int index,int n,vector<int>& arr,int* num,int sum,int targetSum){
    // base case
    if(index>=n || sum>targetSum){
        // condition satisfied
        if(sum==targetSum){
           return 1;
        }   

        // if not satisfied        
        else return 0;
    }

    // pick the item and add its sum
    arr.push_back(num[index]);
    sum = sum+num[index];

    // call the function to pick or not pick next element
    int leftFunctionCall = printS(index+1,n,arr,num,sum,targetSum);

    // dont pick the element and remove it from the sum
    arr.pop_back();
    sum = sum - num[index];

    // call function to pick or not pick next element
    int rightFunctionCall = printS(index+1,n,arr,num,sum,targetSum);

    return leftFunctionCall + rightFunctionCall;
}
int main(){
    int num[] = {1,2,1};
    int size = sizeof(num)/sizeof(int);
    int targetSum = 2;
    vector<int> ans;

    cout<<printS(0,size,ans,num,0,targetSum)<<endl;
    return 0;
}