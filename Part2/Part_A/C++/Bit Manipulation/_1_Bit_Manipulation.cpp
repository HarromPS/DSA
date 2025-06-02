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

Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number - 

1. Get ith bit
2. Set ith bit
3. Clear ith bit

Note : For better understanding, we are starting bits from 1 instead 0. (1-based). You have to print space three space seperated values ( as shown in output without a line break) and do not have to return anything.

Input: 70 3
Output: 1 70 66
Explanation: 
Bit at the 3rd position from LSB is 1. (1 0 0 0 1 1 0)
The value of the given number after setting the 3rd bit is 70. 
The value of the given number after clearing 3rd bit is 66. (1 0 0 0 0 1 0)
*/

class Solution{
public: 
    void bitManipulation(int num, int k) {
        // to check if ith bit is set or not, do and operation 
        int ithBit=(1<<k-1);
        std::cout<<(ithBit & num)<<"\n";

        int isSet=0;    // false 
        int setNum=0;
        int clearedNum=0;
        if((ithBit & num) != 0){
            // bit is set
            isSet=1; 
            setNum=num;             // set the 
            clearedNum=ithBit ^ num;
        }else{
            // bit is not set
            setNum=ithBit | num;
            clearedNum=num;
        }
        std::cout<<isSet<<" "<<setNum<<" "<<clearedNum<<"\n";
    }
};

void solve(){
    int n,i;
    std::cin>>n>>i;
    Solution s;
    s.bitManipulation(n,i);
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