#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAX 1000
bool hashTable[MAX+1][2];

// for +ve & -ve nos placing
void insert(int* arr,int size){
    for(int i=0;i<size;i++){
        if(arr[i]>=0){
            hashTable[arr[i]][0]=1;
        }
        else {
            hashTable[abs(arr[i])][1]=1;
        }
    }
}

bool search(int element){
    if(element>=0){
        if(hashTable[element][0]==1){
            return true;
        }
        else {
            return false;
        }
    }else {
        if(hashTable[abs(element)][1]==1){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    int array[]={23,-2,23,14,3,-21};
    int size=sizeof(array)/sizeof(int);
    insert(array,size);
    int result=search(-12);
    if(result==1){
        printf("^^^^^^^^^^  Element is present in Hash Table  ^^^^^^^^^^");
    }
    else {
    printf("@@@@@@@@@  Element not present in Hash Table  @@@@@@@@@");

    }
    return 0;
}