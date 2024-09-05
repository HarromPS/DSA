#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    int i = 0, j = i + 1;
    while (j < s.size())
    {
        cout<<(s[i] % 2 == 0)<<" "<<(s[j] % 2 == 0)<<endl;
        if (s[i] % 2 == 1 && s[j] % 2 == 1)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            j += 2;
            i += 2;
        }
        else
        {
            j++;
            i++;
        }
    }
    cout<<s<<endl;
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
    // cin>>test;
    // while(test--)
    // {
    solve();
    // }
    return 0;
}
