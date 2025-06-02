#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Consecutive Sum Problem:
Some of prime nos can be expressed as sum of other consecutive prime nos
for e.g
5=2+3
17=2+3+5+7
41=2+3+5+7+11+13

find how many such prime nos. are there which satisfy this condition,
also sum should start with 2 in range 3 to N

e.g
ip: 20 op:2 i.e 5,17
ip: 43 op:4 i.e 5,17,41,43

*/

bool isPrime(int n){
    if(n==0 || n==1) return false;
    if(n==2 || n==3 ) return true;
    if(n%2==0 || n%3==0) return false;

    for(int i=5;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

bool findAns(int n,vector<int>& primeNos){
    int sum=0;
    for(int i=0;i<=primeNos.size();i++){
        sum+=primeNos[i];
        if(sum==n && isPrime(sum)) {
            return true;
        }
        if(sum>n) {
            break;
        }
    }
    return false;
}

int isConsecutivePrime(int num){
    // collect all prime numbers from 3 to n
    vector<int> primeNos;
    for(int i=2;i<=num;i++){
        if(isPrime(i)){
            primeNos.push_back(i);
        }
    }

    // iterate on all and see if it satisfies the condition
    int count=0;
    for(int i=3;i<=num;i++){
        if(findAns(i,primeNos)){
            count+=1;
        }
    }
    return count;
}


void solve()
{
    int n;
    cin>>n;
    int res=isConsecutivePrime(n);
    cout<<res<<endl;

}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
