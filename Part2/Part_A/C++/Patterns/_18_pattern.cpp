#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
E
DE
CDE
BCDE
ABCDE
*/

void printPattern(int n){
    char ch = 65+(n-1);
    for(int i=1;i<=n;i++){
        char x = ch;
        for(int j=1;j<=i;j++){
            printf("%c",x);
            x++;
        }
        ch--;
        printf("\n");
    }
}

void printPattern2(int n){
    for(int i=0;i<n;i++){
        for(char ch = 'E'-i;ch<='E';ch++){
            printf("%c",ch);
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
     
                