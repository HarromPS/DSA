#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given a 0-indexed integer array nums of even length consisting of an 
equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy 
all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] 
are incorrect because they do not satisfy one or more conditions.  


*/

class Solution {
public:
    // Brute force: 
    // generate all premutations 

    void generatePermutations(vector<int> arr, vector<int>& ds,vector<int> mp,int n){
        if(ds.size() == n){
            for(int i=0;i<ds.size();i++) cout<<ds[i]<<" ";
            cout<<endl;
            return;
        }

        // pick element which is not picked 
        for(int i=0;i<mp.size();i++){
            if(mp[i]==-1){
                ds.push_back(arr[i]);
                mp[i]=1;    // set 

                // function call 
                generatePermutations(arr,ds,mp,n);

                ds.pop_back();
                mp[i]=-1;   // unset
            }
        }
    }

    void swap(int i,int j,vector<int>& arr){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    void generatePermutationsSwap(int index,vector<int>& arr){
        if(index>=arr.size()){
            for(auto it: arr) cout<<it<<" ";
            cout<<endl;
        }

        for(int i=index;i<arr.size();i++){
            swap(i,index,arr);
            generatePermutationsSwap(index+1,arr);
            swap(i,index,arr);
        }
    }

    void RearrangeElements(vector<int>& a){
        int n =a.size();
        vector<int> arr;
        for(auto it: a) arr.push_back(it);
        sort(arr.begin(),arr.end());
        vector<int> mp(n,-1);
        vector<int> ds;
        generatePermutations(arr,ds,mp,n);
        // generatePermutationsSwap(0,a);   // not in sorted order 
    }

    // Optimal Solution:TC-O(n), SC-O(1)
    void RearrangeElementsOptimal(vector<int>& arr){
        
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
    s.RearrangeElements(arr);
    cout<<"Optimal: "<<endl;
    s.RearrangeElementsOptimal(arr);

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


