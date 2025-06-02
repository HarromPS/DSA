#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.

Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.

Input: n = 1
Output: 1
*/

class Solution {
public:
    // TC:O(N/2) SC:O(1) gives TLE
    long long floorSqrtBrute(long long n) {
        // run a loop till n and check if the number is a square 
        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long x=i*i;
            if(x==n){
                ans=i;
                break;
            }
            else if(x > n){
                ans=i-1;
                break;
            }
        }
        return ans;
    }

    // TC:O(log n) SC:(1)
    long long floorSqrt(int n){
        // use floor algorithm to find the sqrt of any number 
        if(n==0) return 0;
        long long ans=0;
        long long low=1;
        long long high=n;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if((mid*mid) <= n){
                ans=std::max(ans,mid);
                low=mid+1;  // needed more closer to number n
            }else{
                high=mid-1; // more closer to n
            }
        }
        return ans;
    }
};

void solve(){
    int n;  // array size
    std::cin>>n;
    // int target;
    // std::cin>>target;

    // std::vector<int> arr(n,0);
    // for(int i=0;i<n;i++){
    //     std::cin>>arr[i];
    // }   

    Solution s;
    // int res=s.floorSqrtBrute(n);
    // std::cout<<res<<std::endl;
    int res=s.floorSqrt(n);
    std::cout<<res<<std::endl;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // solve();
    return 0;
}