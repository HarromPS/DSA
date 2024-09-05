#include<iostream>
#include<cstdio>
using namespace std;

// find the power of any number
int power(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1!=0){
            ans=ans*a;
        }
        a = a*a;    // (a^2)^(b/2)
        b>>=1;      // half of b
    }
    return ans;
}

// for bigger nos e.g (342324, 5)
long powerBig(long a, long b,int n){
    long ans=1;
    while(b>0){
        if(b&1!=0){
            ans = (ans * a%n)  % n;     // (a+b)%n = (a%n + b%n)%n
        }
        a = (a%n * a%n);    // (a*b)%n = (a%n * b%n)%n
        b = b>>1;
    }
    return ans;
}
int main(){
    cout<<(2>>1);
    cout<<(2/2)<<endl;
    cout<<power(3,5)<<endl;
    cout<<powerBig(3239232,5,1000000007);
    return 0;
}