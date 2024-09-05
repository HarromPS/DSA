#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{   
    string str;
    cin>>str;
    vector<int> ans;
    vector<int> stack;
    
    int maxBracket=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            maxBracket++;
            stack.push_back(maxBracket);
            ans.push_back(maxBracket);
        }else if(str[i]==')' && stack.size()!=0){
            ans.push_back(stack.back());
            stack.pop_back();
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
