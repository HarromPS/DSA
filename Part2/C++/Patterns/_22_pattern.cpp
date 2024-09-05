#include<iostream>
#include<stdlib.h>
using namespace std;

// Pattern 

/*
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
void printPattern(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top = i;
            int left = j;
            int right = (2*n-1)-j-1;
            int bottom = (2*n-1)-i-1;
            printf("%d",4-min(min(top,right), min(left,bottom)));
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
     
                