#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array arr of n positive integers, 
your task is to find all the leaders in the array. 
An element of the array is considered a leader if it is greater than all the elements on its right side 
or if it is equal to the maximum element on its right side. 
The rightmost element is always a leader.

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

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

    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(n^2), SC-O(n)
    void longestConsecutiveSequence(vector<int> arr){
              
    }

    // Optimal Solution:TC-O(n), SC-O(n)
    // 16, 17, 4, 3, 5, 2
    void longestConsecutiveSequenceOptimal(vector<int>& arr){
       
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
    s.longestConsecutiveSequence(arr);
    
    cout<<"Optimal: "<<endl;
    s.longestConsecutiveSequenceOptimal(arr);

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


