#include<iostream>
#include <vector> 
#include<stdlib.h>
using namespace std;

// implementation of fibonacci series with optimization using dynamic programming

// Top down approach
// This solves in O(n) time
int function(int n, vector<int>& v){
    // base condition
    if(n<=2){
        return 1;
    }
    if(v[n] != -1){
        return v[n];
    }
    int result = function(n-1,v) + function(n-2,v);
    v[n] = result;
    return result;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> s(n+1,-1);
    cout<<function(n,s)<<endl;
    return 0;
}