#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Input: intervals = [[1,3],[3,6],[4,7],[8,10],[15,18]]
Output: [[1,7],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [3,6] and [4,7] overlap, merge them into [1,7].
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
    // Brute Solution: TC-O(2 x (m+n)) SC-O(m+n)
    void mergeSortedArrays(vector<int> a,int m,vector<int> b,int n){
        if(n==0) return;
        if(m==0){
            for(int i=0;i<n;i++){
                a[i-m]=b[i];
            }
            return;
        }
        int i=0;
        int j=0;
        vector<int> temp;
        while(i<m && j<n){
            if(a[i]<b[j]){
                temp.push_back(a[i]);
                i++;
            }else{
                temp.push_back(b[j]);
                j++;
            }
        }
        while(i<m){
            temp.push_back(a[i]);
            i++;
        }   
        while(j<n){
            temp.push_back(b[j]);
            j++;
        }
        for(int i=0;i<m;i++){
            a[i]=temp[i];
        }
        for(int i=0;i<n;i++){
            b[i]=temp[m+i];
        }
        for(auto it:a) cout<<it<<" ";
        for(auto it:b) cout<<it<<" ";
        cout<<endl;

    }

    // Optimal Solution: TC-O(min(n,m)  + n log n + m log m) SC-O(1)
    void mergeSortedArraysOptimal_1(vector<int> a,int m,vector<int> b,int n){
        if(n==0) return; 
        if(m==0){
            for(int i=0;i<n;i++){
                a[i-m]=b[i];
            }
            return;
        }
        int i=m-1;
        int j=0;
        while(i>=0 && j<n){
            if(a[i] > b[j]){
                int temp=a[i];
                a[i]=b[j];
                b[j]=temp;
                i--;
                j++;
            }else{
                break;
            }
        }

        // sort both: as all elements are in their proper set 
        sort(a.begin(),a.begin()+m);
        sort(b.begin(),b.end());

        // for(i=m;i<(m+n);i++){
        //     a[i]=b[i-m];
        // }

        for(auto it:a)  cout<<it<<" ";
        for(auto it:b)  cout<<it<<" ";
        cout<<endl;
    }

private:
    void Swap_2(vector<int>& a,vector<int>& b, int i, int j){
        if(a[i]>b[j]){
            int temp=a[i];
            a[i]=b[j];
            b[j]=temp;
        }
    }

public:
    // Optimal Solution: TC-O(n x log n), SC-O(n)  
    void mergeSortedArraysOptimal_2(vector<int>& a,int m,vector<int>& b,int n){
        // using Gap method (Shell Sort)
        int len = (n+m);
        int gap = (len/2) + (len%2);
        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                // if both left and right pointers are arr1 arr2
                if(left<m && right>=m   ){
                    Swap_2(a,b,left,right-m);
                }
                // arr2 arr2
                else if(left>=m){
                    Swap_2(b,b,left-m,right-m);
                }
                // arr1 arr1
                else if(right<m){
                    Swap_2(a,a,left,right);
                }
                left++;
                right++;
            }
            if(gap==1) break;
            gap = (gap/2) + (gap%2);
        }

        for(auto it:a) cout<<it<<" ";
        for(auto it:b) cout<<it<<" ";
        cout<<endl;

    }
};

void solve(){
    int m,n;  // array size
    cin>>m>>n;

    vector<int> a,b;
    for(int i=0;i<m;i++){
        int ip;
        cin>>ip;
        a.push_back(ip);
    }   
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        b.push_back(ip);
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.mergeSortedArrays(a,m,b,n);
    cout<<"Better: "<<endl;
    s.mergeSortedArraysOptimal_1(a,m,b,n);
    cout<<"Optimal: "<<endl;
    s.mergeSortedArraysOptimal_2(a,m,b,n);    
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


