#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
**********
*        *
*        *
*        *
*        *
*        *
*        *
*        *
*        *
**********
*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==(n-1)){
                printf("*");
            }
            else if(j==0 || j==(n-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        cout<<endl;
    }
}

void printPattern2(int n){
    // run for boundaries only
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
    printPattern2(n);
}
     
                