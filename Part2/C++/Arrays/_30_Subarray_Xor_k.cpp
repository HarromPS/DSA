#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, 
find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.

A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.

Sample Input 1:

4 2
1 2 3 2

Sample Output 1 :

3

Explanation Of Sample Input 1:

Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].

Sample Input 2:

4 3
1 2 3 3

Sample Output 2:

4

Sample Input 3:

5 6
1 3 3 3 5 


*/

class Solution {
public:
    // Brute Solution: TC-O(n^2), SC-O(1)
    void subArrayXorK(vector<int> a,int k){
        // all possible subarrays 
        int count=0;
        int n = a.size();
        for(int i=0;i<n;i++){
            int Xor=0;
            for(int j=i;j<n;j++){
                Xor=Xor^a[j];
                if(Xor==k){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }

    // Better Solution: TC-O(n x log n), SC-O(n)  
    void subArrayXorKOptimal(vector<int> arr,int k){
        // using hasing and prefix sum 
        int count=0;
        int xr = 0;
        int n = arr.size();
        unordered_map<int,int> mp;

        mp[0]=1;
        for(int i=0;i<n;i++){
            xr = xr ^ arr[i];
            // k
            int x = xr ^ k;
            if(mp.find(x)!=mp.end()) {
                count+=mp[x];
            }
            mp[xr]+=1;
        }
        cout<<count<<endl;
    }
};

void solve(){
    int n;  // array size
    int k;
    cin>>n>>k;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr[i]=ip;
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.subArrayXorK(arr,k);
    cout<<"Better: "<<endl;
    s.subArrayXorKOptimal(arr,k);    
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


