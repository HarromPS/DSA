#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500

*/

class Solution {
public: 
    // TLE
    int getShippedWeightAtLoad(std::vector<int>& weights, int load, int days){
        // finds outs how much packages we can ship with load = load in d days
        int loadInShip=0;
        int n=weights.size();
        int i=0;            // ith item
        for(int d=1;d<=days;d++){
            int loaded=0;       // on dth day loaded weight
            while(i<n){
                if(loaded+weights[i] <= load){      // bhare ja ra to hi bharo
                    loaded+=weights[i];     // load to ship
                    i++;                    // move to next item 
                }else{
                    // cant ship this item today 
                    break;
                }
            }
            // total loaded today is 
            loadInShip+=loaded;
        }
        return loadInShip;
    }

    // TC:O(sum(arr) * days * N) SC:O(1)
    int shipWithinDaysBrute(std::vector<int>& weights, int days) {
        // we have to tell at least this weight of products that we can load to the ship
        // such that all products gets shipped within d days

        // int load=1; // min weight possible
        int ans=INT_MAX;    // least weight is asked 
        int totalLoad=std::accumulate(weights.begin(),weights.end(),0); // initialized to 0 
        for(int load=1;load<=totalLoad;load++){
            int shippedLoad=getShippedWeightAtLoad(weights,load,days);
            if(shippedLoad == totalLoad){
                // loaded all packages with d days 
                ans=std::min(ans,load);
                break;
            }
        }
        return ans;
    }

    // TC:O(log (sum(arr)) * days * N) SC:O(1)
    int shipWithinDays(std::vector<int>& weights, int days) {
        // we have to tell at least this weight of products that we can load to the ship
        // such that all products gets shipped within d days

        int ans=INT_MAX;    // least weight is asked 
        int low=1;          // min weight possible
        int high=std::accumulate(weights.begin(),weights.end(),0); // initialized to 0 
        int totalLoad = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int shippedLoad=getShippedWeightAtLoad(weights,mid,days);
            if(shippedLoad == totalLoad){
                // loaded all packages with d days 
                ans=std::min(ans,mid);
                high=mid-1;          // if we can load less weight weight, minimize 
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

void solve(){
    int n;  
    int days;
    std::cin>>n;
    std::cin>>days;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.shipWithinDaysBrute(arr,days);
    std::cout<<res<<std::endl;
    res=s.shipWithinDays(arr,days);
    std::cout<<res<<std::endl<<"\n";
}

void solve2(){
    int n;  
    int days;
    std::cin>>n;
    std::cin>>days;

    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   
    
    int total=std::accumulate(arr.begin(),arr.end(),0);
    std::cout<<total<<"\n";
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