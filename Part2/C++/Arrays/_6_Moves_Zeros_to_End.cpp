#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array 'arr' of 'n' non-negative integers, 
your task is to move all the zeros to the end of the array while keeping
the non-zero elements at the start of the array in their original order.
Return the modified array.

Input: ‘n’ = 5, ‘arr’ = [1, 2, 0, 0, 2, 3]
Output: [1, 2, 2, 3, 0, 0]
*/

class Solution {
public:

    // Brute Solution: TC-O(nlog n + n), SC-O(N)  
    void movesZerosEnd(vector<int> arr){
        // create a temp array 
        vector<int> temp;

        // collect all non zeros
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=0) temp.push_back(arr[i]);
        }

        // fill all non zero elements to arr
        int m = temp.size();
        for(int i=0;i<m;i++){
            arr[i]=temp[i];
        }

        // fill zeros to end
        for(int i=m;i<n;i++){
            arr[i]=0;
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void swap(int i,int j,vector<int>& arr){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    // Optimal Solution: TC-O(2N), SC-O(1)  no extra space is used
    void movesZerosEndOptimal(vector<int>& arr){
        int n=arr.size();
        
        // bring all the zeros to end by swap using two pointers 
        int j=0,i=j+1;
        while(i<n){
            if(arr[j]==0 && arr[i]!=0){
                // swap 
                swap(j,i,arr);
                // check if previous boundary and is a zero if yes do swap with 1 step back 
                if(j-1>=0 && arr[j-1]==0 && arr[j]!=0){
                    i=j;
                    j=j-1;
                    continue;
                }else{
                    i++;
                    j++;
                }
            }
            else if((arr[j]!=0 && arr[i]!=0) || (arr[j]==0 && arr[i]==0) || (arr[j]!=0 & arr[i]==0)){
                i++;
                j++;
                continue;
            }
        }

        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void movesZerosEndOptimal_2(vector<int>& arr){
        int n = arr.size();
        int j=-1;
        // first zero
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1;i<n;i++){
            if(arr[i]!=0) {
                swap(i,j,arr);
                j++;
            }
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
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
    cout<<"Brute: "<<endl;
    s.movesZerosEnd(arr);
    cout<<"Optimal: "<<endl;
    s.movesZerosEndOptimal(arr);
    cout<<"Optimal 2: "<<endl;
    s.movesZerosEndOptimal_2(arr);
    
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


