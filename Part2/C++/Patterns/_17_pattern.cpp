#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
    A    
   ABA   
  ABCBA  
 ABCDCBA 
ABCDEDCBA
*/
void printPattern(int n){
    int x = 65;
    for(int i=0;i<n;i++){
        // space
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }

        // number
        char ch = x;
        int flag=0;
        for(int j=0;j<2*i+1;j++){
            if(j<=(((2*i)+1)/2)){
                printf("%c",ch);
                ch++;
                if(j==(((2*i)+1)/2)){
                    ch--;
                }
            }
            else{
                --ch;
                printf("%c",ch);
            }
        }

        // space
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        cout<<endl;
    }
}
void printPattern2(int n){
    int x = 65;
    for(int i=0;i<n;i++){
        // space
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }

        // number
        char ch = x;
        int breakPoint=0;
        for(int j=0;j<2*i+1;j++){
            printf("%c",j+ch);
            if(j<breakPoint){
                ch++;
            }
            else{
                ch--;
            }
        }

        // space
        for(int j=0;j<n-i-1;j++){
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
}
     
                