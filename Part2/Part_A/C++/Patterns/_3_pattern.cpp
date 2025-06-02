#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*

1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5

*/

void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",j+1);
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
     
                