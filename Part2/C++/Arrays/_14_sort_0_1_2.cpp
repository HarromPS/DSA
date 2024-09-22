#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.
Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
*/

class Solution {
public:
    // Brute Solution: TC-O(n), SC-O(n)
    void Sort012(vector<int> a){
        // collect all 0's 1's 2's in 3 diffferent arrays and fill in original array as sorted 
        vector<int> zeros,ones,twos;
        int n = a.size();
        for(int i=0;i<n;i++){ 
            if(a[i]==0) {
                zeros.push_back(0);
            }
        }

        for(int i=0;i<n;i++){ 
            if(a[i]==1) {
                ones.push_back(1);
            }
        }

        for(int i=0;i<n;i++){ 
            if(a[i]==2) {
                twos.push_back(2);
            }
        }

        int k=0;
        for(int i=0;i<zeros.size();i++) {
            a[k] = zeros[i];
            k++;
        }

        for(int i=0;i<ones.size();i++) {
            a[k] = ones[i];
            k++;
        }

        for(int i=0;i<twos.size();i++) {
            a[k] = twos[i];
            k++;
        }


        for(int i=0;i<k;i++) 
            cout<<a[i]<<" ";
        cout<<endl;
    }

    // for positive and ones and negatives max optimization
    // Better Solution: TC-O(n), SC-O(n)  
    void Sort012Better(vector<int> arr){
        // using freq variables 
        int zeros=0,ones=0,twos=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeros++;
            }
            else if(arr[i]==1){
                ones++;
            }
            else twos++;
        }
        int i=0;
        while(zeros>0){
            arr[i]=0;
            zeros--;
            i++;
        }
        while(ones>0){
            arr[i]=1;
            ones--;
            i++;
        }
        while(twos>0){
            arr[i]=2;
            twos--;
            i++;
        }
        for(i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
        
    }

    void swap(int i,int j,vector<int>& arr){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // max optimization till positives and zeros
    // Optimal Solution:TC-O(n/2), SC-O(n)
    void Sort012Optimal(vector<int>& arr){
        // Dutch National Flag Algorithm
        int n = arr.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(mid,low,arr);
                mid++;
                low++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(mid,high,arr);
                high--;
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
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
    s.Sort012(arr);
    cout<<"Better: "<<endl;
    s.Sort012Better(arr);
    cout<<"Optimal: "<<endl;
    s.Sort012Optimal(arr);
    
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


