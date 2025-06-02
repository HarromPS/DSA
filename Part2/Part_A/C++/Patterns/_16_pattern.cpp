#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
A 
B B 
C C C 
D D D D 
E E E E E 
*/
void printPattern(int n){
    int x  = 65;
    for(int i=1;i<=n;i++){
        char ch = x;
        for(int j=1;j<=i;j++){
            printf("%c ",ch);
        }
        cout<<endl;
        x+=1;
    }   
}
void printPattern2(int n){
    int x = 65;
    for(int i=0;i<n;i++){
        char ch = x;
        for(int j=0;j<=i;j++){
            printf("%c ",ch);
        }
        printf("\n");
        x+=1;

    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
    printPattern2(n);
}
     
                