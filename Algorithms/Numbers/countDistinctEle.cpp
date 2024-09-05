#include<iostream>
#include<cstdio>
using namespace std;

#include<unordered_set>
int main(){

    // BRUTE FORCE
    // int a[]={5,10,5,4,5,10,15};
    // int size=sizeof(a)/sizeof(a[0]);
    // int count=0;
    // int flag=0;
    // for(int i=0;i<size;i++){
    //     flag=0;
    //     for(int j=0;j<i;j++){
    //         if(a[j]==a[i]){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0){
    //         count++;
    //     }
    // }
    // cout<<count<<endl;

    // HASHING
    int a[]={5,10,5,4,5,10,15};
    unordered_set<int>s;
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}