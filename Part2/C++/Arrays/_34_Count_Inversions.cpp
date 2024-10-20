#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array of integers. Find the Inversion Count in the array. 
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

*/

class Solution {
public:
    void Swap(vector<int>& a,vector<int>& b,int i,int j){
        int temp=a[i];
        a[i]=b[j];
        b[j]=temp;
    }

    void reverse(int start,int end,vector<int>& a){
        while(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
            end--;
        }
    }
    // Brute Solution: TC-O(n^2) SC-O(1)
    void countInversionBrute(vector<int> arr){
        // generate all the pairs 
        int count = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    
    int merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp(mid+1-low + high-mid,0);
        int i=low;
        int j=mid+1;
        int k=0;

        int count=0;
        while(i<mid+1 && j<high+1){
            if(arr[i]>arr[j]){
                count+=(mid+1-i);
                temp[k]=arr[j];
                j++;
                k++;
            }
            else{
                temp[k]=arr[i];
                i++;
                k++;
            }
        }
        while(i<mid+1){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<high+1){
            temp[k]=arr[j];
            j++;
            k++;
        }
        // refill the array  
        for(i=low;i<high+1;i++){
            arr[i] = temp[i-low];
        }

        return count;
    }

    int mergeSort(vector<int>& arr,int low,int high){
        int count=0;
        if(low<high){
            int mid=(low+high)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);
            count+=merge(arr,low,mid,high);
        }
        return count;
    }

    // Optimal Solution: TC-O(n x log n), SC-O(1)  
    void countInversionArraysOptimal(vector<int>& arr){
        // using mergem sort, find pairs when merge sort happens 
        int n=arr.size();
        int count=mergeSort(arr,0,n-1);
        cout<<count<<endl;
    }
};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr.push_back(ip);
    }   

    Solution s;
    cout<<"Brute 1: "<<endl;
    s.countInversionBrute(arr);  
    cout<<"Optimal 2: "<<endl;
    s.countInversionArraysOptimal(arr);    
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


