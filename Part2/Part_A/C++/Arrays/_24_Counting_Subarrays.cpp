#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

*/

class Solution {
public:
    void reverse(int start,int end,vector<int>& arr){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[j];
        arr[j]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(n^2), SC-O(1)
    void countSubArraySumBrute(vector<int> arr,int k){
        // generating all the subarrays
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            int csum=0;
            for(int j=i;j<n;j++){
                csum+=arr[j];
                if(csum==k){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void countSubArraySumOptimal(vector<int>& arr,int k){
        // using prefix sum and mapping sequence 
        int psum=0;
        int count=0;
        int n =arr.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            psum+=arr[i];
            int rem = psum-k;
            count+=mp[rem];
            mp[psum]+=1;
        }
        cout<<count<<endl;
    }

};

void solve(){
    int n;  // array size
    int k;
    cin>>n>>k;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr.push_back(ip);
    }   

    Solution s;

    cout<<"Brute: "<<endl;
    s.countSubArraySumBrute(arr,k);

    cout<<"Optimal: "<<endl;
    s.countSubArraySumOptimal(arr,k);
    

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


