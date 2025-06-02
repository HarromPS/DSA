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
    void SubSet_Sum_Brute(int i,vector<int>& arr,vector<int>& ds)
    {   
        // base case
        if(i<0){
            // print ds
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }

        // pick
        ds.push_back(arr[i]);
        SubSet_Sum_Brute(i-1, arr,ds);

        // dont pick
        ds.pop_back();
        SubSet_Sum_Brute(i-1,arr,ds);
    }

    void SubSet_Sum_Brute_Sum(int i,vector<int>& arr,vector<int>& ds,int sum)
    {   
        // base case
        if(i<0){
            // print ds
            cout<<sum<<" ";
            return;
        }

        // pick
        ds.push_back(arr[i]);
        SubSet_Sum_Brute_Sum(i-1, arr,ds,sum+arr[i]);

        // dont pick
        ds.pop_back();
        SubSet_Sum_Brute_Sum(i-1,arr,ds,sum);
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    Solution soln;
    
    vector<int> ds;
    cout<<"All Subsets Brute: "<<endl;
    soln.SubSet_Sum_Brute(n-1,arr,ds);

    ds.clear();
    cout<<"All Subsets Brute with sum: "<<endl;
    soln.SubSet_Sum_Brute_Sum(n-1,arr,ds,0);

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
