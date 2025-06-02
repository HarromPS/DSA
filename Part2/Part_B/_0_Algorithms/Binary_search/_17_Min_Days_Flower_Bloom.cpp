#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS
Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4, (1/4 + 2/4 + 5/4 + 9/4) => (0.25 + 0.5 + 1.25 + 2.25) => (1+1+2+3) => 7
if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44


*/

class Solution {
public: 
    int getSum(std::vector<int>& arr, int divisor){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            // rounded to the nearest integer greater than or equal
            int division=ceil((double)arr[i] / (double)divisor);
            sum+=division;
        }
        return sum;
    }

    // TLE
    // TC:O(log (max(arr))*n) SC:O(1)
    int smallestDivisorBrute(std::vector<int>& arr, int threshold) {
        // if divisor = 1 (min), sum = sum of all elements in array 
        // if divisor = maxelement, sum = size of array 

        int ans=INT_MAX;    // get min divisor 
        int maxEle=*max_element(arr.begin(),arr.end());
        for(int divisor=1;divisor<=maxEle;divisor++){
            int sum = getSum(arr,divisor);
            if(sum<=threshold){
                ans=divisor;
                break;
            }
        }
        return ans;
    }
 
    // TC:O(log max(arr) * N) SC:O(1)
    int smallestDivisor(std::vector<int>& arr, int threshold) {
        // if divisor = 1 (min), sum = sum of all elements in array 
        // if divisor = maxelement, sum = size of array 

        int ans=INT_MAX;    // get min divisor 
        int low=1;          // min divisor 
        int high=*max_element(arr.begin(),arr.end());   // max divisor 
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum = getSum(arr,mid);
            if(sum<=threshold){
                ans=std::min(ans,mid);
                // increase sum to threshold (decrease denominator)
                high=mid-1;
            }else{
                // decrease sum to threashold (increase denominator)
                low=mid+1;
            }
        }
        return ans;
    }
};

void solve(){
    int n;  
    int threshold;
    std::cin>>n;
    std::cin>>threshold;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.smallestDivisorBrute(arr,threshold);
    std::cout<<res<<std::endl;
    res=s.smallestDivisor(arr,threshold);
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