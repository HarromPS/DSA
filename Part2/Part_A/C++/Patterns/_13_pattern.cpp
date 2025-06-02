#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 
/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
*/
void printPattern(int n){
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",x);
            x++;
        }
        cout<<endl;
    }
}
void printPattern2(int n){
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",x);
            x++;
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
     
                