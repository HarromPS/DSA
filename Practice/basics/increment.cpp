#include<iostream>
#include<cstdio>
using namespace std;

// function passed increment/decrement operator
void function(int i){
    if(i>=5){
        return ;
    }
    cout<<i<<" ";
    // return function(i++);   // only 1 is passed & incremented after passing so, 1 is passed
    return function(++i);   // only 1 is passed & incremented after passing so, 1 is passed
}
int main(){
    // only 1 is printed all the time: like infinite while loop
    function(1);
    return 0;
}