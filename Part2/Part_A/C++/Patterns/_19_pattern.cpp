#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
++++++++++
++++  ++++
+++    +++
++      ++
+        +
++      ++
+++    +++
++++  ++++
++++++++++
*/
void printPattern(int n){
    // upper part
    for(int i=0;i<n;i++){
        // stars
        for(int j=0;j<n-i;j++){
            printf("+");
        }

        // spaces
        for(int j=0;j<2*i;j++){
            printf(" ");
        }

        // stars
        for(int j=0;j<n-i;j++){
            printf("+");
        }

        cout<<endl;
    }

    // down part
    for(int i=0;i<n-1;i++){
        // stars
        for(int j=0;j<=(i+1);j++){
            printf("+");
        }

        // spaces
        for(int j=0;j<(2*n)-2*(i+2);j++){
            printf(" ");
        }

        // stars
        for(int j=0;j<=(i+1);j++){
            printf("+");
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    printPattern(n);
}
     
                