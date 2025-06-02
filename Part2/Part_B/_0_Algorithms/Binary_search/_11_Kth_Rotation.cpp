#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Input: arr = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.


Soln=> find smallest number and then find distance from 0th index 
*/

class Solution {
public:
    int findKRotationBrute(std::vector<int> &arr) {
        // TC:O(N) SC:O(1)
        // find smallest element index and return distance from 0th index 
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[ans]){
                ans=i;
            }
        }
        return arr[ans];
    }
    
    int findKRotation(std::vector<int> &arr) {
        // using advantage of sorted and unsorted array 
        /*
        We know in a sorted rotated array, in unsorted region, we have the mininum
        but in conditions where sorted and unsorted both share the same value which is minimum
        here we use a solution 

        => pick minimum from sorted part and move to unsorted part 
         */

        int ans=INT_MAX;
        int ansIndex=INT_MAX;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // check for sorted and unsorted part 
            if(arr[low]<=arr[mid]){
                // pick min from sorted array (left)
                ans=std::min(ans,arr[low]);
                ansIndex=ans==arr[low]?low:ansIndex;    // if [low] value assigned, means update index
                // go right for unsorted right part 
                low=mid+1;
            }else{
                // pick min from sorted array (right)
                ans=std::min(ans,arr[mid]);
                ansIndex=ans==arr[mid]?mid:ansIndex;    // if [mid] value assigned, means update index
                // move unsorted left part 
                high=mid-1;
            }
        }
        return ansIndex;    // return index of smallest value from 0th index => i.e index-0 => index
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
    int res=s.findKRotationBrute(arr);
    std::cout<<res<<std::endl;
    res=s.findKRotation(arr);
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