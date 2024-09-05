#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/**
 * You are give a nums array with multiple occurances in it
 * sort the array in increasing order based on the frequency of the values.
 * If multiple values have the same frequency, sort them in decreasing order.
 *
 * Return the sorted array.
 *
 * Example 1:

    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

    Example 2:

    Input: nums = [2,3,1,3,2]
    Output: [1,3,3,2,2]
    Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

    Example 3:

    Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    Output: [5,-1,4,4,-6,-6,1,1,1]
 *
 */

// reference to non-static member function must be called
// custom comparator function
bool comparator(pair<int,int>& m1,pair<int,int>& m2) 
{ 
    if(m1.second < m2.second){
        return true;
    }

    if(m1.second == m2.second){
        if(m1.first > m2.first){
            return true;
        }
    }
    return false;
} 

class Solution {
public:
  
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        int n  = nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]]=1;
            }
        }

        vector<pair<int,int>> vec (mp.begin(),mp.end());

        // comparator function should be a non static function
        sort(vec.begin(), vec.end(), comparator); 

        vector<int> ans;
        for(auto it: vec){
            int sec = it.second;
            while(sec--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int r=0;
        cin>>r;
        arr.push_back(r);
    }
    Solution s;
    arr=s.frequencySort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

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
