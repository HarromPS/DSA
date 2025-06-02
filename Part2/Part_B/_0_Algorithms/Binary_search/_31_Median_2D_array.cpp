    #include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>
#include<algorithm>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS
Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

Examples:

Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

Input: mat = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median

Input: mat = [[3], [5], [8]]
Output: 5
Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median.
*/

class Solution{
public: 
    // TC:O(m*n + m Log n) SC:O(1)
    int medianBrute(std::vector<std::vector<int>> &arr) {
        int n1=arr.size();
        int n2=arr[0].size();
        
        std::vector<int> arr2;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                arr2.push_back(arr[i][j]);
            }
        }
        
        std::sort(arr2.begin(),arr2.end());
        int n=n1*n2;
        if(n%2 ==0){
            return (arr2[n/2]+arr2[n/2-1])/2;
        }
        return arr2[n/2];
    }

    bool checkIsMedian(std::vector<std::vector<int>>& arr,int median,int least){
        int n1=arr.size();
        int n2=arr[0].size();
        int cnt=0;              // no of elements <= median value
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(arr[i][j]<=median) cnt+=1;
            }
        }
        if(cnt>=least){
            return true;
        }
        return false;
    }
    
    // TC:O(n1 + log(max - min) * (n1*n2)) SC:O(1)
    int median(std::vector<std::vector<int>> &arr) {
        int n1=arr.size();
        int n2=arr[0].size();
        
        int n=n1*n2;
        int least=(n/2)+1;
        int low=std::numeric_limits<int>::max(),high=std::numeric_limits<int>::min();
        for(int i=0;i<n1;i++){
            low=std::min(low,arr[i][0]);
            high=std::max(high,arr[i][n2-1]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkIsMedian(arr,mid,least)){
                ans=mid;
                high=mid-1; // minimize
            }else{
                low=mid+1;
            }
        }
        return low;
    }


    bool checkIsMedian2(std::vector<std::vector<int>>& arr,int median,int least){
        int n1=arr.size();
        int n2=arr[0].size();
        int cnt=0;              // no of elements <= median value
        for(int i=0;i<n1;i++){
            // returns a iterator points to first element greater than median
            auto upIndex = upper_bound(arr[i].begin(),arr[i].end(),median);
            int ele = (upIndex-arr[i].begin()); // get index 
            cnt+=(ele);
        }
        if(cnt>=least){
            return true;
        }
        return false;
    }

    int median2(std::vector<std::vector<int>> &arr) {
        int n1=arr.size();
        int n2=arr[0].size();
        
        int n=n1*n2;
        int least=(n/2)+1;
        int low=std::numeric_limits<int>::max();
        int high=std::numeric_limits<int>::min();

        for(int i=0;i<n1;i++){
            low=std::min(low,arr[i][0]);
            high=std::max(high,arr[i][n2-1]);
        }

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkIsMedian2(arr,mid,least)){
                ans=mid;
                high=mid-1; // minimize
            }else{
                low=mid+1;
            }
        }
        return low;
    }
   
};

void solve(){
    int m;
    int n;  
    std::cin>>m;
    std::cin>>n;

    std::vector<std::vector<int>> arr;
    for(int i=0;i<m;i++){
        std::vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            std::cin>>temp[i];
        }
        arr.push_back(temp);
    }   

    Solution s;
    // int res=s.medianBrute(arr);
    // std::cout<<res<<std::endl;
    // res=s.median(arr);
    // std::cout<<res<<std::endl;
    int res=s.median2(arr);
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
    // while(t--) solve2();
    return 0;
}