#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
    *    
   ***   
  *****  
 ******* 
*********
*********
 ******* 
  *****  
   ***   
    *    
*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*n)-1;j++){
            if(j >= (((2*n)-1)/2)-i && j <= (((2*n)-1)/2)+i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        cout<<endl;
    }

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
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
    return 0;
}
     
                