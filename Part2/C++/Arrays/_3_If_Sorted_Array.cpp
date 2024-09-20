#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). 
Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such 
that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the 
element of value 3: [3,4,5,1,2].

*/

class Solution {
public:
    void reverse(int start,int end,vector<int>& arr){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    // Brute Solution: TC-O(N), SC-O(1)  no extra space is used
    bool isSorted_Brute(vector<int>& arr){
        int n=arr.size();
        if(n==1) return true;
        
        // iterate and check if elements are arranged in sorted order 
        int flag=-1;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]) {
                flag=i-1;
                break;
            }
        }
        if(flag==-1) return true;   // array is already sorted

        // also we have to check if array was rotated in circular 
        // perform the rotate operation to check if array was sorted

        // get the index where we see if arr[i] > arr[i+1]
        reverse(0,flag,arr);
        reverse(flag+1,n-1,arr);
        reverse(0,n-1,arr);

        // again check if array was sorted 
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]) {
                return false;
            }
        }
        return true;        
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
    bool res=s.isSorted_Brute(arr);
    cout<<"Brute: "<<(res==0?"No":"Yes")<<endl;
    
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


