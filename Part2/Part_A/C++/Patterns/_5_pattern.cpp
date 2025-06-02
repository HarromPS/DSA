#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*

* * * * * 
* * * * 
* * * 
* * 
* 

*/
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=(n-1)-i;j++){
            printf("* ");
        }
        cout<<endl;
    }
}

// OR

void printPattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i)+1;j++){
            printf("* ");
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
    return 0;
}
     
                