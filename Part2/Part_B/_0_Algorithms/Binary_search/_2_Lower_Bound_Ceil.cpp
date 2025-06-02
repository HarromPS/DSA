#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Lower Bound or CEIL
-> smallest value such that it is >= k

Upper bound
-> largest value such that it is > k

[3 5 8 15 19]
for k=5

lower bound = 5 as 5>=k
upper bound = 8 as 8>k

for k=10
lower bound = 15 as 15>=k
upper bound = 15 as 15>k
*/

class Solution {
public:
    int lower_bound_ceil(std::vector<int>& arr,int k){
        // finding lowest value >= k
        int ansIndex = INT_MAX;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=k){
                ansIndex=std::min(ansIndex,mid);
                high=mid-1;         // minimize the index to get lower bound or ceil value
            }else{
                low=mid+1;
            }
        }
        if(ansIndex==INT_MAX) return arr.size();
        return ansIndex;
    }

    int upper_bound_floor(std::vector<int>& arr,int k){
        int ansIndex = INT_MAX;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>k){
                ansIndex=std::min(ansIndex,mid);
                high=mid-1;         // just > k
            }else{
                low=mid+1;
            }
        }
        if(ansIndex==INT_MAX) return arr.size();
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
    int res=s.lower_bound_ceil(arr,target);
    std::cout<<res<<std::endl;
    res=s.upper_bound_floor(arr,target);
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
    return 0;
}