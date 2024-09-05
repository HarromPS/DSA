#include<iostream>
#include<cstdio>
using namespace std;

// GCD : greatest common divisor OR highest common divisor

// find gcd using long division method
int gcd(int A,int B){
    if(A==0){
        return B;
    }
    else if(B==0){
        return A;
    }
    return gcd(B,A%B);
}

int gcd2(int a,int b){
    return a%b!=0?gcd(b,a%b):a;
}

int main(){
    cout<<gcd(270,192)<<" "<<gcd2(270,192);
    return 0;
}