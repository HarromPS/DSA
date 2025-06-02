#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

class Solution{
public: 
    // TC:O((m+n)log (m+n)) SC:O(m+n)
    double findMedianSortedArraysBrute(std::vector<int>& arr1, std::vector<int>& arr2) {
        // merge both array
        int m=arr1.size();
        int n=arr2.size();
        std::vector<int> arr3;
        for(int i=0;i<m;i++) arr3.push_back(arr1[i]);
        for(int i=0;i<n;i++) arr3.push_back(arr2[i]);

        // sort 
        std::sort(arr3.begin(),arr3.end());

        if((m+n)%2==1) return (double)arr3[(m+n)/2];
        return (double)(arr3[(m+n)/2] + arr3[((m+n)/2)-1])/2.0;
    }

    // TC:O(m+n) SC:O(1)
    double findMedianSortedArraysBetter(std::vector<int>& arr1, std::vector<int>& arr2) {
        // merge both array
        int m=arr1.size();
        int n=arr2.size();

        // edge cases
        if(m==0 && n==0) return 0;
        if(m==0) {
            if(n%2==0){
                // even
                return (double)((arr2[n/2]+arr2[(n/2)-1])/2.0);
            }
            // odd
            return (double)(arr2[n/2]);
        }
        else if(n==0) {
            if(m%2==0){     
                // even
                return (double)((arr1[m/2]+arr1[(m/2)-1])/2.0);
            }
            // odd
            return (double)(arr1[m/2]);
        }

        int cnt=0;
        int ele1=-1;
        int ele2=-1;

        int i=0,j=0;
        int N=(m+n);
        int ind1=(N/2)-1;
        int ind2=(N/2);
        while(i<m && j<n){
            if(arr1[i]<arr2[j]){
                if(cnt == ind1) ele1=arr1[i]; 
                if(cnt == ind2) ele2=arr1[i];

                i++;
            }else{
                if(cnt == ind2) ele2=arr2[j];
                if(cnt == ind1) ele1=arr2[j]; 

                j++;
            }
            cnt+=1;
        }   
        while(i<m){
            if(cnt == ind1) ele1=arr1[i]; 
            if(cnt == ind2) ele2=arr1[i];

            i++;
            cnt++;
        }
        while(j<n){
            if(cnt == ind1) ele1=arr2[j]; 
            if(cnt == ind2) ele2=arr2[j];

            j++;
            cnt++;
        }

        if(N%2==1){
            return (double)ele2;
        }
        return (double)((ele1+ele2)/2.0);
    }

    double findMedianSortedArraysOptimal(std::vector<int>& arr1, std::vector<int>& arr2){
        int n1=arr1.size();
        int n2=arr2.size();
        // smaller arr1 thats why
        if(n1>n2) return findMedianSortedArraysOptimal(arr2,arr1);

        int n=n1+n2;
        int left = (n1+n2+1)/2;
        int low=0;
        int high=n1;
        while(low<=high){
            int mid1 = low+(high-low)/2;
            int mid2 = left - mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;

            // cases 
            if(mid1 < n1) r1=arr1[mid1];
            if(mid2 < n2) r2=arr2[mid2];
            if(mid1-1 >=0) l1=arr1[mid1-1];
            if(mid2-1 >=0) l2=arr2[mid2-1];

            // check valid symmetry
            if(l1<=r2 && l2<=r1){
                if(n%2==1) return std::max(l1,l2);
                else{
                    return (double)((std::max(l1,l2)+std::min(r1,r2))/2.0);
                }
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
    std::cin>>m;
    std::cin>>n;

    std::vector<int> arr1(m,0);
    for(int i=0;i<m;i++){
        std::cin>>arr1[i];
    }   
    std::vector<int> arr2(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr2[i];
    }   

    Solution s;
    double res=s.findMedianSortedArraysBrute(arr1,arr2);
    std::cout<<res<<std::endl;
    res=s.findMedianSortedArraysBetter(arr1,arr2);
    std::cout<<res<<std::endl;
    res=s.findMedianSortedArraysOptimal(arr1,arr2);
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