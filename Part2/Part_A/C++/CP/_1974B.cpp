#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{   
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char> st;
    for(int i=0;i<s.size();i++){
        st.insert(s[i]);
    }
    vector<int> v;
    for(auto it:st){
        v.push_back((int)it);
    }
    sort(v.begin(),v.end(),greater<int>());
    st.clear();

    // map the chars with its end characters
    unordered_map<char,char> mp;
    for(int i=0;i<v.size()/2;i++){
        int ch = v[i];
        v[i] = v[v.size()-i-1];
        v[v.size()-i-1] = ch;
    }
    for(int i=0;i<v.size();i++){
        mp[(char(v[i]))] = (char)v[v.size()-i-1];
    }
    v.clear();
    for(int i=0;i<s.size();i++){
        s[i] = mp[s[i]];
    }
    cout<<s<<endl;
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
