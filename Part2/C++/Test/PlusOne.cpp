#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void helper(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    vector<int> ans;
    if (n == 1)
    {
        if (arr[0] + 1 >= 10)
        {
            ans.push_back((arr[0] + 1) % 10);
            ans.push_back(1);
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    int carry = 0;
    if (arr[n - 1] + 1 >= 10)
    {
        ans.push_back((arr[n - 1] + 1) % 10);
        carry = 1;
    }
    else
    {
        ans.push_back(arr[n - 1] + 1);
        carry = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] + carry >= 10)
        {
            ans.push_back((arr[i] + 1) % 10);
            carry = 1;
        }
        else
        {
            carry = 0;
            ans.push_back(arr[i]);
        }
    }
    if (carry == 1)
    {
        ans.push_back(1);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    helper(arr, n);
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
    //     solve();
    // }
    solve();
    return 0;
}
