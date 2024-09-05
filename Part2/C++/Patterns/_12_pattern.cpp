#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
1        1
12      21
123    321
1234  4321
1234554321
*/

void printPattern(int n){
    int k=2*(n-2)-1;
    for(int i=0;i<n-1;i++){
        // number
        for(int j=0;j<=i;j++){
            printf("%d",j+1);
        }
        // space
        for(int j=0;j<=k;j++){
            printf(" ");
        }
        // number
        for(int j=i+1;j>=1;j--){
            printf("%d",j);
        }
        
        k-=2;
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
}
     
                