#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Input: intervals = [[1,3],[3,6],[4,7],[8,10],[15,18]]
Output: [[1,7],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [3,6] and [4,7] overlap, merge them into [1,7].
*/

class Solution {
public:
    // Brute Solution: TC-O(n), SC-O(n)
    void mergeIntervals(vector<pair<int,int>> a){
        int n=a.size();
        vector<pair<int,int>> arr(a);
        sort(arr.begin(),arr.end());

        vector<pair<int,int>> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            pair<int,int> p1 = ans.back();
            pair<int,int> p2 = arr[i];
            if(p1.second >= p2.first){
                pair<int,int> newPair = {p1.first, max(p1.second, p2.second)};
                if(ans.size()>0) ans.pop_back();
                ans.push_back(newPair);
            }else{
                ans.push_back(p2);
            }
        }

        for(auto it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<endl;
    }

    // Better Solution: TC-O(n x log n), SC-O(n)  
    void mergeIntervalsOptimal(vector<pair<int,int>> arr){
       
    }
};

void solve(){
    int n;  // array size
    cin>>n;

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        arr.push_back({start,end});
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.mergeIntervals(arr);
    cout<<"Better: "<<endl;
    s.mergeIntervalsOptimal(arr);    
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


