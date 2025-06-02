#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

We have a search space, 
we see on middle, if not middle, we check possiblility of its occurence

we split to halves -> either go left half or right half

TC:O(log n) SC:O(1)
*/

class Solution {
public:
    // TC:O(log n) SC:O(1)
    int binarySearchIterative(std::vector<int>& arr,int target){
        // search target iteratively and return its index 
        // minimize index
        int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){ 
                ans=std::min(ans,mid);
                high=mid-1;     // minimize the index in duplicate element array
            }
            else if(arr[mid]>target){
                // on left
                high=mid-1; 
            }
            else {
                // on right
                low=mid+1;                 
            }
        }
        if(ans==INT_MAX) return -1;  // target not found
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
    int res=s.binarySearchIterative(arr,target);
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

    solve();
    return 0;
}