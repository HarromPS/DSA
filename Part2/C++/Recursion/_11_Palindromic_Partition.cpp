#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

=>  Palindrome Partitioning

Given a string s, partition s such that every
substring
of the partition is a
palindrome
Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

*/
class Solution
{
public:

    bool is_palindrome(int i,int j, string s){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Brute force
    // T.C: O(2^n)
    // Generate all palindromic substrings
    // S.C: O(n)
    void Palindromic_Substrings(int index,string s,vector<string>& ds,vector<vector<string>>& ans,int n)
    {      
        // base case
        if(index >= n){
            ans.push_back(ds);
            return;
        }

        // iterate all the substrings and check if palindrome, then add to answer 
        for(int i=index;i<n;i+=1){
            if(is_palindrome(index, i, s)==true){
                ds.push_back(s.substr(index, i - index + 1));
                Palindromic_Substrings(i+1,s,ds,ans,n);
                ds.pop_back();
            }
        }
    }
};

void solve()
{
    string s;
    cin>>s;
    Solution soln;

    int n = s.size();
    vector<string> ds;
    vector<vector<string>> ans;
    cout<<"All Subsets No Duplicates Brute: "<<endl;
    soln.Palindromic_Substrings(0,s,ds,ans,n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"|";
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
