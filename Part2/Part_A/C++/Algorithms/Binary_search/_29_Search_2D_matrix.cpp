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

Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

class Solution{
public: 
    // TC:O(m*n) SC:O(1)
    bool searchMatrixBrute(std::vector<std::vector<int>> &arr,int target) {
        int n1=arr.size();
        int n2=arr[0].size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(arr[i][j]==target) return true;
            }
        }
        return false;
    }

    // TC:O(m*n) SC:O(1)
    bool searchMatrixBrute2(std::vector<std::vector<int>> &arr,int target) {
        int n1=arr.size();
        int n2=arr[0].size();
        for(int i=0;i<n1;i++){
            // check if exists in this row
            if(arr[i][0] <= target && target <= arr[i][n2-1]){
                for(int j=0;j<n2;j++){
                    if(arr[i][j]==target) return true;
                }
            }else{
                continue;
            }
        }
        return false;
    }

    // code where each row and column is independent but sorted
    // 19 27 35 44 46 51 57 60 66 68 71 74 77 80 83 87 88 95 99 100 105 114 116
    // 23 35 45 54 55 64 65 68 74 76 85 88 93 98 99 109 110 115 121 127 137 142 149
    // TC:O(m*log n) SC:O(1)
    bool searchMatrixBrute3(std::vector<std::vector<int>> &arr,int target) {
        int n1=arr.size();
        int n2=arr[0].size();
        for(int i=0;i<n1;i++){
            // check if exists in this row
            if(arr[i][0] <= target && target <= arr[i][n2-1]){
                int low=0;
                int high=n2-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(arr[i][mid]==target) return true;
                    if(arr[i][mid] < target) low=mid+1;
                    else high=mid-1;
                }
            }else{
                continue;
            }
        }
        return false;
    }

    // code where each row and column is independent but sorted
    // 19 27 35 44 46 51 57 60 66 68 71 74 77 80 83 87 88 95 99 100 105 114 116
    // 23 35 45 54 55 64 65 68 74 76 85 88 93 98 99 109 110 115 121 127 137 142 149
    // TC:O(m*log n) SC:O(1)
    bool searchMatrixOptimal(std::vector<std::vector<int>> &arr,int target) {
        int n1=arr.size();
        int n2=arr[0].size();

        int row=0;
        int col=n2-1;
        while(row<n1 && col>=0){
            if(arr[row][col]==target) return true;
            if(arr[row][col] < target) row+=1;  // go down larger elements
            else col-=1;                        // go left smaller elements
        }
        return false;
    }

    // Code where last of each row is < first of next row
    // TC:O(log(n1).log(n2)) SC:O(1)
    bool searchMatrix(std::vector<std::vector<int>> &arr,int target) {
        // we can have outer and inner trackers using binary search 
        int n1=arr.size();
        int n2=arr[0].size();

        int lowOuter=0,highOuter=n1-1;
        while(lowOuter<=highOuter){
            int outerMidRow = lowOuter+(highOuter-lowOuter)/2;
            // check if target exists in this row 
            if(arr[outerMidRow][0] <= target && target <= arr[outerMidRow][n2-1]){
                // search here
                int lowInner=0, highInner=n2-1;
                while(lowInner<=highInner){
                    int innerMid=lowInner+(highInner-lowInner)/2;
                    // check target 
                    if(arr[outerMidRow][innerMid]==target){
                        return true;    // exists
                    }
                    if(arr[outerMidRow][innerMid]>target){
                        // go left 
                        highInner=innerMid-1;
                    }else{
                        // go right
                        lowInner=innerMid+1;
                    }
                }
            }

            if(target < arr[outerMidRow][0]){
                // go up
                highOuter=outerMidRow-1;
            }else{
                // go down
                lowOuter=outerMidRow+1;
            }
        }
        return false;   // not exists    
    }

    // Code where last of each row is < first of next row
    // TC:O(log(n1).log(n2)) SC:O(1)
    bool searchMatrix2(std::vector<std::vector<int>> &arr,int target) {
        // we can have outer and inner trackers using binary search 
        int n1=arr.size();
        int n2=arr[0].size();

        int low=0;
        int high=(n1*n2)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/n2;
            int col=mid%n2;
            if(arr[row][col]==target) return true;
            if(arr[row][col] < target) low=mid+1;
            else high=mid-1;
        }
        return false;   // not exists    
    }
};

void solve(){
    int m;
    int n;  
    int k;
    std::cin>>m;
    std::cin>>n;
    std::cin>>k;

    std::vector<std::vector<int>> arr;
    for(int i=0;i<m;i++){
        std::vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            std::cin>>temp[i];
        }
        arr.push_back(temp);
    }   

    Solution s;
    bool res=s.searchMatrixOptimal(arr,k);
    std::cout<<res<<std::endl;
    res=s.searchMatrix2(arr,k);
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