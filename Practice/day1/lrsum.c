#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int* leftRigthDifference(int* nums, int size, int* returnSize){
    int v[size+size];
    int k = 0,l=0;
    v[0]=0;
    v[(size+size)-1]=0;
    for (int i = 1; i < size; i++)
    {
        k+=nums[i - 1];
        l+=nums[size-i];
        v[i]=k;
        v[(size+size)-1-i]=l;
    }
     for (int i = 0; i < size; i++)
    {
       v[i]=abs(v[i]-v[size+i]);
       nums[i]=v[i];
    }
    *returnSize=size;
    return nums;
}
int main(){
    int *nums=(int*)malloc(sizeof(int)*4);
    nums[0]=10;
    nums[1]=4;
    nums[2]=8;
    nums[3]=3;
    int k=0;
    nums=leftRigthDifference(nums,4,&k);
    return 0;
}