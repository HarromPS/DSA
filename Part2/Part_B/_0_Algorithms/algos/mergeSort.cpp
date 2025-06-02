#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement
Given an Integer n and a list arr. Sort the array using Merge sort algorithm.
*/

class Solution {
public:
    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[i];    
        arr[i]=arr[j];
        arr[j]=temp;
    }

    void merge(vector<int>& arr,int low,int mid,int high){
        int i=low;
        int j=mid+1;

        vector<int> sorted;
        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                sorted.push_back(arr[i]);
                i++;
            }
            else{
                sorted.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            sorted.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            sorted.push_back(arr[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=sorted[i-low];
        }
    }

    void MergeSortBrute(vector<int>& arr,int low,int high){
        // merge sort, dividing and merging sorted arrays
        // TC:O(N^2)  SC:O(N) or O(1)

        if(low<high){
            int mid=(low+high)/2;
            MergeSortBrute(arr,low,mid);
            MergeSortBrute(arr,mid+1,high);
            merge(arr,low,mid,high);
        }

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
    cout<<"Before sort:\n";
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;

    cout<<"Brute:\n";
    s.MergeSortBrute(arr,0,n-1);
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
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


