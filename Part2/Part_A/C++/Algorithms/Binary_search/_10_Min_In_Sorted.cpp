#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

*/

class Solution {
public:
    // Find Minimum in Rotated Sorted Array
    // Unique elements
    int findMinBrute(std::vector<int>& arr) {
        // using linear search 
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++){
            ans=std::min(ans,arr[i]);
        }
        return ans;
    }

    int findMin(std::vector<int>& arr) {
        // using binary search traversal 
        int ans=INT_MAX;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check for sorted and unsorted part 
            if(arr[low]<=arr[mid]){
                // pick min from sorted array 
                ans=std::min(ans,arr[low]);
                // go right for unsorted part 
                low=mid+1;
            }else{
                // pick min from sorted array 
                ans=std::min(ans,arr[mid]);
                // go left for unsorted part 
                high=mid-1;
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

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.findMinBrute(arr);
    std::cout<<res<<std::endl;
    res=s.findMin(arr);
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

    // int t;
    // std::cin>>t;
    // while(t--) solve();
    solve();
    return 0;
}