#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int upper=0,i=0;
    while(s[i]!='\0'){
        if((int)s[i]>=65 && (int)s[i]<=90){
            upper+=1;
        }
        i++;
    }
    if(upper > s.size()-upper){
        // replace all lower with upper
        for(int i=0;i<s.size();i++){
            if((int)s[i]>=97 && (int)s[i]<=122){
                s[i] = (char)((int)s[i] - 32);
            }   
        }
        cout<<s<<endl;
        return;
    }else if(upper <= s.size()-upper){
        // replace all upper with lower
        for(int i=0;i<s.size();i++){
            if((int)s[i]>=65 && (int)s[i]<=90){
                s[i] = (char)((int)s[i] + 32);
            }   
        }
        cout<<s<<endl;
        return;
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
