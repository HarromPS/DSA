/*

One day, the schoolboy Mark misbehaved, so the teacher Sasha called him to the whiteboard.

Sasha gave Mark a table with n
rows and m columns. His task is to arrange the numbers 0,1,…,n⋅m−1 in the table (each number must be used exactly once) in such a way as to maximize the sum of MEX∗ across all rows and columns. More formally, he needs to maximize
∑i=1nmex({ai,1,ai,2,…,ai,m})+∑j=1mmex({a1,j,a2,j,…,an,j}),
where ai,j is the number in the i-th row and j

-th column.

Sasha is not interested in how Mark arranges the numbers, so he only asks him to state one number — the maximum sum of MEX across all rows and columns that can be achieved.

∗
The minimum excluded (MEX) of a collection of integers c1,c2,…,ck is defined as the smallest non-negative integer x which does not occur in the collection c

.

For example:

    mex([2,2,1])=0

, since 0
does not belong to the array.
mex([3,1,0,1])=2
, since 0 and 1 belong to the array, but 2
does not.
mex([0,3,1,2])=4
, since 0, 1, 2, and 3 belong to the array, but 4 does not. 

The question revolves around arranging numbers in a grid (table) in such a way as to maximize a specific mathematical property. Here's a breakdown:
Key Concepts:

Grid Dimensions:
The table has nn rows and mm columns, creating a grid with n×mn×m cells.

Numbers to Arrange:
The numbers 0,1,2,…,(n⋅m−1)0,1,2,…,(n⋅m−1) are to be arranged in the grid. Each number must appear exactly once.

MEX (Minimum Excluded Value):
For a given set of numbers, the MEX is the smallest non-negative integer that does not appear in the set.

*/

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec;
    int x=0;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            temp.push_back(x);
            // cout<<x<<" ";
            x++;
        }
        // cout<<endl;
        vec.push_back(temp);
    }

    int rowSum=0;

    map<int,int> mp;
    for(int i=0;i<=m*n;i++) mp[i]=0; // reset

    // traverse each row 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp.find(vec[i][j])!=mp.end()) {  // present
                mp[vec[i][j]]=1;    // check attendance of every integer
            }
        }
        for(auto it: mp){
            if(it.second==0){
                rowSum+=it.first;
                break;
            }
        }
        // reset 
        for(int i=0;i<=m*n;i++) mp[i]=0; 
    }   

    int colSum=0;
    // traverse each column
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(mp.find(vec[i][j])!=mp.end()) {  // present
                mp[vec[i][j]]=1;    // check attendance of every integer
            }
        }
        for(auto it: mp){
            if(it.second==0){
                colSum+=it.first;
                break;
            }
        }
        // reset 
        for(int i=0;i<=m*n;i++) mp[i]=0; 
    }

    cout<<rowSum+colSum<<endl;
}

void solve_2(){
    int n,m;
    cin>>n>>m;
    cout<<max(n,m)+1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        // solve();
        solve_2();
    }
    // solve();
    return 0;
}


// lets see 

// rows wise first 
// 9
// 0
// 0
// 0
// 0
// 0
// 0
// 0

// col wise
// 1 0 0 0 0 0 0 0 