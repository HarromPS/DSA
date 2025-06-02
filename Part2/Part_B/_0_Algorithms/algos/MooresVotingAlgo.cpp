#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Moore's Voting Algorithm
if there is an element which is > n/2, which does not get cancelled -> majority element 

Given an array arr.
Find the majority element in the array. 
If no majority exists, return -1.

A majority element in an array is an element that appears strictly more than arr.size()/2 
times in the array.

Input: arr[] = [3, 1, 3, 3, 2]
Output: 3
Explanation: Since, 3 is present more than n/2 times, so it is the majority element.
*/

class Solution {
public:
   
    void MajorityElementOptimal(vector<int>& arr){
        int ele=-1;
        int cnt=0;
        int n = arr.size();
        
        // apply moore's algo 
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele=arr[i];
            }
            else if(arr[i]==ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        // verify if ele is a majority element
        cnt=0;
        for(int i=0;i<n;i++){
            if(ele==arr[i]) cnt++;
        }
        if(cnt > (n/2)) cout<<ele<<endl;
        else cout<<-1<<endl;
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
    s.MajorityElementOptimal(arr);
    
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


