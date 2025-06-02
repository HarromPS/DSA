#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

You are given 2 numbers n and m, the task is to find n√m (nth root of m). 
If the root is not integer then returns -1.

Examples :

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.

Input: n = 1, m = 14
Output: 14
*/

class Solution {
public:
    // TC:O(N/2) SC:O(1) gives TLE
    int nthRootBrute(int n, int m) {
        // run a loop till n and check if the number is a square 
        int ans=-1;
        for(int i=1;i<=m;i++){
            int root=1;
            for(int j=1;j<=n;j++){
                root=root*i;
            }
            if(root==m){
                ans=i;
                break;
            }else if(root>m){
                break;
            }
        }
        return ans;
    }

    // TC:O(log n) SC:(1)
    // Overflow for larger m
    int powerExponentiation(int x,int n){
        // pow (x,n)
        if(n==0) return 1;
        if(n==INT_MAX){
            if(x==1) return 1;
        }

        int ans=1;
        while(n>0){
            if(n%2==0){
                // even
                x=x*x;
                n=n/2;
            }else{
                ans=ans*x;
                n-=1;
            }
        }
        return ans;
    }

    int powerExp(int x,int n,int m){
        // return 1 if == m
        // return 0 if < m
        // return 2 if > m
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=x;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        return 0;
    }
    int nthRoot(int n,int m){
        // nth root of m
        // n=3 m=27, so 3rd root of 27 is 3 as 3 x 3 x 3 = 27

        if(n==1 || m==1) return m;
        int ans=-1;
        int low=1;
        int high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            int root=powerExp(mid, n, m);
            if(root==1){
                ans=mid;
                break;
            }
            else if(root==2){
                // more lesser 
                high=mid-1;
            }else{
                // more higher 
                low=mid+1;
            }
        }
        return ans;
    }
};

void solve(){
    int n;  
    int m;
    std::cin>>n;
    std::cin>>m;
    // int target;
    // std::cin>>target;

    // std::vector<int> arr(n,0);
    // for(int i=0;i<n;i++){
    //     std::cin>>arr[i];
    // }   

    Solution s;
    int res=s.nthRootBrute(n,m);
    std::cout<<res<<std::endl;
    res=s.nthRoot(n,m);
    std::cout<<res<<std::endl;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // solve();
    return 0;
}