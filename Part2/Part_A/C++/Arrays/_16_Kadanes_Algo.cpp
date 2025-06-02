#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer array nums, find the subarray
with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

*/

class Solution {
public:
    // Brute Solution: TC-O(n^3), SC-O(1)
    void maxSubArray(vector<int> a){
        // generate all possible subarrays 
        int ans = INT_MIN;
        int n = a.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=a[k];
                    ans=max(ans,sum);
                }
            }
        }
        cout<<ans<<endl;

        // more better is TC: O(n^2) 
        ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                ans=max(ans,sum);
            }
        }
        cout<<ans<<endl;
    }

    // Optimal Solution:TC-O(n), SC-O(1)
    void maxSubArrayOptimal(vector<int>& arr){
        int sum=0;
        int maxi = arr[0];
        int n = arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi = max(maxi,sum);
            if(sum<0) sum=0;
        }
        cout<<maxi<<endl;
    }

    void printMaxSubarray(vector<int> & arr){
        int start=0;
        int sum=0;
        int maxi = INT_MIN;
        int ansStart=-1, ansEnd=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            // subarray starts when sum is 0 
            if(sum==0) start = i;
            sum+=arr[i];
            if(sum>maxi){
                maxi=sum;
                ansStart=start;
                ansEnd=i;
            }
            if(sum<0) sum=0;
        }
        for(int i=ansStart;i<=ansEnd;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<maxi<<endl;
    }
};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.maxSubArray(arr);
    cout<<"Optimal: "<<endl;
    s.maxSubArrayOptimal(arr);
    s.printMaxSubarray(arr);

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


