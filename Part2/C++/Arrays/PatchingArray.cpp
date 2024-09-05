#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class Solution {
public:
    // brute force i.e get all possible combinations 

    void solve(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& combs){
        if(ind>=nums.size()){
            combs.push_back(ds);
            return;
        }
        // pick and non pick 
    
        ds.push_back(nums[ind]);
        solve(ind+1,nums,ds,combs);
        ds.pop_back();
        solve(ind+1,nums,ds,combs);    
    }

    int haveSum(int n,vector<vector<int>>& combs){
        int res=n;
        for(int i=0;i<combs.size();i++){
            int sum=0;
            for(int j=0;j<combs[i].size();j++){
                sum+=combs[i][j];
            }
            if(sum==n){ return n;}
            else if(sum<n) {res =  min(res,n-sum);}
        }
        return res;
    }
    int minPatches(vector<int>& nums, int n) {
        vector<vector<int>> combs;
        vector<int> ds;
        int ans=0;

        // get the initial combination
        solve(0,nums,ds,combs);

        int patch=0;
        for(int i=n;i>=1;i--){
            patch=haveSum(i,combs);
            if(patch==i) continue;
            else {
                ds.clear();
                combs.clear();
                nums.push_back(patch);
                sort(nums.begin(),nums.end());
                solve(0,nums,ds,combs);
                ans+=1;
            }
        } 
        
        
        return ans;
    }
};
void solve_()
{
    Solution s;
    int arr[] = {1,5,10};
    vector<int> v;
    for(int i=0;i<4;i++){
        v.push_back(arr[i]);
    }
    int n=20;
    int res = s.minPatches(v,n);
    cout<<res<<endl;

}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    solve_();
    return 0;
}