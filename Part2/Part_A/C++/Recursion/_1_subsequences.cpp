#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

// subsequences i.e the power set
void printS(int index,int n,vector<int>& arr,int* num){
    if(index>=n){
        // print
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // pick the item and add its sum
    arr.push_back(num[index]);

    // call the function to pick or not pick next element
    printS(index+1,n,arr,num);

    // dont pick the element and remove it from the sum
    arr.pop_back();
    // call function to pick or not pick next element
    printS(index+1,n,arr,num);
}
int main(){
    int num[] = {1,2,1};
    int size = sizeof(num)/sizeof(int);
    vector<int> ans;

    printS(0,size,ans,num);
    return 0;
}