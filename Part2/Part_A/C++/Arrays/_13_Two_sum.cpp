#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    // Brute Solution: TC-O(n^2), SC-O(1)
    void TwoSum(vector<int> a,int target){
        // all possible pairs  
        int ans_i=0,ans_j=0;
        int n = a.size();
        for(int i=0;i<n-1;i++){
            int sum=0;
            int flag=0;
            for(int j=i+1;j<n;j++){
                sum=a[i]+a[j];
                if(sum==target){
                    ans_i=i;
                    ans_j=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        cout<<ans_i<<" "<<ans_j<<endl;
    }

    // for positive and ones and negatives max optimization
    // Better Solution: TC-O(n), SC-O(n)  
    void TwoSumBetter(vector<int> arr,int target){
        // using hasing and reverse sum 
        int ans_i=0,ans_j=0;
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            // if corresponding sum element is there in the map return ans 
            int corresponding_element = target-arr[i];
            if(mp.find(corresponding_element)!=mp.end()){
                ans_i=i;
                ans_j=mp[corresponding_element];
                break;
            }else{
                mp[arr[i]]=i;
            }
        }
        cout<<ans_i<<" "<<ans_j<<endl;
        
    }

    // max optimization till positives and zeros
    // Optimal Solution:TC-O(n/2), SC-O(n)
    void TwoSumOptimal(vector<int> arr,int target){
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int len = 0;
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++) vp.push_back({arr[i],i});
        sort(vp.begin(),vp.end());

        int ans_i=0,ans_j=0;
        while(left<right){
            int sum = vp[left].first + vp[right].first;
            if(sum==target) {
                ans_i=vp[left].second;
                ans_j=vp[right].second;
                break;
            }else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        cout<<ans_i<<" "<<ans_j<<endl;
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
    s.TwoSum(arr,k);
    cout<<"Better: "<<endl;
    s.TwoSumBetter(arr,k);
    cout<<"Optimal: "<<endl;
    s.TwoSumOptimal(arr,k);
    
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


