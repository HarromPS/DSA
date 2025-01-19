#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Aggressive Cows

You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
*/

class Solution {
public: 
    bool canPossible(std::vector<int> &stalls, int cows,int dist){
        int n=stalls.size();
        int cowsPlaced=1;   // 1st cow placed
        int lastCowPlaced=0;    // last cow placed at index 0
        int i=1;    // place next cow
        while(i<n){
            // if min dist >= required dist then we can place cow at this stall
            if(stalls[i]-stalls[lastCowPlaced] >= dist){
                cowsPlaced+=1;  // cow placed
                lastCowPlaced=i;    // at this stall
            }
            i+=1;   // place next cow
        }
        if(cowsPlaced>=cows){
            // able to place reqired no of cows placed,this must be possible min distance
            return true;
        }
        return false;
    }
    // TC:O(n log n + n * max(arr)) SC:O(1)
    // Brute Force
    int aggressiveCowsBrute(std::vector<int> &stalls, int k) {
        // Pattern: max of min or min of max
        // min dist betwen two cows is consecutive distance
        // ans is max among all those min distances

        // sort stalls forst 
        std::sort(stalls.begin(),stalls.end());

        int ans=1;  // min dist possible 
        int n=stalls.size();
        int maxDist=*max_element(stalls.begin(),stalls.end());

        // start from min dist 1 to max dist 
        for(int dist=1;dist<=maxDist;dist++){
            bool res=canPossible(stalls,k,dist);
            if(res==true) continue;
            else{
                ans=dist-1; // previous dist
                break;
            }
        }
        return ans;
    }

    // TC:O(n log n + n * log(max(arr))) SC:O(1)
    int aggressiveCows(std::vector<int> &stalls, int k) {
        // Pattern: max of min or min of max
        // min dist betwen two cows is consecutive distance
        // ans is max among all those min distances

        // sort stalls forst 
        std::sort(stalls.begin(),stalls.end());

        // using binary search as 1 2 3 4 5 ....
        //                        Y Y Y N N .... 

        int ans=1;  // min dist possible 
        int n=stalls.size();
        int low=1;
        int high=*max_element(stalls.begin(),stalls.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            bool res=canPossible(stalls,k,mid);
            if(res==true){
                ans=mid;   
                low=mid+1;  // look for max distance
            }else{
                high=mid-1; // look for some smller distance
            }
        }
        return high;    // opposite polarity of possible solution
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
    int res=s.aggressiveCowsBrute(arr,k);
    std::cout<<res<<std::endl;
    res=s.aggressiveCows(arr,k);
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