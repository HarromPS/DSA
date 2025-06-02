#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
=> 39. Combination Sum

Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is
less than 150 combinations for the given input.

E.g 
n=4
sum=7
arr = [2 3 6 7]

ans = [ [7], [2 2 3] ]

*/
class Solution
{
public:
    // Brute force
    // T.C: O(2^n)
    // S.C: O(n)
    void Combination_Sum_Infinite_Number_Supply_Brute(int i,vector<int>& arr,int target, vector<int>& ds,vector<vector<int>>& ans)
    {
        // base case
        if(i<0){
            if(target==0){
                // add to answer
                ans.push_back(ds);
            }
            return;
        }

        // recurrence relation
        // check if target is achievable
        if(target - arr[i] >= 0){
            // pick
            ds.push_back(arr[i]);

            // can pick it again
            Combination_Sum_Infinite_Number_Supply_Brute(i,arr,target-arr[i],ds,ans);
            
            // non pick 
            ds.pop_back();
        }

        Combination_Sum_Infinite_Number_Supply_Brute(i-1,arr,target,ds,ans);
    }
};

void solve()
{
    int n,sum;
    cin>>n>>sum;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    Solution soln;
    
    vector<int> ds;
    vector<vector<int>> ans;
    cout<<"Combination Sum Brute: "<<endl;
    soln.Combination_Sum_Infinite_Number_Supply_Brute(n-1,arr,sum,ds,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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
