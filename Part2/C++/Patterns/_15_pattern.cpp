#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
A B C D E 
A B C D 
A B C 
A B 
A 
*/
void printPattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<(n-i+1);j++){
            printf("%c ",j+65);
        }
        cout<<endl;
    }
}

void printPattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=(n-i-1);j++){
            printf("%c ",j+65);
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
     
                