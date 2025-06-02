#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement
Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, 
return the union of the arrays.

The union of two sorted arrays can be defined as an array consisting of the common and 
the distinct elements of the two arrays. 
The final array should be sorted in ascending order.

Note: 'a' and 'b' may contain duplicate elements, 
but the union array must contain unique elements.

Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]

*/

class Solution {
public:

    // Brute Solution: TC-O(n+m+nlog n+log n), SC-O(n+m)  
    void unionArrays(vector<int> a,vector<int>& b){
        // using set 
        set<int> st;    // inserted in sorted manner

        // add all the elements to the set
        int n = a.size();
        int m = b.size();

        for(int i=0;i<n;i++){
            st.emplace(a[i]);
        }
        for(int i=0;i<m;i++){
            st.emplace(b[i]);
        }
        vector<int> union_;
        for(auto it:st) union_.push_back(it);
        for(auto it:union_) cout<<it<<" ";
        cout<<endl;

    }

    // Optimal Solution:TC-O(n+m), SC-O(n+m)  
    void unionArraysOptimal(vector<int> a,vector<int>& b){
        // add all elements & check if prev. added also
        int i=0;
        int j=0;
        int n = a.size(), m = b.size();
        int k=0;
        vector<int> ans;

        // 1st index
        if(a[0]<=b[0]) ans.push_back(a[0]);
        if(a[0]>b[0]) ans.push_back(b[0]);
        k++;

        while(i<n && j<m){
            if(a[i]==b[j]){
                if(k>0 && ans[k-1]!=a[i]){  // reduced set searching
                    ans.push_back(a[i]);    
                    k++;
                }
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                if(k>0 && ans[k-1]!=a[i]){
                    ans.push_back(a[i]);
                    k++;
                }
                i++;
            }
            else if(a[i]>b[j]){
                if(k>0 && ans[k-1]!=b[j]){
                    ans.push_back(b[j]);
                    k++;
                }
                j++;
            }
        }

        while(i<n){
            if(k>0 && ans[k-1]!=a[i]){
                ans.push_back(a[i]);
                k++;
            }
            i++;
        }

        while(j<m){
            if(k>0 && ans[k-1]!=b[j]){
                ans.push_back(b[j]);
                k++;
            }
            j++;
        }

        for(auto it: ans)cout<<it<<" ";
        cout<<endl;
    }

};

void solve(){
    int n;  // array size
    int m;
    cin>>n>>m;

    vector<int> a(n,0);
    vector<int> b(m,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    for(int i=0;i<m;i++){
        cin>>b[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.unionArrays(a,b);
    cout<<"Optimal: "<<endl;
    s.unionArraysOptimal(a,b);
    
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


