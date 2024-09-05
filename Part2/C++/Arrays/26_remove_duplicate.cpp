#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
- Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
- The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
- The remaining elements of nums are not important as well as the size of nums.
- Return k.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.


*/

void removeDuplicatesBruteForce(vector<int> &nums)
{
    /*
        Using a set 
        T.C: O(N*log(N) + N)    // nlogn for set operation + iterating array of size n
        S.C: O(N)      if all elements are unique
    */

    set<int> uniqueElements;
    int totalElements = nums.size();
    int duplicateElements = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        uniqueElements.emplace(nums[i]);
    }

    // now modify the elements
    int i=0;
    for (auto it:uniqueElements)
    {
        nums[i]=it;
        cout<<nums[i]<<" ";
        i++;
    }
    cout<<endl;
    // cout<<endl<<uniqueElements.size()<<endl; // only unique elements
}

void removeDuplicatesOptimalSolution(vector<int> & nums){
    /*
        Using a Two Pointer approach 
        T.C: O(N)       iterating array
        S.C: O(1)      if all elements are unique
    */

    int i=0;
    // for(int j=1;j<nums.size();j++){
    //     if(nums[i]!=nums[j]) {
    //         nums[i+1]=nums[j];
    //         i++;
    //     }
    // }

    int j=1;
    while(j<nums.size()){
        while(nums[i]==nums[j] && j<nums.size()){   // skip duplicates
            j++;
        }
        if(j<nums.size()){
            nums[i+1]=nums[j];
            i++;
            j++;
        }
    }

    // number of unique elements -> i+1
    for(int j=0;j<(i+1);j++){
        cout<<nums[j]<<" ";
    }
    cout<<endl;

    
}
void solve()
{
    vector<int> nums ;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int res;
        cin>>res;
        nums.push_back(res);
    }
    vector<int> temp(nums);
    removeDuplicatesBruteForce(nums);
    removeDuplicatesOptimalSolution(temp);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    // solve();
    return 0;
}
