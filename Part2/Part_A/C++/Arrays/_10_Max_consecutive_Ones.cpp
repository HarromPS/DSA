#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement

You are given an array ‘ARR’ of length ‘N’ consisting of only ‘0’s and ‘1’s. 
Your task is to determine the maximum length of the consecutive number of 1’s.


For Example:

ARR = [0, 1, 1, 0, 0, 1, 1, 1], here you can see the maximum length of consecutive 1’s is 3. 
Hence the answer is 3.


*/

class Solution {
public:
    // Optimal Solution:TC-O(n), SC-O(1)
    void consecutiveOnes(vector<int> arr,int n){
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) cnt=0;
            else{
                cnt+=1;
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }

};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   

    Solution s;
    cout<<"Optimal: "<<endl;
    s.consecutiveOnes(a,n);
    
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


