#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
#include<algorithm>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Bit Manipulation

Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number 

1. check ith bit
2. Set ith bit
3. Clear ith bit

Note: For better understanding, we are starting bits from 1 instead 0. (1-based). You have to print space three space seperated values ( as shown in output without a line break) and do not have to return anything.

Input: 70 3
Output: 1 70 66
Explanation: 
Bit at the 3rd position from LSB is 1. (1 0 0 0 1 1 0)
The value of the given number after setting the 3rd bit is 70. 
The value of the given number after clearing 3rd bit is 66. (1 0 0 0 0 1 0)
*/

class Solution{
public: 
    // Third variable
    void Swap1(int a, int b) {
        int temp=a;
        a=b;
        b=temp;
        std::cout<<a<<" "<<b<<std::endl;
    }

    // 2 variables 
    void Swap2(int a, int b) {
        a = a+b;
        b=a-b;
        a=a-b;
        std::cout<<a<<" "<<b<<std::endl;
    }

    // Bit manipulation 
    void Swap3(int a, int b) {
        a=a^b;
        b=a^b;
        a=a^b;
        std::cout<<a<<" "<<b<<std::endl;
    }

    // return a pair SC:O(2)
    std::pair<int,int> Swap4(int a, int b) {
        return {b,a};
    }

};

void solve(){
    int a,b;
    std::cin>>a>>b;
    Solution s;
    std::cout<<"Before: "<<a<<" "<<b<<std::endl;
    s.Swap1(a,b);
    s.Swap2(a,b);
    s.Swap3(a,b);
    std::pair<int,int> res = s.Swap4(a,b);
    std::cout<<res.first<<" "<<res.second<<std::endl;
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