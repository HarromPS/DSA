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
    int res=s.medianBrute(arr);
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