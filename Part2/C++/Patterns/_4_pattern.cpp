#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
*/

void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",i+1);
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
     
                