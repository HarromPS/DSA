#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,int> map;
    map['I']=1;
    map['V']=5;
    map['X']=10;
    map['L']=50;
    map['C']=100;
    map['D']=500;
    map['M']=1000;
    int n=123,temp=0;
    while(n>0){
        int rem = n%10;
        temp=(temp*10)+rem;
        n=n/10;
    }
    cout<<temp;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){

    }
    return 0;
}
