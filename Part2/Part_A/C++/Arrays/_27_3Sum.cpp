#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Example 1:

Input: nums = [3,2,3]
Output: [3]

*/

class Solution {
public:
    void reverse(int start,int end,vector<int>& arr){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[j];
        arr[j]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(n^2), SC-O(n)
    void _3_SumBrute(vector<int> arr){
        // generate all triplets
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==0){
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        sort(temp.begin(),temp.end());
                        ans.push_back(temp);
                    }
                }
            }
        }
        set<vector<int>> st;
        for(auto it:ans){
            st.emplace(it);
        }
        for(auto it:st){
            for(auto iter:it){
                cout<<iter<<" ";
            }
            cout<<endl;
        }
    }
    
    // Brute force Solution:TC-O(n^2 x log size of elements), SC-O(n * size of element * 2)
    void _3_SumBetter(vector<int> arr){
        // using hashing
        int n=arr.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            set<int> hashset;
            for(int j=i+1;j<n;j++){
                int k=-(arr[i]+arr[j]);
                if(hashset.find(k)!=hashset.end()){
                    vector<int> temp = {arr[i],arr[j],k};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                hashset.insert(arr[j]);
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        for(auto it:res){
            for(auto iter:it) cout<<iter<<" ";
            cout<<endl;
        }
    }
 
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void _3_SumOptimal(vector<int> arr){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else {
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
            }
        }
        for(auto it:res){
            for(auto iter:it) cout<<iter<<" ";
            cout<<endl;
        }
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

    cout<<"Brute: "<<endl;
    s._3_SumBrute(arr);

    cout<<"Better: "<<endl;
    s._3_SumBetter(arr);

    cout<<"Optimal: "<<endl;
    s._3_SumOptimal(arr);
    

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