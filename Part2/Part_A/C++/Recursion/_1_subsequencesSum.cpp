#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// subarrays i.e the power set
void printS(int index,int n,vector<int>& arr,int* num,int sum,int targetSum){
    if(index>=n || sum>targetSum){
        // check if sum is equal
        if(sum==targetSum){
            // print
            for(auto iter: arr){
                cout<<iter<<" ";
            }
            cout<<endl;
        }
        return;
    }

    // pick the item and add its sum
    arr.push_back(num[index]);
    sum = sum+num[index];

    // call the function to pick or not pick next element
    printS(index+1,n,arr,num,sum,targetSum);

    // dont pick the element and remove it from the sum
    arr.pop_back();
    sum = sum - num[index];

    // call function to pick or not pick next element
    printS(index+1,n,arr,num,sum,targetSum);
}
int main(){
    int num[] = {1,2,1};
    int size = sizeof(num)/sizeof(int);
    int targetSum = 2;
    vector<int> ans;

    printS(0,size,ans,num,0,targetSum);
    return 0;
}