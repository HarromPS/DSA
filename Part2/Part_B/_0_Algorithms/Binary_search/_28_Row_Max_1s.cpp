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

Row with max 1s

You are given a 2D binary array arr[][] consisting of only 1s and 0s. 
Each row of the array is sorted in non-decreasing order. 
Your task is to find and return the index of the first row that contains the maximum number of 1s. 
If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.

Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.

*/

class Solution{
public: 
    // TC:O(m*n) SC:O(1)
    int rowWithMax1sBrute(std::vector<std::vector<int>> &arr) {
        int curr=0;
        int row=0;
        int n1=arr.size();
        int n2=arr[0].size();
        for(int i=0;i<n1;i++){
            int currMax=0;
            for(int j=0;j<n2;j++){
                if(arr[i][j]==1) currMax+=1;
            }
            if(currMax>curr){
                row=i;
                curr=currMax;
            }
        }
        return curr==0?-1:row;
    }

    // TC:O(n1.log(n2)) SC:O(1)
    int rowWithMax1s(std::vector<std::vector<int>> &arr) {
        // apply binary search here
        int curr=0; // max 1s
        int row=0;  // max 1s row number
        int n1=arr.size();
        int n2=arr[0].size();
        
        // for each row
        for(int i=0;i<n1;i++){
            // base case
            // 0th index 
            if((n2==1 && arr[i][0]==1) || arr[i][0]==1) {
                // all are 1s
                return i;   // max 1s first row
            }
           
            int currMax=-1;
            int low=1;
            int high=n2-2;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[i][mid]==1){
                    // check if this is first 1
                    if(arr[i][mid-1] == 0 && arr[i][mid+1]==1){
                        currMax=n2-mid;
                    }
                }
                if(arr[i][mid]==0){
                    // go right
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            // more than 1 1s
            if(currMax>curr){
                curr=currMax;
                row=i;
            }
            // last index base case
            if(currMax==-1 && arr[i][n2-1]==1){
                currMax=1;
                if(currMax>curr){
                    curr=currMax;
                    row=i;
                }
            }
            // std::cout<<row<<std::endl;
        }
        return curr==0?-1:row;
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
    int res=s.rowWithMax1sBrute(arr);
    // std::cout<<res<<std::endl;
    res=s.rowWithMax1s(arr);
    // std::cout<<res<<std::endl;
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