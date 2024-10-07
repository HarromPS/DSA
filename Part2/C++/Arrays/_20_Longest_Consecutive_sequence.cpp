#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

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
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(nlog n + n), SC-O(n)
    void longestConsecutiveSequenceBrute(vector<int> arr){
        // finding all consecutive sequence 
        int len=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int x=arr[i];
            int cnt=1;
            for(int j=0;j<n;j++){
                if(arr[j]==x+1){
                    x=x+1;
                    cnt+=1;
                    j=-1;
                    len=max(len,cnt);
                }
            }
        }
        cout<<len<<endl;
    }

    void longestConsecutiveSequenceBetter(vector<int> arr){
        // sort the given array
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        // traverse and find longest consecutive sequence
        int len=1;
        int lastSmaller=arr[0];
        int consecutive_count=1;     // at least one element is in consectutive manner 
        for(int i=1;i<n;i++){
            // if consecutive 
            if(arr[i]==lastSmaller+1){
                lastSmaller=arr[i];
                consecutive_count++;
                len=max(len,consecutive_count);
            }
            else if(arr[i]==lastSmaller){
                continue;
            }
            else{
                consecutive_count=1;
                lastSmaller=arr[i];
            }
        }
        cout<<len<<endl;
    }

    // Optimal Solution:TC-O(n), SC-O(n)
    void longestConsecutiveSequenceOptimal(vector<int> arr){
       // get a set 
       unordered_set<int> st;
       int n=arr.size();
       for(auto it:arr) st.emplace(it);

        // search for the starting point of a consecutive sequence 
        int len=1;
        for(auto it:st){
            int x = it-1;
            if(st.find(x)==st.end()){   // if no one before, means it is a starting one
                int cnt=1;
                x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                len=max(len,cnt);
            }
        }
        cout<<len<<endl;
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
    s.longestConsecutiveSequenceBrute(arr);
    
    cout<<"Better: "<<endl;
    s.longestConsecutiveSequenceBetter(arr);
    
    cout<<"Optimal: "<<endl;
    s.longestConsecutiveSequenceOptimal(arr);

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


