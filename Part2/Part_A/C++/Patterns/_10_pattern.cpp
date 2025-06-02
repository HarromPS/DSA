#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*

*
**
***
****
*****
****
***
**
*


*/
void printPattern(int n){
    for(int i=0;i<2*n;i++){
        if(i<(2*n)/2){
            for(int j=0;j<=i;j++){
                printf("*");
            }
        }
        else{
            for(int j=0;j<(2*n)-i-1;j++){
                printf("*");
            }
        }
        if(!(i==(2*n)-1)){
            cout<<endl;
        }
    }
}
void printPattern2(int n){
    for(int i=1;i<(2*n);i++){
        int stars = (i>n ? (2*n)-i : i);
        for(int j=1;j<=stars;j++){
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
    printPattern2(n);
    return 0;
}

     
                