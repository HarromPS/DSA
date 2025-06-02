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
    int kthElementArraysBrute(std::vector<int>& arr1, std::vector<int>& arr2,int k) {
        // merge both array
        int m=arr1.size();
        int n=arr2.size();
        std::vector<int> arr3;
        for(int i=0;i<m;i++) arr3.push_back(arr1[i]);
        for(int i=0;i<n;i++) arr3.push_back(arr2[i]);

        // sort 
        std::sort(arr3.begin(),arr3.end());

        // return k-1 indexed element 
        return arr3[k-1];
    }

    // TC:O(m+n) SC:O(1)
    int kthElementArraysBetter(std::vector<int>& arr1, std::vector<int>& arr2,int k) {
        // merge both array
        int m=arr1.size();
        int n=arr2.size();

        // edge cases
        if(m==0 && n==0) return 0;
        if(m==0) {
            return arr2[k-1];
        }
        if(n==0) {
            return arr1[k-1];
        }

        int cnt=0;
        int ele=-1;

        int i=0,j=0;
        int ind=k-1;
        while(i<m && j<n){
            if(arr1[i]<arr2[j]){
                if(cnt == ind) ele=arr1[i]; 
                i++;
            }else{
                if(cnt == ind) ele=arr2[j];
                j++;
            }
            cnt+=1;
        }   
        while(i<m){
            if(cnt == ind) ele=arr1[i]; 
            i++;
            cnt++;
        }
        while(j<n){
            if(cnt == ind) ele=arr2[j];
            j++;
            cnt++;
        }

        return ele;
    }

    // TC:O(k) SC:O(1)
    int kthElementArraysOptimal_Linear(std::vector<int>& arr1, std::vector<int>& arr2,int k){
        int n1=arr1.size();
        int n2=arr2.size();
        // smaller arr1 thats why
        if(n1>n2) return kthElementArraysOptimal_Linear(arr2,arr1,k);

        int left = std::min(k,n1);   // only k elements on left so l2 will hold the answer
        for(int ele=std::max(0,k-n2);ele<=left;ele++){
            int ind1 = ele;
            int ind2 = k-ele;
            int l1=std::numeric_limits<int>::min();
            int l2=std::numeric_limits<int>::min();
            int r1=std::numeric_limits<int>::max();
            int r2=std::numeric_limits<int>::max();

            // cases 
            if(ind1 < n1) r1=arr1[ind1];
            if(ind2 < n2) r2=arr2[ind2];
            if(ind1-1 >=0) l1=arr1[ind1-1];
            if(ind2-1 >=0) l2=arr2[ind2-1];

            // check valid merge
            if(l1<=r2 && l2<=r1){
                return std::max(l1,l2);
            }
        }
        return 0;
    }

    // TC:O(log k) SC:O(1)
    int kthElementArraysOptimal_BS(std::vector<int>& arr1, std::vector<int>& arr2,int k){
        int n1=arr1.size();
        int n2=arr2.size();
        // smaller arr1 thats why
        if(n1>n2) return kthElementArraysOptimal_BS(arr2,arr1,k);

        int low=std::max(0,k-n2);
        int high=std::min(k,n1);    // only k elements on left so l2 will hold the answer
        while(low<=high){
            int mid1 = low+(high-low)/2;
            int mid2 = k - mid1;
            int l1=std::numeric_limits<int>::min();
            int l2=std::numeric_limits<int>::min();
            int r1=std::numeric_limits<int>::max();
            int r2=std::numeric_limits<int>::max();

            // cases 
            if(mid1 < n1) r1=arr1[mid1];
            if(mid2 < n2) r2=arr2[mid2];
            if(mid1-1 >=0) l1=arr1[mid1-1];
            if(mid2-1 >=0) l2=arr2[mid2-1];

            // check valid merge
            if(l1<=r2 && l2<=r1){
                return std::max(l1,l2);

            }

            // go right 
            if(l2>r1){
                low=mid1+1;
            }else{
                high=mid1-1;
            }
        }
        return 0;
    }

};

void solve(){
    int m;
    int n;  
    int k;  
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
    double res=s.kthElementArraysBrute(arr1,arr2,k);
    std::cout<<res<<std::endl;
    res=s.kthElementArraysBetter(arr1,arr2,k);
    std::cout<<res<<std::endl;
    res=s.kthElementArraysOptimal_Linear(arr1,arr2,k);
    std::cout<<res<<std::endl;
    res=s.kthElementArraysOptimal_Linear(arr1,arr2,k);
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