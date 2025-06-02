#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 
*/
void printPattern(int n){
    for(int i=1;i<=n;i++){
        int bin=(i%2==0 ? 0 : 1);
        for(int j=1;j<=i;j++){
            printf("%d ",bin);
            bin = !bin;
        }
        printf("\n");
    }
}

void printPattern2(int n){
    for(int i=0;i<n;i++){
        int bin=(i%2==0 ? 1 : 0);
        for(int j=0;j<=i;j++){
            printf("%d ",bin);
            bin = !bin;
        }
        printf("\n");
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
     
                