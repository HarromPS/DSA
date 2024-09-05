#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int arr[]={5,10,5,15,4,5};
    int count=0,flag=0;
    for(int i=0;i<6;i++){
        flag=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}