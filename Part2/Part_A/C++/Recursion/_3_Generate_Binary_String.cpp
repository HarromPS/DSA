#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/**
 * 
 * Generate all binary strings
 * 
 * 1??0?101
 * 
 * 11101101 11100101 11001101 11000101 10101101 10100101 10001101 10000101 

 */

class Solution
{
public:
    void helper(int i,string s,vector<string> &ds,string ans_str,int n){
        // base case
        if(i>=n){
            ds.push_back(ans_str);
            return;
        }

        // recurrence relation
        // if unknown is there "?" then there are 2 choices
        if(s[i]=='?'){
            // pick 1
            helper(i+1, s, ds, ans_str+'1',n);

            // pick 0
            helper(i+1, s, ds, ans_str+'0',n);
        }else{
            // just add the character default
            helper(i+1, s, ds, ans_str+s[i],n);
        }
    }
    vector<string> generate_binary_string(string s)
    {
        // Code here
        int n = s.size();
        vector<string> ans;
        helper(0, s, ans,"", n);
        return ans;
    }
};

void solve()
{
    string s;
    cin>>s;
    int n=s.size();

    Solution soln;
    vector<string> ans=soln.generate_binary_string(s);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
