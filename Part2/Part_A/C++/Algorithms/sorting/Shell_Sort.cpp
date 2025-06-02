#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement
Given an Integer n and a list arr. Sort the array using Shell sort algorithm.
*/

class Solution {
public:
    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[i];    
        arr[i]=arr[j];
        arr[j]=temp;
    }

    void ShellSort(vector<int>& arr){
        // Generalization of Insertion sort 
        // TC:O(n log n) best case
        // TC:O(n log (n)^2) average case
        // TC:O(n^2) worst case

        // sort far distance elements, subsequently reduce gap between them, apply insertion at the end

        int n=arr.size();
        for(int interval=n/2; interval > 0 ; interval/=2){
            // start sorting by interval elements 
            for(int i=interval;i<n;i+=1){
                int temp = arr[i];
                int j=i;
                for(j=i;j>=interval && (arr[j-interval] > temp); j-=interval){   
                    // move with a space as the interval size
                    arr[j]=arr[j-interval];
                }

                // put temp (the original a[i]) in its correct position  
                arr[j]=temp; // if above no swaps happens, then same element is assigned 
            }
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
    for(auto it:arr) {
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<"Shell Sort:\n";
    s.ShellSort(arr);

    cout<<"Before sort:\n";
    for(auto it:arr) {
        cout<<it<<" ";
    }
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


