#include<iostream>
#include<cstdio>
using namespace std;

// Josephus Problem: circle, n people, one has gun, shoots person k steps & also can himself
// logic: f(n,k) = (f(n-1, k) + k) % n

int alive(int n,int k){
    if(n==1) return 0;     // last man
    return (alive(n-1, k) + k)%n;
}
int main(){
    printf("%d",alive(5,3));
    return 0;
}