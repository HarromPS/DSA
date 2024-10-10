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
    void _4_SumBrute(vector<int> arr){
        // generate all triplets
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        if(arr[i]+arr[j]+arr[k]+arr[l]==0){
                            vector<int> temp;
                            temp.push_back(arr[i]);
                            temp.push_back(arr[j]);
                            temp.push_back(arr[k]);
                            temp.push_back(arr[l]);
                            sort(temp.begin(),temp.end());
                            ans.push_back(temp);
                        }
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
    void _4_SumBetter(vector<int> arr){
        // using hashing
        int n=arr.size();
        set<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                set<int> hashset;
                for(int k=j+1;k<n;k++){   
                    int l=-(arr[i]+arr[j]+arr[k]);
                    if(hashset.find(l)!=hashset.end()){
                        vector<int> temp = {arr[i],arr[j],arr[k],l};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                    hashset.insert(arr[k]);
                }
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        for(auto it:res){
            for(auto iter:it) cout<<iter<<" ";
            cout<<endl;
        }
    }
 
    // Optimal TC:O(Nlogn +) SC:O(N*M) + O(1)
    void _4_SumOptimal(vector<int> arr){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int sum=arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum<0) k++;
                    else if(sum>0) l--;
                    else {
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        res.push_back(temp);
                        k++;
                        l--;
                        while(k<l && arr[k]==arr[k-1]) k++;
                        while(k<l && arr[l]==arr[l+1]) l--;
                    }
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
    s._4_SumBrute(arr);

    cout<<"Better: "<<endl;
    s._4_SumBetter(arr);

    cout<<"Optimal: "<<endl;
    s._4_SumOptimal(arr);
    

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