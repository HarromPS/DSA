#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
=> LCS of palindrome 

Given a string,
find the minimum number of characters to be inserted to convert it to a palindrome.

e.g

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked with bold characters in dcbabcd, 
here we need minimum three characters to make it palindrome.

*/

// find LCS of string 
// Original string length - LCS length => returns the count of min numbers required to be inserted to make the srting a palindrome

class Solution
{
public:
    // Brute force
    // T.C: O(2^n)
    // S.C: O(n)
    int LCS_Min_Insert_Palindrome_Brute(int i,int j, string s1,string s2){
        // base case
        // if any index goes out of boundry
        if(i<0 || j<0){
            return 0;   // 0 length of the string remained matched
        }

        // if character matches
        if(s1[i] == s2[j]){
            int matched = 1 + LCS_Min_Insert_Palindrome_Brute(i-1,j-1,s1,s2);
            return matched;
        }
        
        // if not matched
        int move_i = 0 + LCS_Min_Insert_Palindrome_Brute(i-1,j,s1,s2);
        int move_j = 0 + LCS_Min_Insert_Palindrome_Brute(i,j-1,s1,s2);

        return max(move_i,move_j);
    }

    // i-> i-1, n-1 => n
    // j-> j-1  m-1 => m
    int LCS_Min_Insert_Palindrome_Brute_Shifting_Index(int i,int j, string s1,string s2){
        // base case
        // if any index goes out of boundry
        if(i==0 || j==0){
            return 0;   // 0 length of the string remained matched
        }

        // if character matches
        if(s1[i-1] == s2[j-1]){
            int matched = 1 + LCS_Min_Insert_Palindrome_Brute(i-1,j-1,s1,s2);
            return matched;
        }
        
        // if not matched
        int move_i = 0 + LCS_Min_Insert_Palindrome_Brute(i-1,j,s1,s2);
        int move_j = 0 + LCS_Min_Insert_Palindrome_Brute(i,j-1,s1,s2);

        return max(move_i,move_j);
    }

    int LCS_Min_Insert_Palindrome_Memoization(int i,int j, string s1,string s2,vector<vector<int>>& dp){
        // base case
        // if any index goes out of boundry
        if(i<0 || j<0){
            return 0;   // 0 length of the string remained matched
        }

        // check if subproblems are already solved or not
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if character matches
        if(s1[i] == s2[j]){
            int matched = 1 + LCS_Min_Insert_Palindrome_Memoization(i-1,j-1,s1,s2,dp);
            dp[i][j]=matched;
            return dp[i][j];
        }
        
        // if not matched
        int move_i = 0 + LCS_Min_Insert_Palindrome_Memoization(i-1,j,s1,s2,dp);
        int move_j = 0 + LCS_Min_Insert_Palindrome_Memoization(i,j-1,s1,s2,dp);

        dp[i][j] = max(move_i,move_j);
        return dp[i][j];
    }

    // i-> i-1, n-1 => n
    // j-> j-1  m-1 => m
    int LCS_Min_Insert_Palindrome_Memoization_Shifting_Index(int i,int j, string s1,string s2,vector<vector<int>>& dp){
        // base case
        // if any index goes out of boundry
        if(i==0 || j==0){
            return 0;   // 0 length of the string remained matched
        }

        // check if subproblems are already solved or not
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if character matches
        if(s1[i-1] == s2[j-1]){
            int matched = 1 + LCS_Min_Insert_Palindrome_Memoization_Shifting_Index(i-1,j-1,s1,s2,dp);
            dp[i][j] =  matched;
            return dp[i][j];
        }
        
        // if not matched
        int move_i = 0 + LCS_Min_Insert_Palindrome_Memoization_Shifting_Index(i-1,j,s1,s2,dp);
        int move_j = 0 + LCS_Min_Insert_Palindrome_Memoization_Shifting_Index(i,j-1,s1,s2,dp);

        dp[i][j] = max(move_i,move_j);
        return dp[i][j];
    }

    int LCS_Min_Insert_Palindrome_Tabulation(int n,int m, string s1,string s2){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // base case
        // for all j when i=0
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }

        // for all i when j=0
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }

        // recurrence relation
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{                
                    // if not matched
                    int move_i = 0 + dp[i-1][j];
                    int move_j = 0 + dp[i][j-1];
                    dp[i][j] = max(move_i,move_j);
                }

            }
        }
        return dp[n][m];
    }
    int LCS_Min_Insert_Palindrome_DP_Optimized(int n,int m, string s1,string s2){
        vector<int> prev(m+1,0);

        // recurrence relation
        for(int i=1;i<n+1;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{                
                    // if not matched
                    int move_i = 0 + prev[j];
                    int move_j = 0 + curr[j-1];
                    curr[j] = max(move_i,move_j);
                }
            }
            // update prev
            prev = curr;
        }
        return prev[m];
    }
};

void solve()
{
    string s;
    cin>>s;
    int n = s.size();

    string rev="";
    for(int i=n-1;i>=0;i--){
        rev+=s[i];
    }
    Solution soln;

    int ans = soln.LCS_Min_Insert_Palindrome_Brute(n-1,n-1,s,rev);
    cout<<"Brute LCS: "<<ans<<endl;

    ans = soln.LCS_Min_Insert_Palindrome_Brute_Shifting_Index(n,n,s,rev);
    cout<<"Brute Shifting Index LCS: "<<ans<<endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    ans = soln.LCS_Min_Insert_Palindrome_Memoization(n-1,n-1,s,rev,dp);
    cout<<"DP Memoization LCS: "<<ans<<endl;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            dp[i][j]=-1;
        }
    }
    ans = soln.LCS_Min_Insert_Palindrome_Memoization_Shifting_Index(n,n,s,rev,dp);
    cout<<"DP Memoization Shifting Index LCS: "<<ans<<endl;

    ans = soln.LCS_Min_Insert_Palindrome_Tabulation(n,n,s,rev);
    cout<<"DP Tabulation: "<<ans<<endl;

    ans = soln.LCS_Min_Insert_Palindrome_DP_Optimized(n,n,s,rev);
    cout<<"DP Optimized: "<<ans<<endl;

    cout<<"\nMinimum number of characters to be inserted to convert it to a palindrome: "<<(n-ans)<<endl;
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

