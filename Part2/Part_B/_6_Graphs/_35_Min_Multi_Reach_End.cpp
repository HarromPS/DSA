#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given start, end and an array arr of n numbers. At each step, 
start is multiplied with any number in the array and
then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. 
If it is not possible to reach end, then return -1.

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30

Dijsktra Algo | Shortest Path | BFS | Counting array 
*/



class Solution
{
public:
    // BFS -> will find the shortest path 
    int bfs_shortest(int start,int end,vector<int> arr,vector<int>& dist,int modValue){
        // create a priority queue
        // dist, node
        queue<pair<int,int>> q;

        // add src with time 0 to queue
        q.push({0, start});

        // dist of src is 0 
        dist[start] = 0;

        while (!q.empty()) {
            int n = q.front().second;
            int d = q.front().first;
            q.pop();            

            // Check if we have reached the end
            if (n == end) {
                return d; // Return the distance to the end node
            }

            // Ask neighbors
            for (auto neigh : arr) {
                int mult = (n * neigh) % modValue;

                // Shortest distance 
                if ((1 + d) < dist[mult]) {
                    // Update the distance 
                    dist[mult] = d + 1;

                    // Add it to the queue
                    q.push({d + 1, mult});
                }
            }   
        }
        // Return -1 if end not found
        return -1;
    }


};

void solve()
{
    int n;  // nodes
    int start;    // src
    int end;    // dest
    cin >> n >> start >> end;

    // grid
    vector<int> arr(n,0);
    for(int k=0;k<n;k++){
        int u;
        cin>>u;
        arr[k]=u;
    }
    
    Solution s;
    int modValue = 100000;
    vector<int> dist(modValue,(int)1e9);
    int res = s.bfs_shortest(start,end,arr,dist,modValue);
    cout<<res<<endl;
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
