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

K-th element of two Arrays

Given two sorted arrays a[] and b[] and an element k, 
the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: 
Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.

*/

class Solution{
public: 
    // TC:O((m+n) . log (m+n)) SC:O(m+n)
    long long kthSmallestProductBrute(std::vector<int>& arr1, std::vector<int>& arr2,long long k) {
        // get all combinations
        int n1=arr1.size();
        int n2=arr2.size();
        std::vector<long long> product;
        for(int i=0;i<n1;i++) {
            for(int j=0;j<n2;j++) {
                product.push_back(arr1[i]*arr2[j]);
            }
        }

        // return k-1 indexed element 
        return product[k-1];
    }

};

void solve(){
    int m;
    int n;  
    long long k;  
    std::cin>>m;
    std::cin>>n;
    std::cin>>k;

    std::vector<int> arr1(m,0);
    for(int i=0;i<m;i++){
        std::cin>>arr1[i];
    }   
    std::vector<int> arr2(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr2[i];
    }   

    Solution s;
    long long res=s.kthSmallestProductBrute(arr1,arr2,k);
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