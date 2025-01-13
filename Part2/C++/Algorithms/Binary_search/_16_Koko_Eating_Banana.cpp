#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/

class Solution {
public:
    int requiredTimeBrute(std::vector<int>& piles,int k){
        int n=piles.size();
        int reqTime=0;
        for(int i=0;i<n;i++){
            int ceilVal=std::ceil((double)piles[i]/(double)k);
            reqTime+=ceilVal;
        }
        return reqTime;
    }

    // TC:O(max) * O(N) SC:O(1)
    int minEatingSpeedBrute(std::vector<int>& piles,int h){
        // max bananas koko can eat is max(piles)
        int k=1;    // go from 1 banana per hr
        int max=*max_element(piles.begin(),piles.end());
        for(int i=1;i<=max;i++){
            int reqTime=requiredTimeBrute(piles,k);
            if(reqTime<=h){
                return k;
            }
            k+=1;
        }
        return 0;
    }
    int requiredTime(std::vector<int>& piles,int k){
        int n=piles.size();
        int reqTime=0;
        for(int i=0;i<n;i++){
            // TLE
            /*
            int tempPile=piles[i];
            while(tempPile>0){
                if(tempPile<=k){
                    reqTime+=1;
                    break;
                }else{
                    tempPile-=k;
                }
                reqTime+=1;
            }
            */
            // ceil value
            // int ceilVal=((double)piles[i]+k-1)/(double)k;
            // reqTime+=ceilVal;

            // int ceilVal=std::ceil((double)piles[i]/(double)k);
            // reqTime+=ceilVal;
        }
        return reqTime;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        // base case k>=n is fixed
        int n=piles.size();
        int ans=0;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            // std::cout<<mid<<std::endl;

            // calculate total time to finish all bananas in all piles in mid(k/hrs)
            int reqTime=requiredTime(piles,mid);
            
            // check if possible to finish all piles in h hrs if mid is k bananas/hrs
            if(reqTime <= h){
                ans=mid;
                high=mid-1; // find minimum k such that koko can eat all bananas
            }
            else if(reqTime>h){
                low=mid+1;  // increase number of bananas eating
            }
        }
        return ans;
    }
};

void solve(){
    int n;  
    int k;
    std::cin>>n;
    std::cin>>k;
    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.minEatingSpeedBrute(arr,k);
    // std::cout<<res<<std::endl;
    int res_2=s.minEatingSpeed(arr,k);
    std::cout<<res_2<<std::endl<<"\n";
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
    // solve();
    return 0;
}