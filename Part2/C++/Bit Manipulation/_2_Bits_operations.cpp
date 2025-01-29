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
4. swap two number using bits
5. toggle ith bit
6. remove 1st set bit from right (lsb)
7. set 1st unset bit from right (lsb)

Note: For better understanding, we are starting bits from 1 instead 0. (1-based). You have to print space three space seperated values ( as shown in output without a line break) and do not have to return anything.

*/

class Solution{
public: 
    // 1. check ith bit
    void checkIthBitLeftShift(int num, int k) {
        // to check if ith bit is set or not, do and operation 
        int ithBit=(1<<k-1);    
        if((num & ithBit) == 0){        // bring 1 to ith bit and do and operation
            std::cout<<"Bit is 0\n";
        }else{
            std::cout<<"Bit is 1\n";
        }
    }

    void checkIthBitRightShift(int num, int k) {
        int ithBit=(num >> (k-1)); // get the ith bit to lsb
        if((ithBit & 1) == 0){
            std::cout<<"Bit is 0\n";
        }else{
            std::cout<<"Bit is 1\n";
        }
    }


    // 2. Set ith bit
    void setIthBit(int num, int k) {
        std::cout<<"Before: "<<num;
        int res = num | (1 << k-1);
        std::cout<<", After: "<<res<<"\n";
    }

    // 3. Clear ith bit
    void unSetIthBit(int num, int k) {
        std::cout<<"Before: "<<num;
        int res = num ^ (1 << k-1);
        std::cout<<", After: "<<res<<"\n";
    }


    // 4. swap two number using bits
    void swapNos(int a,int b){
        std::cout<<"Before: "<<a<<" "<<b;
        a=a^b;
        b=a^b;
        a=a^b;
        std::cout<<", After: "<<a<<" "<<b<<std::endl;
    }

    // 5. toggle ith bit
    void toggleIthBitBrute(int n,int k){
        int ans=0;

        // check ith bit if set, 
        if(((n >> k-1) & 1) == 1){
            // unset 
            ans = n ^ (1<< k-1);
        }else{
            // set 
            ans = n | (1<< k-1);
        }
        std::cout<<ans<<std::endl;
    }

    void toggleIthBit(int n,int k){
        int ans=n^(1<< k-1);
        std::cout<<ans<<std::endl;
    }

    // 6. remove 1st set bit from right (lsb)
    void rightMostUnset1(int n){
        // check 1st set bit and make it unset 
        int i=0;
        int ans=0;
        while(i<=31){
            // check 
            if((n & (1 << i)) != 0){
                ans=(n ^ (1<<i));
                break;
            }
            i++;
        }
        std::cout<<ans<<std::endl;
    }

    void rightMostUnset2(int n){
        // n-1 sets 1st set bit to 0 and all bits on right to 1
        // 16 -     1 0 0 0 0 
        // 15 -     0 1 1 1 1 
        // 16 & 15 -0 0 0 0 0 

        int ans=(n & n-1);
        std::cout<<ans<<std::endl;
    }

    // 7. set 1st unset bit from right (lsb)
    void rightMostSet1(int n){
        // check 1st set bit and make it unset 
        int i=0;
        int ans=0;
        while(i<=31){
            // check 
            if((n & (1 << i)) == 0){
                ans=(n | (1<<i));
                break;
            }
            i++;
        }
        std::cout<<ans<<std::endl;
    }

    // Return the number after setting the rightmost unset bit of 'N'. 
    // If there are no unset bits in N's binary representation, 
    // then the number should remain unchanged.
    void rightMostSet2(int n){
        // using right shift 
        int i=0;
        int temp=0;
        int ans=0;
        while(temp>0){
            // check 
            if((n >> i & 1) == 0){
                ans = (n | (1<<i));
                break;
            }
            i++;
        }
        ans = n;
        std::cout<<ans<<std::endl;
    }

    void rightMostSet3(int n){
        // N + 1 flips the rightmost unset bit to 1 and all bits to its right to 0.
        int ans = (n | (n+1));
        if((n & (n+1)) == 0){
            // all bits are set 
            ans = n;
        }
        std::cout<<ans<<std::endl;
    }

};

void solve(){
    int n,i;
    std::cin>>n>>i;
    Solution s;
    s.checkIthBitLeftShift(n,i);
    s.checkIthBitRightShift(n,i);
    s.setIthBit(n,i-1);
    s.unSetIthBit(n,i);
    s.swapNos(n,n+10);
    s.toggleIthBitBrute(n,i);
    s.toggleIthBit(n,i);
    s.rightMostUnset1(n);
    s.rightMostUnset2(n);
    s.rightMostSet1(n);
    s.rightMostSet2(n);
    s.rightMostSet3(n);
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