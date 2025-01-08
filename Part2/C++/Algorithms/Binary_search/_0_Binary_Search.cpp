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
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){ 
                return mid;
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
        return -1;  // target not found
    }

    int recursiveSolution(int low,int high,std::vector<int>& arr,int target){
        // base case
        if(low>high){
            return -1;  // target not found because of no more search space 
        }

        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target){
            // search on left search space
            return recursiveSolution(low,mid-1,arr,target);
        }

        // search on right search space 
        return recursiveSolution(mid+1,high,arr,target);
    }
    // TC:O(log n) SC:O(log n)
    int binarySearchRecursive(std::vector<int> &arr,int target){
        int low=0;
        int high=arr.size()-1;
        return recursiveSolution(low,high,arr,target);
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
    res=s.binarySearchRecursive(arr,target);
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
    while(t--){
        solve();
    }
    return 0;
}