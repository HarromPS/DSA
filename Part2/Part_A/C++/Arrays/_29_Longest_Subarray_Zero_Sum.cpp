#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array having both positive and negative integers. 


Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.

Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.The task is to compute the length of the largest subarray with sum 0.
*/

class Solution {
public:
    // Brute Solution: TC-O(n^2), SC-O(1)
    void longestSubarrayZeroSum(vector<int> a,int k){
        // all possible subarrays 
        int len=0;
        int n = a.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+a[j];
                if(sum==k){
                    len=max(len, (j-i)+1);
                }
            }
        }
        cout<<len<<endl;
    }

    // for positive and ones and negatives max optimization
    // Better Solution: TC-O(n), SC-O(1)  
    void longestSubarrayZeroSumBetter(vector<int> arr,int k){
        // using hasing and prefix sum 
        int prefixSum=0;
        int n = arr.size();
        int len=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum==k){
                len = max(len, i+1);
                mp[prefixSum]=i;
            }
            else {
                int x_k = prefixSum-k;
                if(mp.find(x_k) != mp.end()){   // if exists
                    int _i = mp[x_k];
                    int _j = i;
                    len = max(_j-_i, len);

                }   
            }
            // if sum is already there dont update it, else
            if(mp.find(prefixSum)==mp.end()){
                mp[prefixSum]=i;
            }
        }
        cout<<len<<endl;
    }
};

void solve(){
    int n;  // array size
    int k;
    cin>>n>>k;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr[i]=ip;
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.longestSubarrayZeroSum(arr,k);
    cout<<"Better: "<<endl;
    s.longestSubarrayZeroSumBetter(arr,k);    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}


