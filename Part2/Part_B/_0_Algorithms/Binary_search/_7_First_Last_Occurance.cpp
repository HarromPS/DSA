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

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    // If target is not found in the array, return [-1, -1].

    int getCeilValue(std::vector<int>& arr,int k){
        int ansIndex=INT_MAX;   // out of array 
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=k){
                ansIndex=std::min(ansIndex,mid);
                high=mid-1; // minimize index
            }else{
                low=mid+1;
            }
        }
        // check if its our target
        if(ansIndex!=INT_MAX && arr[ansIndex]==k){
            return ansIndex;
        }
        return -1;
    }

    int getFloorValue(std::vector<int>& arr,int k){
        int ansIndex=INT_MIN;   // below array 
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=k){
                ansIndex=std::max(ansIndex,mid);
                low=mid+1;  // maximize index
            }else{
                high=mid-1;
            }
        }
        // check if its our target
        if(ansIndex!=INT_MIN && arr[ansIndex]==k){
            return ansIndex;
        }
        return -1;
    }

    std::vector<int> searchRange(std::vector<int>& arr, int k) {
        // ceil value gives first occurance i.e minimal index >= k closer to k
        int ceilValue=getCeilValue(arr,k);

        // floor value gives last occuranc i.e maximal index <= k closer to k 
        int floorValue=getFloorValue(arr,k);

        return {ceilValue,floorValue};
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
    std::vector<int> res=s.searchRange(arr,target);
    for(auto it:res) std::cout<<it<<" ";
    std::cout<<std::endl;
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