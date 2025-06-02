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
    // Brute force Solution:TC-O(n^2), SC-O(n)
    void leaderInarray(vector<int> arr){
        // check all the elements to be a leader 
        int n=arr.size();
        
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(arr[i]);
            }
        }
        // add last element as first leader 
        ans.push_back(arr[n-1]);

        for(auto it:ans) cout<<it<<" ";
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

    // Optimal Solution:TC-O(n), SC-O(n)
    // 16, 17, 4, 3, 5, 2
    void leaderInarrayOptimal(vector<int>& arr){
        // see from the last, 2 will always be 1st leader 
        // 3 is not included because 5 is greatest leader on right 
        // we got a new leader 17 which is greater than previous leader i.e 5
        // so traverse from behind 

        int n=arr.size();
        int leader=arr[n-1];
        vector<int> ans;
        // add last element as first leader 
        ans.push_back(leader);

        for(int i=n-2;i>=0;i--){
            if(arr[i]>leader){
                // update the leader 
                leader=arr[i];
                ans.push_back(leader);
            }
        }

        // just reverse 
        reverse(0,ans.size()-1,ans);
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
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
    s.leaderInarray(arr);
    
    cout<<"Optimal: "<<endl;
    s.leaderInarrayOptimal(arr);

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


