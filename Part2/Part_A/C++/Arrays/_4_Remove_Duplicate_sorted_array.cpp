#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted,
you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

class Solution {
public:

    // Brute Solution: TC-O(nlog n + n), SC-O(N)  
    void removeDuplicatesSorted(vector<int> arr){
        int n=arr.size();

        int countOfDuplicateElements=0;

        set<int> st;
        for(int i=0;i<n;i++){
            st.emplace(arr[i]);
        }

        countOfDuplicateElements = n - st.size();

        // fill the first unique elements
        int i=0;
        for(auto it: st){
            arr[i] = it;
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Optimal Solution: TC-O(N), SC-O(1)  no extra space is used
    void removeDuplicatesSortedOptimal(vector<int>& arr){
        int n=arr.size();
        int countOfDuplicateElements=0;

        int i=0,j=i+1;
        while(j<n){
            if(arr[i]!=arr[j]){
                arr[i+1]=arr[j];
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        countOfDuplicateElements=i+1;   
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
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
    s.removeDuplicatesSorted(arr);
    cout<<"Optimal: "<<endl;
    s.removeDuplicatesSortedOptimal(arr);
    
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


