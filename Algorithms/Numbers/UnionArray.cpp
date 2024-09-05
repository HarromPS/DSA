#include<iostream>
#include<cstdio>
using namespace std;

#include<unordered_set>
int main(){

    // BRUTE FORCE
    // int a[]={5,10,15,5};
    // int b[]={10,15,4,5};
    // int s1=sizeof(a)/sizeof(a[0]);
    // int s2=sizeof(b)/sizeof(a[0]);
    // int count=0;
    // int flag=0;

    // // 1st find distinct elements from 1st array first & then compare the second array
    // for(int i=0;i<s1;i++)
    // {
    //     flag=0;
    //     for(int j=0;j<i;j++)
    //     {
    //         if(a[j]==a[i]){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0)
    //         count++;
    // }

    // // now compare the second array with the first
    // for(int i=0;i<s2;i++){
    //     flag=0;
    //     for(int j=0;j<s1;j++)
    //     {
    //         if(b[i]==a[j]){
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
    int a[]={5,10,15,5};
    int b[]={10,15,4,5};
    int s1=sizeof(a)/sizeof(a[0]);
    int s2=sizeof(b)/sizeof(a[0]);

    unordered_set<int> s;
    for(int i=0;i<s1;i++){
        s.insert(a[i]);
    }

    for(int i=0;i<s2;i++){
        s.insert(b[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}