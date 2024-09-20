#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array, arr. The task is to find the largest element in it.

Examples:

Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.

*/

class Solution {
public:
    // Brute Solution: TC-O(N logN), SC-O(1)  no extra space is used
    int largest_Brute(vector<int>& arr){
        int n=arr.size();
        // if size is zero return -1
        if(arr.size()==0) return -1;

        int largestElement=0;

        // sorting the array
        sort(arr.begin(),arr.end());

        // return last element
        return arr[n-1];
    }

    // Optimized solution TC-O(N) SC-O(1)  no extra space is used
    int largest(vector<int> &arr) {
        // code here
        int largestElement=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(largestElement<arr[i]) largestElement=arr[i];
        }
        return largestElement;
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
    int res=s.largest_Brute(arr);
    cout<<"Brute: "<<res<<endl;
    res=s.largest(arr);
    cout<<"Optimal: "<<res<<endl;
    
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


