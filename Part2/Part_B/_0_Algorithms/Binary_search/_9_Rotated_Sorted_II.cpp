#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


*/

class Solution {
public:
    // Unique elements
    bool searchInUniqueRotatedSorted(std::vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check if target found
            if(arr[mid]==target){
                return true;
            }

            // check sorted half 
            if(arr[low] <= arr[mid]){
                // check existance of target in left sorted portion 
                if(arr[low]<=target && target<=arr[mid]){
                    // yes exists on left portion
                    high=mid-1;
                }else{
                    // go right unsorted portion and check existance
                    low=mid+1;
                }
            }
            else{
                // check existance of target in right sorted portion 
                if(arr[mid]<=target && target<=arr[high]){
                    // yes exists on right portion
                    low=mid+1;
                }else{
                    // go left sorted portion and check existance
                    high=mid-1;
                }
            }
        }
        return false;   // does not exists
    }

    bool searchInDuplicateRotatedSorted(std::vector<int>& arr, int target) {
        /*
        0 1 2 3 4

        1 0 1 1 1
        target = 0

        here 
        low = 0
        high = 4
        mid = 2
        so arr[low] = arr[mid] = arr[high]
        so both portions are sorted, so trim down this condition

        i.e if arr[mid] != target, and arr[low] = arr[mid] = arr[high], 
        so neither arr[low] nor arr[high],  will be equal to target as well
         */
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check if target found
            if(arr[mid]==target){
                return true;
            }

            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                // trim this condition
                low=low+1;
                high=high-1;
                continue;   // if this condition happens do this same thing
            }

            // check sorted half 
            if(arr[low] <= arr[mid]){
                // check existance of target in left sorted portion 
                if(arr[low]<=target && target<=arr[mid]){
                    // yes exists on left portion
                    high=mid-1;
                }else{
                    // go right unsorted portion and check existance
                    low=mid+1;
                }
            }
            else{
                // check existance of target in right sorted portion 
                if(arr[mid]<=target && target<=arr[high]){
                    // yes exists on right portion
                    low=mid+1;
                }else{
                    // go left sorted portion and check existance
                    high=mid-1;
                }
            }
        }
        return false;   // does not exists
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
    int res=s.searchInUniqueRotatedSorted(arr,target);
    std::cout<<res<<std::endl;
    res=s.searchInDuplicateRotatedSorted(arr,target);
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