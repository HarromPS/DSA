#include<iostream>
#include<cstdio>
using namespace std;

#include<unordered_set>
int main(){

    // BRUTE FORCE
    // int a[]={3,4,2};
    // int b[]={1,5};
    // int a[]={5,10,15,5};
    // int b[]={10,15,4,5};
    // int s1=sizeof(a)/sizeof(a[0]);
    // int s2=sizeof(b)/sizeof(a[0]);
    // int count=0;
    // int flag=0;

    // for(int i=0;i<s1;i++)
    // {
    //     flag=0;
    //     for(int j=0;j<s2;j++)
    //     {
    //         if(a[i]==b[j]){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==1)
    //         count++;
    // }

    // cout<<count<<endl;

    // for Sorted Array
    int a[]={1,5,10,15,112};
    int b[]={4,5,10,15,134};
    int s1=sizeof(a)/sizeof(a[0]);
    int s2=sizeof(b)/sizeof(a[0]);
    int count=0;
    int i=0,j=0;
    while(i<s1 && j<s2)    {
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else if(a[i]==b[j]){
            count++;
            i++;
            j++;
        }
    }
    cout<<count<<endl;

    // HASHING
    // int a[]={5,10,15,5};
    // int b[]={10,15,4,5};
    // int s1=sizeof(a)/sizeof(a[0]);
    // int s2=sizeof(b)/sizeof(a[0]);

    // unordered_set<int> s;
    // // add 1st array to the set
    // for(int i=0;i<s1;i++){
    //     s.insert(a[i]);
    // }

    // int count=0;
    // // find distinct in 2nd array
    // for(int i=0;i<s2;i++){
    //     if(s.find(b[i])!=s.end()){
    //         s.erase(b[i]);
    //         count++;
    //     }
    //     s.insert(b[i]);
    // }
    // cout<<count<<endl;
    // cout<<s.size()<<endl;
    return 0;
}