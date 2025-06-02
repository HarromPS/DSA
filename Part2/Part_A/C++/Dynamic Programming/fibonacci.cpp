#include<iostream>
#include<stdlib.h>
using namespace std;

// implementation of fibonacci series 

// This solves in O((1+sqrt(5))/2)^n

int function(int n){
    if(n<=2){
        return 1;
    }
    int result = function(n-1) + function(n-2);
    return result;
}
int main(){
    printf("%d\n",function(50));
    return 0;
}