#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer array nums, find a subarray
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

class Solution {
public:
    void Swap(vector<int>& a,vector<int>& b,int i,int j){
        int temp=a[i];
        a[i]=b[j];
        b[j]=temp;
    }

    void reverse(int start,int end,vector<int>& a){
        while(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
            end--;
        }
    }
    // Brute Solution: TC-O(n^2) SC-O(1)
    void maxProductBrute(vector<int> arr){
        // generate all subarrays
        int ans=INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=i;j<n;j++){
                product*=(arr[j]);
                ans=max(ans,product);
            }
        }
        cout<<ans<<endl;
    }

    // Optimal Solution: TC-O(n x log n), SC-O(1)  
    void maxProductOptimal(vector<int>& arr){
        // using prefix and suffix product 
        int ans=INT_MIN;
        int prefix = 1;
        int suffix = 1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix=prefix*arr[i];
            suffix=suffix*arr[n-1-i];
            ans=max(ans,max(prefix,suffix));
        }
        cout<<ans<<endl;
    }
};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr.push_back(ip);
    }   

    Solution s;
    cout<<"Brute 1: "<<endl;
    s.maxProductBrute(arr);  
    cout<<"Optimal 2: "<<endl;
    s.maxProductOptimal(arr);    
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


