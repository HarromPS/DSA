#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    // Overflows in INT_MIN ans INT_MAX
    /*
    In context of typical 32-bit signed integer, when its value goes beyond range it overflows 
    then 32-bit system wraps around it, it is due to the way integers are stored in 2'c complement.

    e.g range INT_MIN to INT_MAX: (-2,147, 483, 648) to (2,147, 483, 647) i.e -(2^32) to (2^32)-1

    INT_MIN overflows: -2,147, 483, 648 - 1: 2,147, 483, 647
    INT_MAX overflows: 2,147, 483, 647 + 1: -2,147, 483, 648

    so long is used as it has range (-2^63) to (2^63)-1, to prevent overflow
     */

    int min_value = INT_MIN;
    int max_value = INT_MAX;

    cout<<"INT MIN: "<<min_value<<endl;
    cout<<"INT MIN Overflowed: "<<(min_value-1)<<endl;

    cout<<"INT MAX: "<<max_value<<endl;
    cout<<"INT MAX Overflowed: "<<(max_value+1)<<endl;

    // to prevent, typecast in value in int
    long min_long_value=(long)INT_MIN;
    long max_long_value=(long)INT_MAX;

    cout<<"\nINT MIN: "<<min_value<<endl;
    cout<<"INT MIN in LONG NOT Overflowed: "<<(min_long_value-1)<<endl;

    cout<<"INT MAX: "<<max_value<<endl;
    cout<<"INT MAX in LONG NOT Overflowed: "<<(max_long_value+1)<<endl;
    

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
