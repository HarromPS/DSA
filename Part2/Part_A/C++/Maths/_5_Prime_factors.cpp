#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Check if a number is prime 
*/

// Brute force:
// T.C: O(10^d x d)
class Solution{
public:
    int isPrime(int n){
        if(n==1) return 0;
        if(n==2 || n==3 || n==5) return 1;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
        return 1;
    }

    // Brute: TC:O(sqrt(N) x 2 x sqrt(N)) SC:O(N)
    // Does not works for all numbers e.g 2
    vector<int> primeFactorsBrute(int n){
        vector<int> ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0 && isPrime(i)){
                ans.push_back(i);
                if(n/i!=i && isPrime(n/i)){
                    ans.push_back(n/i);
                }
            }
        }
        return ans;
    }

    // Brute: TC:O(sqrt(N) x 2 x sqrt(N)) SC:O(N)
    vector<int> primeFactorsOptimal(int n){
        vector<int> ans;

        // dividing the number and reducing it 
        /*
            n=780;
            780%2 == 0 => 390
            390%2 == 0 => 195
            195%3 == 0 => 65
            65%5 == 0 => 13
            13%13 == 0 => 1

        */
        for(int i=2;i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0) {
                    n=n/i;
                }
            }
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin>>n;
    Solution s;
    int res = s.isPrime(n);
    
    vector<int> ans = s.primeFactorsBrute(n);
    // for(auto it: ans) cout<<it<<" ";
    // cout<<endl;

    ans.clear();
    ans = s.primeFactorsOptimal(n);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

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
    // cin >> test;
    // while (test--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
