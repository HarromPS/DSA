#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int i=100;
    int num=0;
    while(i>0){
        num=(num*10)+i/10;
        i%=10;
    }
    cout<<num<<endl;
    return 0;
}