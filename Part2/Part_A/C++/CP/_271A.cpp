#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isBeautifulYear(int n){
    set<int> s;
    while(n>0){
        int rem = n%10;
        if(s.count(rem)!=0){
            return false;
        }
        s.emplace(rem);
        n/=10;
    }
    return true;
}
void solve()
{
    // trying every possible combination
    int y;
    cin>>y;
    int i=1;
    while(true){
        bool res = isBeautifulYear(y+i);
        if(res){
            cout<<y+i<<endl;
            break;
        }
        i++;
    }
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
