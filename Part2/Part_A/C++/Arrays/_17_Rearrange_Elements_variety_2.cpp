#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
You are given a 0-indexed integer array nums of even length consisting of an 
equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy 
all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] 
are incorrect because they do not satisfy one or more conditions.  


*/

class Solution {
public:
    // Brute Solution: TC-O(n), SC-O(n)
    void RearrangeElements(vector<int> a){
        // seperate positives and negatives 
        int n=a.size();
        vector<int> pos, negs;
        for(int i=0;i<n;i++){
            if(a[i]>0) pos.push_back(a[i]);
            else negs.push_back(a[i]);
        }
        // fill it out back and with this order is also preserved 
        int i=0,j=0,k=0;
        int x = pos.size();
        int y = negs.size();
        if(x!=y){
            if(x>y){
                y-=1;
            }else{
                x-=1;
            }
        }
        while(i<=x && j<=y && k<n){
            a[k]=pos[i];
            k++;
            i++;
            a[k]=negs[j];
            k++;
            j++;
        }

        while(i<pos.size()){
            a[k]=pos[i];
            k++;
            i++;
        }
        while(j<negs.size()){
            a[k]=negs[j];
            k++;
            j++;
        }

        for(auto it:a) cout<<it<<" ";
        cout<<endl;

    }

    // Optimal Solution:TC-O(n), SC-O(1)
    void RearrangeElementsOptimal(vector<int>& arr){
        
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
    cout<<"Brute: "<<endl;
    s.RearrangeElements(arr);
    cout<<"Optimal: "<<endl;
    s.RearrangeElementsOptimal(arr);

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


