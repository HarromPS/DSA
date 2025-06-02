#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
A 
A B 
A B C 
A B C D 
A B C D E 
*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            char ch = j+65;
            printf("%c ",ch);
        }
        cout<<endl;
    }
}
void printPattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char ch = j+64;
            printf("%c ",ch);
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
     
                