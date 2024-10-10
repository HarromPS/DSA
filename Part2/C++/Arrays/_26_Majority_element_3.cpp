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
    void majorityElementBrute(vector<int> arr){
        // count for each element
        set<int> st;
        int n=arr.size();
        int limit=n/3;
        for(int i=0;i<n;i++){
            int count=1;    // for each element 
            for(int j=0;j<n;j++){
                if(i!=j && arr[i]==arr[j]){
                    count++;
                }
            }
            if(count>limit){
                st.emplace(arr[i]);
                if(st.size()==2) break;  // as we can have max 2 elements only
            }
        }
        for(auto it:st) cout<<it<<" ";
        cout<<endl;
    }
    
    // Brute force Solution:TC-O(n), SC-O(n)
    void majorityElementBetter(vector<int> arr){
        // using hashing 
        int n=arr.size();
        map<int,int> mp;
        for(auto it:arr) mp[it]+=1;

        vector<int> ans;
        int limit=n/3;
        for(auto it:mp){
            if(it.second>limit){
                ans.push_back(it.first);
                if(ans.size()==2) break;  // as we can have max 2 elements only
            }
        }
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
 
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void majorityElementOptimal(vector<int> arr){
        // Morres voting algorithm
        int n=arr.size();
        int cnt1=0,ele1=-1e9;
        int cnt2=0,ele2=-1e9;
        for(int i=0;i<n;i++){
            if(cnt1==0 && arr[i]!=ele2){
                cnt1=1;
                ele1=arr[i];
            }
            else if(cnt2==0 && arr[i]!=ele1){
                cnt2=1;
                ele2=arr[i];
            }
            else if(ele1==arr[i]) cnt1++;
            else if(ele2==arr[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        // manual check 
        cnt1=0;
        cnt2=0;
        int limit=(n/3);
        cout<<limit<<endl;
        for(int i=0;i<n;i++){
            if(ele1==arr[i]) cnt1++;
            if(ele2==arr[i]) cnt2++;
        }
        if(cnt1>limit) cout<<ele1<<"\n";
        if(cnt2>limit) cout<<ele2<<"\n";
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
    s.majorityElementBrute(arr);

    cout<<"Better: "<<endl;
    s.majorityElementBetter(arr);

    cout<<"Optimal: "<<endl;
    s.majorityElementOptimal(arr);
    

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