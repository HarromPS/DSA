#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. 
Both these arrays are sorted in non-decreasing order.
You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
Note :

1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.


*/

class Solution {
public:

    // Brute Solution: TC-O(n+m+nlog n+log n), SC-O(n+m)  
    void intersectionArrays(vector<int> a,vector<int>& b){
        // see corresponding element in the other array
        int j=0;
        int n=a.size(), m=b.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int k=j;k<m;k++){
                if(a[i]==b[k]){
                    ans.push_back(a[i]);
                    j++;
                    break;
                }else if(a[i] < b[j]){
                    break;
                }
            }
        }
        for(auto it: ans)cout<<it<<" ";
        cout<<endl;

    }

    // Optimal Solution:TC-O(n+m), SC-O(n+m)  
    void intersectionArraysOptimal(vector<int> a,vector<int>& b){
        // add all elements & check if prev. added also
        int i=0;
        int j=0;
        int n = a.size(), m = b.size();
        vector<int> ans;

        while(i<n && j<m){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                i++;
            }
            else if(a[i]>b[j]){
                j++;
            }
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
    s.intersectionArrays(a,b);
    cout<<"Optimal: "<<endl;
    s.intersectionArraysOptimal(a,b);
    
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


