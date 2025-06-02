#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
*********
 ******* 
  *****  
   ***   
    *  
*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        int k = ((2*n)-1)/2;
        for(int j=0;j<(2*n)-1;j++){
            if(j>=k-(k-i) && j<=k+(k-i)){
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
    for(int i=0;i<n;i++){
        int k = (2*n)/2;
        for(int j=1;j<2*n;j++){
            if(j >= k-(k-i)+1 && j <= k+(k-i)-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        cout<<endl;
    }
}
void printPattern3(int n){
    for(int i=0;i<n;i++){
        // space
        for(int j=0;j<i;j++){
            printf(" ") ;
        }
        // star
        for(int j=i;j<(2*n)-i-1;j++){
            printf("*");
        }
        // space
        for(int j=0;j<i;j++){
            printf(" ");
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
    printPattern3(n);
    return 0;
}
     
                