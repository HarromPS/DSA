#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

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
    void reversePairsBrute(vector<int> arr){
        // generate all the pairs 
        int count = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>2*arr[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    
    void merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp(mid+1-low + high-mid,0);
        int i=low;
        int j=mid+1;
        int k=0;

        while(i<mid+1 && j<high+1){
            if(arr[i]>arr[j]){
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
    }

    int mergeSort(vector<int>& arr,int low,int high){
        int count=0;
        if(low<high){
            int mid=(low+high)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);
            count+=countReversePairs(arr,low,mid,high);
            merge(arr,low,mid,high);
        }
        return count;
    }

    int countReversePairs(vector<int> &arr, int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int i=low;i<mid+1;i++){
            while(right<high+1 && arr[i]>(2*arr[right])){
                right++;
            }
            // when above loop breaks, count the number of elements forming pairs 
            count=count+(right-(mid+1));
        }
        return count;
    }

    // Optimal Solution: TC-O(n x log n), SC-O(1)  
    void reversePairsOptimal(vector<int>& arr){
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
    s.reversePairsBrute(arr);  
    cout<<"Optimal 2: "<<endl;
    s.reversePairsOptimal(arr);    
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


