#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
BINARY SEARCH ALGORITHM TECHNIQUE FOR SEARCHING IN SORTED OBJECTS

We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. 
Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. 
Find the answer exactly to 2 decimal places.

Example 1:

Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

Example 2:

Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.

Note: stations is in a strictly increasing order.
*/

class Solution{
public: 
    void helper(std::vector<int> &stations,std::vector<int> &placedStations){
        int n=stations.size();
        long double maxDist=0;
        int index=0;

        // iterate through all stations and find max dist to be minimized 
        for(int i=1;i<n;i++){
            int stationPlaced=placedStations[i-1];
            long double sectors=(long double)stationPlaced+1;
            long double dist=(long double)(stations[i]-stations[i-1])/sectors;
            if(maxDist < dist){
                maxDist=dist;
                index=i;
            }
        }

        // place station at max dist 
        if(index>0)
            placedStations[index-1]+=1;
    }

    // Brute Force TC:O(k*N) SC:O(1)
    long double findSmallestMaxDistBrute(std::vector<int> &stations, int k) {
        int n=stations.size();
        std::vector<int> placedStations(n-1,0); // stations placed between gaps

        // place stations one by one 
        for(int statn=1;statn<=k;statn++){
            // place kth station
            helper(stations,placedStations);
        }

        // after last station placed find max dist which is min
        long double ans=0;
        for(int i=1;i<n;i++){
            int stationPlaced=placedStations[i-1];
            long double sectors=(long double)stationPlaced+1;
            long double dist=(long double)(stations[i]-stations[i-1])/sectors;
            ans=std::max(ans,dist);
        }
        return ans;
    }

    void helper2(std::vector<int> &stations,std::vector<int> &placedStations, std::priority_queue<std::pair<long double,int>>& pq){
        // get the top max distance at index 
        // long double dist = pq.top().first;
        int index=pq.top().second;
        pq.pop();

        // place a station at index 
        placedStations[index-1]+=1;
        long long dist = (long double)(stations[index]-stations[index-1]);
        long double sectors=(long double)(placedStations[index-1]+ 1 );
        long double newDistance = dist/sectors;

        // insert new distance
        pq.push({newDistance,index});
    }   

    // Better using PQ
    long double findSmallestMaxDistBetter(std::vector<int> &stations, int k) {
        // using priority queue to track max dist 
        int n=stations.size();
        std::vector<int> placedStations(n-1,0);
        std::priority_queue<std::pair<long double,int>> pq;

        // initially fill pq with dist and index 
        for(int i=1;i<n;i++){
            long double dist=(long double)(stations[i]-stations[i-1]);
            pq.push({dist,i});
        }

        // insert stations one by one 
        for(int statn=1;statn<=k;statn++){
            // place kth station
            helper2(stations,placedStations,pq);
        }

        // return top max dist 
        return pq.top().first;

        // return std::round(pq.top().first * 100.0) / 100.0; round off to 2 decimal places
    }

    int numberOfGasStations(std::vector<int>& stations,long double dist){
        int n=stations.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            int stationsInBetween=(stations[i]-stations[i-1])/dist;
            // exact division remove 1 from it as a sector addition
            if(stationsInBetween * dist == (stations[i]-stations[i-1])/dist){
                stationsInBetween--;
            }
            cnt+=stationsInBetween;
        }
        return cnt;
    }

    // Binary Search TC:O(log(maxDist) * N) + O(N) SC:O(1)
    long double findSmallestMaxDist(std::vector<int> &stations, int k) {
        int n=stations.size();
        long double low=0;
        long double high=0;
        for(int i=1;i<n;i++){
            high=std::max(high, (long double)(stations[i]-stations[i-1]));
        }

        long double diff=1e-6;
        while(high-low>diff){
            long double mid=low+(high-low)/2.0;
            int cnt=numberOfGasStations(stations,mid);
            if(cnt>k){
                // increase dist 
                low=mid;
            }else{
                high=mid;
            }
        }
        return high;
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
    long double res=s.findSmallestMaxDistBrute(arr,k);
    std::cout << std::fixed << std::setprecision(6) << res << std::endl;
    // res=s.findSmallestMaxDistBetter(arr,k);
    // std::cout << std::fixed << std::setprecision(6) << res << std::endl<<"\n";
    res=s.findSmallestMaxDist(arr,k);
    std::cout << std::fixed << std::setprecision(6) << res << std::endl<<"\n";

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