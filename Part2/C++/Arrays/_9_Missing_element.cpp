#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 Problem statement

Given an array ‘a’ of size ‘n’-1 with elements of range 1 to ‘n’. 
The array does not contain any duplicates. Your task is to find the missing number.
Input:
'a' = [1, 2, 4, 5], 'n' = 5

Output :
3

Explanation: 3 is the missing value in the range 1 to 5.
*/

class Solution {
public:

    // Brute Solution: TC-O(n), SC-O(n)
    void missingElement(vector<int> arr,int n){
        // map all the elements between 1 to n
        map<int,int> mp;
        for(int i=1;i<=n;i++) mp[i]=0;
        for(auto it:arr) {
            if(mp.find(it)!=mp.end()){
                mp[it]=1;
            }
        }
        for(auto it: mp){
            if(it.second==0){
                cout<<it.first<<endl;
                break;
            }
        }
    }

    // Better Solution: TC-O(n), SC-O(1)  
    void missingElementOptimal_1(vector<int> arr,int n){
        int xor1=0;
        int xor2=0;
        for(int i=1;i<=n;i++) xor1^=i;
        for(int i=0;i<n;i++) xor2^=arr[i];
        int ans = xor1^xor2;
        cout<<ans<<endl;
    }

    // Optimal Solution:TC-O(n), SC-O(1)
    void missingElementOptimal(vector<int> arr,int n){
        // sum 
        int sum = (n*(n+1))/2;
        int sumOfAll=0;
        for(auto it:arr) sumOfAll+=it;
        int ans = sum-sumOfAll;
        cout<<ans<<endl;
    }

};

void solve(){
    int n;  // array size
    int k;
    cin>>n>>k;

    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.missingElement(a,k);
    cout<<"Optimal xor: "<<endl;
    s.missingElementOptimal_1(a,k);
    cout<<"Optimal: "<<endl;
    s.missingElementOptimal(a,k);
    
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


