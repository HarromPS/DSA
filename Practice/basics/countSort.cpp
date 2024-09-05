#include<iostream>
#include<cstdio>
using namespace std;

// Non-comparison based algorithm
// get count of every digit & sort until by reducing 1 from its index util zero

class Solution{
public:
    int* countSort(int* arr,int n){
        int m = maxDigit(arr,n);
        int count[m+1];
        for(int i=0;i<=m;i++){
            count[i]=0;
        }
        for(int i=0;i<n;i++){
            count[arr[i]]+=1;
        }
        int *temp=(int*)malloc(sizeof(int)*n);
        int k=0;
        for(int i=0;i<=m;i++){
            while(count[i]>0){
                count[i]-=1;
                temp[k]=i;
                k++;
            }
        }
        return temp;
    }
    int maxDigit(int* arr,int n){
        int max=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max)
            max=arr[i];
        }
        return max;
    }
    void printArray(int *arr,int n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n=7;
    int *a=(int*)malloc(sizeof(int)*n);
    int temp[]={2,1,2,3,1,2,4};
    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
    Solution s;
    a=s.countSort(a,n);
    s.printArray(a,n);
    return 0;
}