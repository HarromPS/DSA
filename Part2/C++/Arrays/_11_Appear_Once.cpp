#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement

You are given a sorted array 'arr' of positive integers of size 'n'.

It contains each number exactly twice except for one number, which occurs exactly once.
Find the number that occurs exactly once.

Example :
Input: ‘arr’ = {1, 1, 2, 3, 3, 4, 4}.
Output: 2
Explanation: 1, 3, and 4 occur exactly twice. 2 occurs exactly once. Hence the answer is 2.
*/

class Solution {
public:
    // Brute Solution: TC-O(n), SC-O(n)
    void getSingleElement(vector<int> a,int n){
        // try all possible cases 
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt=1;  // initially each appears once
            for(int j=0;j<n;j++){
                if(i!=j && a[i]==a[j]) cnt+=1;
            }
            if(cnt==2) continue;
            else {
                ans = a[i];
                break;
            }
        }
        cout<<ans<<endl;
    }

    // Better Solution: TC-O(n), SC-O(1)  
    void getSingleElementBetter(vector<int> arr,int n){
        // map all elements with its frequency
        int ans=0;
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        for(auto it:mp){
            if(it.second==1) {
                ans=it.first;
                break;
            }
        }
        cout<<ans<<endl;
    }

    // Optimal Solution:TC-O(n), SC-O(1)
    void getSingleElementOptimal(vector<int> arr,int n){
        // xor
        int Xor=0;
        for(auto it:arr) Xor^=it;
        cout<<Xor<<endl;
    }

};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.getSingleElement(arr,n);
    cout<<"Better: "<<endl;
    s.getSingleElement(arr,n);
    cout<<"Optimal: "<<endl;
    s.getSingleElement(arr,n);
    
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


