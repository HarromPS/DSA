#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

*/

class Solution {
public: 
    // TC:O(K+N) SC:O(1)
    // Brute Force
    int findKthPositiveBrute(std::vector<int>& arr, int k) {
        // range will be like
        int n=arr.size();
        int maxRange=k+n;

        int missedElement=0;
        int kthMissedCount=0;

        int i=0;    // tracks array elements
        int elej=1; // tracks range completely 1 to maxRange
        while(elej<=maxRange+1){  // true
            // std::cout<<missedElement<<" "<<kthMissedCount<<" "<<elej<<std::endl;
            // checks if this is kth missing element 
            if(kthMissedCount == k){
                return missedElement;
            }

            // check if this element is present in array 
            if(i<n && elej == arr[i]){
                // move to next
                i++;
                elej+=1;
            }
            else if((i<n && elej != arr[i]) || i>=n){
                // not in array OR array range is over
                missedElement=elej;     // missed   
                kthMissedCount+=1;      // its count
                elej+=1;                // checks for next missing
            }

            // boundary check 
            // check if i crossed boundary 
            if(i>=n){
                // make it equal to INT_MAX
                i=INT_MAX;    
            }
        }
        return 1;   // just returning the return type 
    }

    /*
    [] kth = 4 => 1 2 3 4

    now just consider the empty array again and we added a number smaller than k to it,
    say 2, so now when we again try to find the 4th missing number we would get it as 5 ( as 1 3 4 5 , as 2 already present in the array, 
    hence the missing value shifts by one position ahead and 5 is the 4th missing value), 
    hence whenever we get a number in the array smaller than k, the kth missing value shifts by position ahead

    [2] 4th => 1 3 4 5
    [2 3] 4th => 1 4 5 6
    [2 3 4] 4th => 1 5 6 7
    [2 3 4 7] 4th => 1 5 6 8
    [2 3 4 7 11]4th => 1 5 6 8 
    */
//    TC:O(N)
    int findKthPositiveOptimal(std::vector<int>& arr, int k) {
        // using binary search and finding 2 nearby indexes for kth missing no
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missingNos = arr[mid]-(mid+1);  // missing no before this number
            if(missingNos < k){
                low=mid+1;      // find missing numbers near to k go right
            }else{
                high=mid-1;     // find missing numbers near to k go left
            }   
        }

        // return low+k or high+1+k (derived formula look into book or https://www.youtube.com/watch?v=uZ0N_hZpyps)
        return low+k;
    }

    // TC:O(log n) SC:O(1)
    int findKthPositiveBetter(std::vector<int>& arr, int k) {
        // if arr[i]<k kth position shifts by 1 position ahead
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                k++;
            }
        }
        return k;
    }
};

void solve(){
    int n;  
    int k;
    std::cin>>n;
    std::cin>>k;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.findKthPositiveBrute(arr,k);
    std::cout<<res<<std::endl;
    res=s.findKthPositiveBetter(arr,k);
    std::cout<<res<<std::endl;
    res=s.findKthPositiveOptimal(arr,k);
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
    // while(t--) solve2();
    return 0;
}