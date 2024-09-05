#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/
void printPattern(int n){
    // upper part
    for(int i=1;i<=n;i++){
        // stars 
        for(int j=0;j<i;j++){
            printf("*");
        }
        // space
        for(int j=0;j<(2*n)-(2*i);j++){
            printf(" ");
        }
        // stars 
        for(int j=0;j<i;j++){
            printf("*");
        }
        cout<<endl;
    }
    // lower part
    for(int i=1;i<n;i++){
        // stars 
        for(int j=0;j<n-i;j++){
            printf("*");
        }
        // space
        for(int j=0;j<2*i;j++){
            printf(" ");
        }
        // stars 
        for(int j=0;j<n-i;j++){
            printf("*");
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
}
     
                