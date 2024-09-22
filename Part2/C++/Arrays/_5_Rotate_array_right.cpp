#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

class Solution {
public:

    // Brute Solution: TC-O(nlog n + n), SC-O(N)  
    void rotateArray(vector<int> arr,int k){
        // By one place
        int n = arr.size();
        int temp = arr[n-1];

        // rotate to right 
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void rotateArray_2(vector<int> arr,int k){
        // By more than 1 place
        int n = arr.size();
        vector<int> temp(n,0);

        for(int i=0;i<n;i++){
            // temp[i]=arr[(i+k+1)%n];

            temp[(i+k)%n]=arr[i];
        }

        for(int i=0;i<n;i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }

    void reverse(int start,int end,vector<int>& arr){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    // Optimal Solution: TC-O(2N), SC-O(1)  no extra space is used
    void rotateArrayOptimal(vector<int>& arr,int k){
        int n=arr.size();
        k=k%n;
        reverse(0,n-k-1,arr);
        reverse(n-k,n-1,arr);
        reverse(0,n-1,arr);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void solve(){
    int n;  // array size
    int k;  // steps
    cin>>n>>k;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.rotateArray(arr,k);
    cout<<"Brute: "<<endl;
    s.rotateArray_2(arr,k);
    cout<<"Optimal: "<<endl;
    s.rotateArrayOptimal(arr,k);
    
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


