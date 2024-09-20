#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an array arr, return the second largest distinct element from an array. 
If the second largest element doesn't exist then return -1.

Examples:

Input: arr = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest 
element is 34.

*/

class Solution {
public:
    // Brute Solution: TC-O(N logN), SC-O(1)  no extra space is used
    vector<int> second_largest_Brute(vector<int>& arr){
        int n=arr.size();
        // if size is zero return -1
        if(n==0 || n==1) return {-1,-1};

        int largestElement=0;

        // sorting the array
        sort(arr.begin(),arr.end());

        // we know arr[n-1] gives largest array element,but if all elements are same 
        int flargest=arr[n-1];
        int slargest=arr[n-2];

        for(int i=n-2;i>0;i--){
            if(slargest==flargest){
                slargest=arr[i];
                break;
            }
        }

        // return second largest and smallest element
        return {flargest,slargest};
    }

    // Better solution TC-(N + N) SC-O(1)  no extra space is used
    vector<int> second_largest_Better(vector<int>& arr){
        int n=arr.size();
        // if size is zero return -1
        if(n==0 || n==1) return {-1,-1};

        int largestElement=0;

        // get the largest element
        for(int i=0;i<n;i++){
            if(largestElement<arr[i]) largestElement=arr[i];
        }

        // once again iterate the array for second largest
        int secondLargest=0;
        for(int i=0;i<n;i++){
            if(secondLargest<arr[i] && arr[i]!=largestElement){
                secondLargest=arr[i];
            }
        }

        // return second largest and smallest element
        return {largestElement,secondLargest};
    }

    // Optimized solution TC-O(N) SC-O(1)  no extra space is used
    vector<int> second_largest_Optimal(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==0 || n==1) return {-1,-1}; // is answer does not exist

        int firstLargestElement=arr[0];
        int secondLargestElement=0;

        for(int i=1;i<n;i++){
            if(firstLargestElement<arr[i]){
                secondLargestElement=firstLargestElement;
                firstLargestElement=arr[i];
            }else if(arr[i]<firstLargestElement && secondLargestElement<arr[i]){
                secondLargestElement=arr[i];
            }
        }

        int firstSmallestElement=arr[0];
        int secondSmallestElement=INT_MAX;
        for(int i=1;i<n;i++){
            if(firstSmallestElement > arr[i]){
                secondSmallestElement=firstSmallestElement;
                firstSmallestElement=arr[i];
            }
            else if(arr[i]>firstSmallestElement && secondSmallestElement>arr[i]){
                secondSmallestElement=arr[i];
            }
        }
        return {firstLargestElement,secondLargestElement};
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
    vector<int> res=s.second_largest_Brute(arr);
    cout<<"Brute: "<<res[0]<<" "<<res[1]<<endl;

    res.clear();
    res=s.second_largest_Better(arr);
    cout<<"Better: "<<res[0]<<" "<<res[1]<<endl;

    res.clear();
    res=s.second_largest_Optimal(arr);
    cout<<"Optimal: "<<res[0]<<" "<<res[1]<<endl;
    
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


