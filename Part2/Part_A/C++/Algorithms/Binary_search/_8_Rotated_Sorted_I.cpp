#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: index - 4

*/

class Solution {
public:
    int searchInRotatedSorted(std::vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check if target found
            if(arr[mid]==target){
                ans=mid;
                return ans;
            }

            // check sorted half 
            if(arr[low] <= arr[mid]){
                // check existance of target in left sorted portion 
                if(arr[low]<=target && target<=arr[mid]){
                    // go left sorted portion
                    high=mid-1;
                }else{
                    //  go right unsorted portion and check existance
                    low=mid+1;
                }
            }
            else{
                // check existance of target in right sorted portion 
                if(arr[mid]<=target && target<=arr[high]){
                    // go right unsorted portion
                    low=mid+1;
                }else{
                    // go left unsorted portion and check existance
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};

void solve(){
    int n;  // array size
    std::cin>>n;
    int target;
    std::cin>>target;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.searchInRotatedSorted(arr,target);
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