#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. 
In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

i.e arr[0-1] = -inf and arr[n] = -inf

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    // TC:O(N) SC:O(1)
    int peakElementBrute(std::vector<int>& arr) {
        // base case 
        int n=arr.size();
        if(n==1) return arr[0];

        // edges/boundaries 
        if(arr[0]>arr[1]) return arr[0];
        if(arr[n-1]>arr[n-2]) return arr[n-1];

        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                return arr[i];
            }
        }
        return 1;        
    }

    // TC:O(N) SC:O(1)
    int peakElement(std::vector<int>&arr){
        // base condition 
        int n=arr.size();
        if(n==1) return arr[0];
        // edge/boundary cases 
        if(arr[0]>arr[1]) return arr[0];
        if(arr[n-1]>arr[n-2]) return arr[n-1];

        // start by trimming down edges 
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check peak
            if(arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1]){
                return arr[mid];
            }

            // right peak (increasing curve)
            if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]){
                low=mid+1;
            }else{
                // left peak(decreasing curve)
                high=mid-1;
            }
        }
        return -1;  // dummy return value
    }
};

void solve(){
    int n;  // array size
    std::cin>>n;
    // int target;
    // std::cin>>target;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.peakElementBrute(arr);
    std::cout<<res<<std::endl;
    res=s.peakElement(arr);
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