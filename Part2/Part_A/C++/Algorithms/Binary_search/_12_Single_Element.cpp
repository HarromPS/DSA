#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

class Solution {
public:
    // TC:O(N) SC:O(1)
    int singleNonDuplicateMethod1(std::vector<int>& arr) {
        // using simple linear search by counting number of occurances 
        int ans=-1;
        int n=arr.size();
        for(int i=0;i<n-1;i+=2){
            int count=0;
            for(int j=i;j<2;j++){
                if(arr[j]==arr[i]){
                    count+=1;
                }
            }
            if(count!=2){
                ans=arr[i];
                break;
            }
        }
        return ans==-1?arr[n-1]:ans;
        
    }

    // TC:O(N) + O(N) to do deletion, SC:O(N)
    int singleNonDuplicateMethod2(std::vector<int>& arr) {
        // using hashset 
        std::unordered_set<int> st;
        for(auto it:arr){
            if(st.count(it)==1){
                st.erase(it);
            }else{
                st.insert(it);
            }
        }
        return *st.begin();
        
    }

    // TC:O(N) + O(log n) SC:O(N)
    int singleNonDuplicateMethod3(std::vector<int>& arr) {
        // using hashmap
        std::map<int,int> mp;
        for(auto it:arr) mp[it]+=1;
        for(auto it:mp){
            if(it.second==1) {
                return it.first;
            }
        }
        return 1;        
    }

    // TC:O(N) SC:O(1)
    int singleNonDuplicateMethod4(std::vector<int>& arr) {
        // using xor operation 
        int xor_=0;
        for(auto it:arr) xor_^=it;
        return xor_;
    }

    // TC:O(log n) SC:O(1)
    int singleNonDuplicateMethod5(std::vector<int>& arr) {
        // using binary search
        // eliminate left or right part 
        
        // even odd index -> left part 
        // odd even index -> right part 

        // edge cases 
        int n=arr.size();
        if(n==1) return arr[0];

        // trim down edges to check boundary condition 
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];

        int low=1;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            // check single element
            if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1]){
                return arr[mid];    // always exists
            }

            // even odd left part 
            if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid]==arr[mid+1])){
                // left part, eliminate and go right 
                low=mid+1;
            }else{
                // right part, eliminate and go left 
                high=mid;
            }
        }
        return 1;          // dummy condition
    }
    
};

void solve(){
    int n;  // array size
    std::cin>>n;
    // int target;
    // std::cin>>target;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.singleNonDuplicateMethod1(arr);
    // std::cout<<res<<std::endl;
    res=s.singleNonDuplicateMethod2(arr);
    // std::cout<<res<<std::endl;
    res=s.singleNonDuplicateMethod3(arr);
    // std::cout<<res<<std::endl;
    res=s.singleNonDuplicateMethod4(arr);
    // std::cout<<res<<std::endl;
    res=s.singleNonDuplicateMethod5(arr);
    std::cout<<res<<std::endl;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    std::cin>>t;
    while(t--) solve();
    // solve();
    return 0;
}