#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 // DP: better-> Memoization (required answer to base case then back)
// T.C: O(n x k), S.C: O(n x k)

// we say -1 0 1 2 .. n-1
// n = n-1, so 2 = 1, 1 = 2 ..., 1=0
// so i changes i-1 and j changes to j-1
int Longest_Common_Substring_Memoization_Shifting_Index(int i, int j, string str1, string str2, vector<vector<int>>& dp) {
    // base case change
    // if any index goes out of bounary
    if (i == 0 || j == 0) {
        // lcs is 0
        return 0;
    }

    // check if previously solved subproblems
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int res = 0;
    // if characters matched
    if (str1[i-1] == str2[j-1]) {
        // 1 means 1 length string matched
        res = 1+ Longest_Common_Substring_Memoization_Shifting_Index(i - 1, j - 1, str1, str2, dp);
    }else{
        res = 0;
    }
    dp[i][j] = res;
    return dp[i][j];
}

void solve()
{
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Longest_Common_Substring_Memoization_Shifting_Index(i,j,s,t,dp);
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<"DP Memoization Shifing index: "<<ans<<endl;
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
