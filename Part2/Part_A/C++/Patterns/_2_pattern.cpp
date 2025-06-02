#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern :
/*

* 
* * 
* * * 
* * * * 
* * * * * 

*/

void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
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
    return 0;
}
     
                