#include<iostream>
#include<cstdio>
using namespace std;

// Finding duplicate elements in the array
int main(){
    int arr[5]={1,3,3,4,4};
    int count,integer[5];
    for(int i=0;i<5;i++)
    {
        count=0;
        for(int j=i;j<5;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }  
        if(count>1){
        printf("\n%d is a duplicate element in the array\n",arr[i]);
        printf("%d occured: %d times\n",arr[i],count);
        }
    }
    
    return 0; 
}