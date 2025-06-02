#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
=>
Given an array arr of size n of non-negative integers and an integer sum, 
the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.
*/
class Solution
{
public:
    // Brute force
    int Combination_Sum_Brute(int i,vector<int>& arr,int target)
    {
        // base case
        if(i<0){
            if(target==0){
                return 1;
            }
            return 0;
        }

        // recurrence relation
        // check if target is achievable
        int pick = 0;
        if(target - arr[i] >= 0){
            pick = Combination_Sum_Brute(i-1,arr,target-arr[i]);
        }

        // non pick 
        int nonPick = Combination_Sum_Brute(i-1,arr,target);

        // return the total count 
        return pick+nonPick;
    }

    // DP Memoization
    int Combination_Sum_Memoization(int i,vector<int>& arr,int target,vector<vector<int>>& dp)
    {
        // base case
        // if(i<0){
        //     if(target==0){
        //         return 1;
        //     }
        //     return 0;
        // }

        if(i==0){
            if(target==0){      // if target is already 0 means we got a subsequence before, so no need to see for index 0 element
                return 1;
            }
            if(target-arr[i] == 0 ){    // if target is still, reachable then try if we can get it by picking 0th index
                return 1;
            }

            // just return 0 other wise, means no sequence is formed
            return 0;
        }

        // check if subproblems are previously solved
        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        // recurrence relation
        // check if target is achievable
        int pick = 0;
        if(target - arr[i] >= 0){
            pick = Combination_Sum_Memoization(i-1,arr,target-arr[i],dp);
        }

        // non pick 
        int nonPick = Combination_Sum_Memoization(i-1,arr,target,dp);
        
        // save the calculations
        dp[i][target] = pick + nonPick;

        // return the total count 
        return dp[i][target];
    }

    // DP Tabulation
    int Combination_Sum_Tabulation(vector<int>& arr,int n,int target)
    {   
        int dp[n][target+1];

        // filled with 0 initially 
        for(int i=0;i<n;i++){
            for(int j=0;j<target+1;j++){
                dp[i][j]=0;     // no value got yet
            }
        }

        // base case
        // if(i<0){
        //     if(target==0){
        //         return 1;
        //     }
        //     return 0;
        // }

        // shifting index
        // i -> i+1 
        /*
        if(i==0){
            if(target==0){      // if target is already 0 means we got a subsequence before, so no need to see for index 0 element
                return 1;
            }
            if(target-arr[i] == 0 ){    // if target is still, reachable then try if we can get it by picking 0th index
                return 1;
            }

            // just return 0 other wise, means no sequence is formed
            return 0;
        }
        */

        // 1st condition
        dp[0][0]=1;

        // 2nd condition, for any target if it is achievable mark it 1, for index 0
        /*
        
        target - arr[0] >= 0: This checks if the target sum minus the first element is non-negative,
        meaning it is possible to include the first element in the subset to achieve some sum.
        
        dp[0][arr[0]] += 1;: This updates the dp table to indicate that there is one way to achieve the 
        sum arr [0] using the first element. The += 1 is used to account for this single way.

        */
        if(target-arr[0] >=0){
            dp[0][arr[0]] += 1;     
        }

        // recurrence relation
        for(int i = 1;i<n;i++){
            for(int tar = 0; tar <= target; tar++){
                // pick
                int pick = 0;
                if(tar - arr[i] >=0 ){
                    pick = dp[i-1][tar-arr[i]];
                }
                int nonPick = dp[i-1][tar];
                dp[i][tar] = pick+nonPick;
            }
        }

        return dp[n-1][target];
    }
    // DP Space Optimizaion
    int Combination_Sum_Optimized(vector<int>& arr,int n,int target)
    {   
        vector<int> prev(target+1,0);        
        // 1st condition
        prev[0]=1;

        // 2nd condition, for any target if it is achievable mark it 1, for index 0
        /*
        
        target - arr[0] >= 0: This checks if the target sum minus the first element is non-negative,
        meaning it is possible to include the first element in the subset to achieve some sum.
        
        dp[0][arr[0]] += 1;: This updates the dp table to indicate that there is one way to achieve the 
        sum arr [0] using the first element. The += 1 is used to account for this single way.

        */
        if(target-arr[0] >=0){
            prev[arr[0]] += 1;     
        }

        // recurrence relation
        for(int i = 1;i<n;i++){
            vector<int> curr(target+1,0);
            curr[0]=1;          // for each target 0 ans is 1
            for(int tar = 0; tar <= target; tar++){
                // pick
                int pick = 0;
                if(tar - arr[i] >=0 ){
                    pick = prev[tar-arr[i]];
                }
                int nonPick = prev[tar];
                curr[tar] = pick+nonPick;
            }
            // update prev
            prev = curr;

        }

        return prev[target];
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
    
    int ans = soln.Combination_Sum_Brute(n-1,arr,sum);
    cout<<"Combination Sum Brute: "<<ans<<endl;

    // only one index i.e "i"
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    ans = soln.Combination_Sum_Memoization(n-1,arr,sum,dp);
    cout<<"Combination Sum Memoization: "<<ans<<endl; 

    ans = soln.Combination_Sum_Tabulation(arr,n,sum);
    cout<<"Combination Sum Tabulation: "<<ans<<endl; 

    ans = soln.Combination_Sum_Optimized(arr,n,sum);
    cout<<"Combination Sum Optimized: "<<ans<<endl;    


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
