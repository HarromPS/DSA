#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement

You are given a sorted array 'arr' of positive integers of size 'n'.

It contains each number exactly twice except for one number, which occurs exactly once.
Find the number that occurs exactly once.

Example :
Input: ‘arr’ = {1, 1, 2, 3, 3, 4, 4}.
Output: 2
Explanation: 1, 3, and 4 occur exactly twice. 2 occurs exactly once. Hence the answer is 2.
*/

class Solution {
public:
    // Brute Solution: TC-O(n^2), SC-O(1)
    void longestSubarraySum(vector<int> a,int k){
        // all possible subarrays 
        int len=0;
        int n = a.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[i];
                if(sum==k){
                    len=max(len, j-i+1);
                }
            }
        }
        cout<<len<<endl;
    }

    // for positive and ones and negatives max optimization
    // Better Solution: TC-O(n), SC-O(1)  
    void longestSubarraySumBetter(vector<int> arr,int k){
        // using hasing and reverse sum 
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

    // max optimization till positives and zeros
    // Optimal Solution:TC-O(n), SC-O(1)
    void longestSubarraySumOptimal(vector<int> arr,int k){
        int right = 0;
        int left = 0;
        int n = arr.size();
        int len = 0;
        int sum = arr[0];
        while(left<n && right<n){
            // if sum already > k
            while(sum>k){
                sum-=arr[left];
                left++;
            }
            if(sum==k){
                len=max(len, right-left+1);
            }
            right++;
            if(right,n){
                sum+=arr[right];
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
        cin>>arr[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.longestSubarraySum(arr,k);
    cout<<"Better: "<<endl;
    s.longestSubarraySumBetter(arr,k);
    cout<<"Optimal: "<<endl;
    s.longestSubarraySumOptimal(arr,k);
    
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


