#include<iostream>
#include<cstdio>
using namespace std;

// Select the lighest element & bring forward

class Solution{
public:
    void selectionSort(int* arr,int n){
        for(int i=0;i<n-1;i++){
            int minIndex = i;
            for(int j=i+1;j<n;j++){
                if(arr[minIndex] > arr[j]){
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    void printArray(int *arr,int n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n=6;
    int *a=(int*)malloc(sizeof(int)*n);
    int temp[]={40,20,60,10,50,30};
    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
    Solution s;
    s.selectionSort(a,n);
    s.printArray(a,n);
    return 0;
}