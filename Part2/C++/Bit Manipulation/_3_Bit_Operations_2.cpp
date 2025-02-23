#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<limits>
#include<algorithm>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Bit Manipulation

Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number 

1. count number of set bits 
1. count number of set bits in range (1 to n)
2. odd or even 


Note: For better understanding, we are starting bits from 1 instead 0. (1-based). You have to print space three space seperated values ( as shown in output without a line break) and do not have to return anything.

*/

class Solution{
public: 
    void countSetBitsSingle(int n){
        // brute force: convert to its binary and count number of set bits 
        // bit operation approach 
        int count=0;
        int temp=n;
        int i=0;
        while(temp>0){
            if((n>>i)&1!=0) count++;
            i++;
            temp>>=1;
        }
        std::cout<<count<<std::endl;
    }

    // You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).
    int countSetBits(int n){
        if(n==0) return 0;

        int x=0;    // largest power of 2
        while((1<<x) <= n){
            x++;
        }
        x-=1;
        int y=(1<<(x-1))*x;
        int z=n-(1<<x);

        return y+z+1+countSetBits(z);
    }

    void oddOrEven(int n){
        // brute force is using mod operator
        // bit operation 
        if((n & 1) == 0){
            std::cout<<"Even"<<std::endl;
            return;
        }
        std::cout<<"Odd"<<std::endl;
    }

};

void solve(){
    int n,i;
    std::cin>>n>>i;
    Solution s;
    // s.countSetBitsSingle(n);
    int res=s.countSetBits(n);
    std::cout<<res<<std::endl;

    // s.oddOrEven(n);
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // while(t--) solve2();
    return 0;
}