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
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

[[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
*/

class Solution{
public: 
    // TC:O(m*n) SC:O(1)
    std::vector<int> findPeakGridBrute(std::vector<std::vector<int>> &arr) {
        // traverse all matrix, find peak element and return its index 
        int n1=arr.size();
        int n2=arr[0].size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                // get adj neighbors
                int up=(i-1 >=0)?arr[i-1][j]:-1;
                int down=(i+1 < n1)?arr[i+1][j]:-1;
                int left=(j-1 >=0)?arr[i][j-1]:-1;
                int right=(j+1 < n2)?arr[i][j+1]:-1;
                // check if this is peak element 
                if(arr[i][j] > up && arr[i][j] > down && arr[i][j] > left && arr[i][j] > right){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    // TC:O(n+m) SC:O(1)
    std::vector<int> findPeakGridBetter(std::vector<std::vector<int>> &arr) {
        // traverse and if neighbor is > element then that neighbor could be peak element 
        int n1=arr.size();
        int n2=arr[0].size();
        int i=0;
        int j=0;
        while(i>=0 && i<n1 && j>=0 && i<n2){
            // get adj neighbors
            int up=(i-1 >=0)?arr[i-1][j]:-1;
            int down=(i+1 < n1)?arr[i+1][j]:-1;
            int left=(j-1 >=0)?arr[i][j-1]:-1;
            int right=(j+1 < n2)?arr[i][j+1]:-1;
            // check if this is peak element 
            if(arr[i][j] > up && arr[i][j] > down && arr[i][j] > left && arr[i][j] > right){
                return {i,j};
            }

            // get the max neighbor
            int maxNeighbour=0,iMax=-1,jMax=-1;
            if(up>maxNeighbour){
                maxNeighbour=up;
                iMax=i-1;
                jMax=j;
            }
            if(down>maxNeighbour){
                maxNeighbour=down;
                iMax=i+1;
                jMax=j;

            }
            if(left>maxNeighbour){
                maxNeighbour=left;
                iMax=i;
                jMax=j-1;

            }
            if(right>maxNeighbour){
                maxNeighbour=right;
                iMax=i;
                jMax=j+1;
            }
            i=iMax;
            j=jMax;
        }
        return {i,j};
    }

    // TC:O(n log m) or O(m log n) SC:O(1)
    std::vector<int> findPeakGridOptimal(std::vector<std::vector<int>> &arr) {
        int n1=arr.size();
        int n2=arr[0].size();

        int low=0;
        int high=n2-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxEle=-1;
            int maxInd=-1;
            for(int i=0;i<n1;i++){
                if(maxEle<arr[i][mid]){
                    maxEle=arr[i][mid];
                    maxInd=i;
                }
            }

            // check if this is a peak element
            int left=mid-1>=0?arr[maxInd][mid-1]:-1;
            int right=mid+1<n2?arr[maxInd][mid+1]:-1;
            if(left < arr[maxInd][mid] && arr[maxInd][mid]>right){
                return {maxInd,mid};
            }

            // eliminate right part 
            if(left > arr[maxInd][mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {0,0};
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
    std::vector<int> res=s.findPeakGridBrute(arr);
    for(auto it:res) std::cout<<it<<" ";
    std::cout<<std::endl;

    res=s.findPeakGridOptimal(arr);
    for(auto it:res) std::cout<<it<<" ";
    std::cout<<std::endl;
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