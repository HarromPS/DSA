#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

=> Subset sum

Given a list arr of n integers, 
return sums of all subsets in it. 
Output sums can be printed in any order.

Input:
n = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

*/
class Solution
{
public:
    // Brute force
    // T.C: O(2^n)
    // Generate all subsets
    // S.C: O(n)
    void SubSet_Sum_Brute_No_Duplicates(int index,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans)
    {      
        int n = arr.size();
        ans.push_back(ds);    

        // pick subsequences
        for(int i=index;i<n;i++){
            // check if there are any duplicates 
            if(i > index && arr[i]==arr[i-1]){
                continue;   // skip it
            }

            // pick
            ds.push_back(arr[i]);
            SubSet_Sum_Brute_No_Duplicates(i+1, arr,ds,ans);

            // dont pick
            ds.pop_back();
        }
    
    }

    void SubSet_Sum_Brute_No_Duplicates_Sum(int index,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans,int target)
    {   
        int n = arr.size();
        if(target==0){
            ans.push_back(ds);                
            return;
        }

        // pick subsequences
        for(int i=index;i<n;i++){
            // check if there are any duplicates 
            if(i > index && arr[i]==arr[i-1]){
                continue;   // skip it
            }

            // if target is achievable
            if(arr[i] > target){    
                break;  // not acheivable as array is sorted so, larger elements ahead
            }

            // pick
            ds.push_back(arr[i]);
            target=target-arr[i];
            SubSet_Sum_Brute_No_Duplicates_Sum(i+1, arr,ds,ans,target);

            // dont pick
            target=target+arr[i];
            ds.pop_back();
        }
    }
};

void solve()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    Solution soln;
    
    // Sort the array first for duplicate checking 
    sort(arr.begin(),arr.end());

    vector<int> ds;
    vector<vector<int>> ans;
    cout<<"All Subsets No Duplicates Brute: "<<endl;
    soln.SubSet_Sum_Brute_No_Duplicates(0,arr,ds,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    ds.clear();
    ans.clear();
    cout<<"All Subsets Brute with sum: "<<endl;
    soln.SubSet_Sum_Brute_No_Duplicates_Sum(0,arr,ds,ans,target);

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
