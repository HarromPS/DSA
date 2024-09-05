#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// What if we want one answer 
bool printS(int index,int n,vector<int>& arr,int* num,int sum,int targetSum){
    if(index>=n || sum>targetSum){
        // condition satisfied
        if(sum==targetSum){
            for(auto iter: arr){
                cout<<iter<<" ";
            }
            cout<<endl;
            return true;
        }

        // if not satisfied 
        return false;
    }

    // pick the item and add its sum
    arr.push_back(num[index]);
    sum = sum+num[index];

    // check if the function call got any solution so that further recursion calls can be avoided
    if(printS(index+1,n,arr,num,sum,targetSum)==true){
        return true;
    }

    // dont pick the element and remove it from the sum
    arr.pop_back();
    sum = sum - num[index];

    // call function to pick or not pick next element
    if(printS(index+1,n,arr,num,sum,targetSum)){
        return true;
    }

    // return false until a solution is found
    return false;
}
int main(){
    int num[] = {1,2,1};
    int size = sizeof(num)/sizeof(int);
    int targetSum = 2;
    vector<int> ans;

    printS(0,size,ans,num,0,targetSum);
    return 0;
}