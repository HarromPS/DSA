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
        int temp = arr[0];

        // rotate to left 
        for(int i=1;i<n;i++){
            arr[i-1]=arr[i];
        }
        arr[n-1]=temp;

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void rotateArray_2(vector<int> arr,int k){
        // By more than 1 place
        int n = arr.size();
        vector<int> temp(k,0);

        k=k%n;

        // add d elements to temp array
        for(int i=0;i<k;i++){
            temp[i]=arr[i];
        }

        // shifting
        for(int i=k;i<n;i++){
            arr[i-k]=arr[i];
        }

        // fill the rest elements from temp to arr
        for(int i=n-k;i<n;i++){
            arr[i]=temp[i-(n-k)];
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
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
    // Optimal Solution: TC-O(N), SC-O(1)  no extra space is used
    void rotateArrayOptimal(vector<int>& arr,int k){
        int n=arr.size();
        k=k%n;
        reverse(0,k-1,arr);
        reverse(k,n-1,arr);
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


