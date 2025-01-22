#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Allocate Minimum Pages
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

*/

class Solution{
public: 
    bool helper(std::vector<int> &arr, int maxSubarraySumAllowed, int subarrays){
        // check for each book 
        int i=0;
        int n=arr.size();
        int subArraySum=0;   // max subarray sum in a subarray 
        int subArrayFilled=1;     // at least 1 subarray can have all the sum
        while(i<n){
            // add element to this subarray untill reaches max subarray sum limit
            if(subArraySum + arr[i] <= maxSubarraySumAllowed){
                subArraySum += arr[i];
            }else{
                subArraySum=arr[i];    // allocate this element to other subarray
                subArrayFilled+=1;
            }
            i++;
        }
        if(subArrayFilled > subarrays){ 
            // no of subarrays exceeded limit and cant fit it into other subarrays
            return false;
        }
        return true;    
    }

    int splitArrayBrute(std::vector<int> &arr, int k) {
        int n=arr.size();

        // base condition
        if(k > n) return -1;    // number of splits are more than elements

        int maxSubarraySumAllowed=*max_element(arr.begin(),arr.end());
        int totalSum=std::accumulate(arr.begin(),arr.end(),0);
        for(int i=maxSubarraySumAllowed;i<=totalSum;i++){
            // check all elements are used to make k subarrays exactly
            bool res=helper(arr,i,k);
            if(res==true){
                return i;   // min subarray sum to be maximum
            }
        }
        return -1;   // not possible to allot books to k students
    }

    int splitArray(std::vector<int> &arr, int k) {
        int n=arr.size();

        // base condition
        if(k > n) return -1;    // not possible to allocate books to k students

        int ans=-1;
        int low=*max_element(arr.begin(),arr.end());
        int high=std::accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            // check all elements are used to make k subarrays exactly
            bool res=helper(arr,mid,k);
            if(res==true){
                ans=mid;   // min subarrays sum to be maximum
                high=mid-1; // minimize ans
            }else{
                low=mid+1;
            }
        }
        return low;  
    }
};

void solve(){
    int n;  
    int k;
    std::cin>>n;
    std::cin>>k;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.splitArrayBrute(arr,k);
    std::cout<<res<<std::endl;
    res=s.splitArray(arr,k);
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
    // while(t--) solve2();
    return 0;
}