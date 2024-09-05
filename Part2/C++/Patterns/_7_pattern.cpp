#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 
*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*n)-1;j++){
            if(j >= (((2*n)-1)/2)-i && j <= (((2*n)-1)/2)+i){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        cout<<endl;
    }
}
void printPattern_2(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<(2*n);j++){
            if(j >= ((2*n)/2)-i && j<= ((2*n)/2)+i){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        cout<<endl;
    }
}
void printPattern_3(int n){
    for(int i=0;i<n;i++){
        // space 
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        // star
        for(int j=0;j<(2*i)+1;j++){
            printf("*");
        }
        // space
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        printf("\n");
    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
    printPattern_2(n);
    printPattern_3(n);
    return 0;
}
     
                