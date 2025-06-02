#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

FLOOR
largest element which is <= x

[3 5 8 15 19]

for k=5
floor = 5 as 5<=k

for k=10
floor = 8 as 8<=k
*/

class Solution {
public:
    int floor_value(std::vector<int>& arr,int k){
        // finding lowest value >= k
        int ansIndex = INT_MIN;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=k){
                ansIndex=std::max(ansIndex,arr[mid]);
                low=mid+1;      // maximize the index to get floor value
            }else{
                high=mid-1;         
            }
        }
        if(ansIndex==INT_MIN) return -1;
        return ansIndex;
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
    int res=s.floor_value(arr,target);
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