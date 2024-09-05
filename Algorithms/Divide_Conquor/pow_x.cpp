#include<iostream>
#include<cstdio>
using namespace std;

int power(int x,int p){
    int k=x;
    while(p>1){
        x=x*k;
        p--;
    }
    return x;
}
int main(){
    // write our own program pow(x,n) to find x^n
    int x=12;
    int p=4;

    // ans => 27
    int result = power(x,p);
    cout<<result<<endl;

   return 0;
}