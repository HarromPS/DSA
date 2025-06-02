#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement
Given an Integer n and a list arr. Sort the array using Quick sort algorithm.
*/

class Solution {
public:
    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[i];    
        arr[i]=arr[j];
        arr[j]=temp;
    }

    int partition(vector<int>& arr,int low,int high){
        int pivot = arr[low];
        int i=low;
        int j=high;

        while(i<=j){
            // find someone smaller than pivot 
            while(arr[j] > pivot && j>=low+1) j--;

            // find someone larger than pivot 
            while(arr[i] <= pivot && i<=high) i++;

            if(i<j) Swap(i,j,arr);
        }

        // swap pivot and j
        Swap(low,j,arr);
        return j;
    }

    void quickSortBrute(vector<int>& arr,int low,int high){
        // quick sort, dividing and conquor algo
        // TC:O(N^2)  SC:O(N) or O(1)
        if(low<high){
            int partionIndex=partition(arr,low,high);
            quickSortBrute(arr,low,partionIndex-1);
            quickSortBrute(arr,partionIndex+1,high);
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
    s.quickSortBrute(arr,0,n-1);
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


