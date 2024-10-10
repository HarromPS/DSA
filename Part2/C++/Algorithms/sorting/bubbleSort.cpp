#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Problem statement
Given an Integer n and a list arr. Sort the array using bubble sort algorithm.
*/

class Solution {
public:
    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[i];    
        arr[i]=arr[j];
        arr[j]=temp;
    }

    void bubbleSortBrute(vector<int>& arr){
        // bubble sort, bringing larger element to front 
        // TC:O(N^2)  SC:O(N) or O(1)

        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    Swap(i,j,arr);
                }
            }
        }

        for(auto it:arr) cout<<it<<" ";
        cout<<endl;
    }

    void bubbleSortOptimal(vector<int>& arr){
        // bubble sort, bringing larger element to front 
        int n=arr.size();

        // check if it is already sorted  
        // TC:O(N) best case, O(N^2) worst case 
        int flag=0;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0) return;

        // TC:O(N^2)  SC:O(N) or O(1)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    Swap(i,j,arr);
                }
            }
        }

        for(auto it:arr) cout<<it<<" ";
        cout<<endl;
    }

};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr(n,0);
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        temp.push_back(arr[i]);
    }   

    Solution s;
    cout<<"Before sort:\n";
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;

    cout<<"Brute:\n";
    s.bubbleSortBrute(temp);

    temp.clear();
    for(auto it:arr) temp.push_back(it);

    cout<<"Optimal:\n";
    s.bubbleSortOptimal(temp);
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


