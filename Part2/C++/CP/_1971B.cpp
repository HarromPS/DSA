#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1]){
            char ch=s[i];
            s[i]=s[i+1];
            s[i+1]=ch;
            flag=1;
        }
    }
    if(flag==1){
        cout<<"YES"<<endl<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
