#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
GCD
*/

class Solution{
public:
    // Brute: TC:O(sqrt(N) x 2 x sqrt(N)) SC:O(N)
    int gcdBrute_1(int a,int b){
        int ans=1;   // if two always have 1 in common
        // from first 
        for(int i=1;i<=min(a,b);i++){
            if(a%i==0 && b%i==0){
                ans=i;
            }
        }
        return ans;
    }

    int gcdBrute_2(int a,int b){
        int ans=1;   // if two always have 1 in common
        // from last
        for(int i=min(a,b);i>=1;i--){
            if(a%i==0 && b%i==0) ans=i;
        }
        return ans;
    }

    // Optimal TC:O(min(a,b)) SC:O(1)
    int gcdOptimal(int a,int b){
        // gcd (a,b) = gcd(a-b,b) a>b
        int ans=1;
        while(a>0 && b>0){
            if(a>b){
                a-=b;
            }else{
                b-=a;
            }
            if(a<=0){
                ans=b;
                break;
            }
            else if(b<=0){
                ans=a;
                break;
            }
        }
        return ans;
    }

    // remainder 
    // TC: O(log(min(a,b))) SC:O(1)
    int gcdOptimal_2(int a,int b){
        // gcd (a,b) = gcd(a-b,b) a>b
        int ans=1;
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }else{
                b=b%a;
            }
        }
        if(a<=0){
            ans=b;
        }
        else{
            ans=a;
        }
        return ans;
    }

    // recursion 
    // TC: O(log(min(a,b))) SC:O(log(min(a,b)))
    int gcdOptimal_3(int a,int b){
        if(a<=0) return b;
        else if(b<=0) return a;

        if(a>b) return gcd(a%b,b);
        return gcd(b%a,a);
    }

};

void solve()
{
    int a,b;
    cin>>a>>b;
    Solution s;
    int res = s.gcdBrute_1(a,b);
    cout<<"Brute 1: "<<res<<endl;
    // res = s.gcdBrute_2(a,b);
    cout<<"Brute 2: "<<res<<endl;
    res = s.gcdOptimal(a,b);
    cout<<"Optimal 2: "<<res<<endl;
    res = s.gcdOptimal_2(a,b);
    cout<<"Optimal 3: "<<res<<endl;
    res = s.gcdOptimal_3(a,b);
    cout<<"Optimal 4: "<<res<<endl;

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
