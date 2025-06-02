#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. 
(For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+ 7 (1+1+2+3) 
and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

*/

class Solution {
public: 
    // TLE
    // TC: more than O(N) SC:O(1)
    bool checkMinDayPossibility(std::vector<int>& bloomDay, int m, int k,int day){
        int i=0;
        int n=bloomDay.size();
        int bouquetCount=0; // we have make 0 bouquet till now
        while(i<n){
            // check by picking k adjacent flowers to make 1 bouquet
            int flag=0;
            int flowers=0;
            for(int j=i;j<n && j<(i+k);j++){
                // if flower is not bloomed
                if(bloomDay[j] > day){
                    flag=1;
                    break;
                }else{
                    flowers+=1;
                }
            }
            if(flag==0 && flowers==k){
                bouquetCount+=1;    // made a bouquet 
                i=i+k;              // next bouquet
            }else{
                // not able to make 1 bouquet as using k flowers
                i=i+1;  // check next k adj flowers
            }
        }
        if(bouquetCount >= m){
            // made m bouquets 
            return true;
        }
        return false;       // cant make m bouquets on this day 
    }

    // TC:O(N)
    bool checkMinDayPossibility2(std::vector<int>& bloomDay, int m, int k,int day){
        int flower=0;
        int bouquetCount=0; 
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                flower+=1;
            }else{
                flower=0;
            }
            if(flower==k){
                bouquetCount+=1;
                flower=0;
            }
        }
        if(bouquetCount >= m){
            return true;
        }
        return false;
    }

    // TC:O(log (max(arr))*n) SC:O(1)
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        // base case
        int n=bloomDay.size();

        // Overflow
        // if(n < (m*k)){
        //     // no of flowers are less than required 
        //     return -1;
        // }

        int ans=INT_MAX;
        int low=1;  // min 1 day to bloom any flower 
        int high=*max_element(bloomDay.begin(),bloomDay.end()); // max day in bloom array 
        while(low<=high){
            int mid=low+(high-low)/2;
            
            // check if this is min day
            int result=checkMinDayPossibility(bloomDay,m,k,mid);
            if(result!=false){
                // there is a possibility this could be a day to make m bouquets
                ans=std::min(ans,mid);
                high=mid-1;     // look for more min days
            }else{
                low=mid+1;      // wait some more days for flowers to bloom
            }
        }
        if(ans!=INT_MAX){
            return ans;
        } 
        return -1;      // cannot make m bouquets using k flowers on any day
    }
};

void solve(){
    int n;  
    int m;
    int k;
    std::cin>>n;
    std::cin>>m;
    std::cin>>k;
    std::vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }   

    Solution s;
    int res=s.minDays(arr,m,k);
    std::cout<<res<<std::endl<<"\n";
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