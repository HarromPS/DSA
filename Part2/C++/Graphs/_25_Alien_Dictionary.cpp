#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, 
thus you may return any valid order and output will be 1 if the order of string returned by 
the function is correct else 0 denoting incorrect string returned.

So, we know in english dictionary 
we have alphabets a,b,c,d ... x,y,z

for strings abca, abcd, baa, cab, cad   
a before b before c before d

so we have given a dictionary and we have to find out an alien dictionary (just order) of
first k english alphabets 

baa
abcd
abca
cab
cad

baa, abcd => b comes before a 
abcd, abca => d comes before a
abca, cab => a comes before c
cab, cad => b comes before d

so a directed graph (DG) is generated 
b a
b d
d a
a c

# represent a b c ... as 1 2 3 ...
# find a DG
# find a topo sort for order
*/



class Solution
{
public:
    void dfs(int node,vector<int> adj_list[],vector<int>& ans,int n,vector<int>& visited){
        visited[node]=1;

        // ask neighbours
        for(auto neigh: adj_list[node]){
            if(!visited[neigh]){
                dfs(neigh,adj_list,ans,n,visited);
            }
        }
        ans.push_back(node);
    }

};

void solve()
{
    // grid
    int k;  // alphabets
    int n;  // array size
    cin >> k >> n;

    vector<string> dict;
    for(int i=0;i<n;i++){
        string inp;
        cin>>inp;
        dict.push_back(inp);
    }

    // generate a dg
    // Adjancency List for directed graph
    vector<int> adj_list[k];    
    for(int i=1;i<n;i++){
        string s1=dict[i-1];
        string s2=dict[i];

        int j=0,k=0;
        int len1=s1.size();
        int len2=s2.size();
        while(j<len1 && k<len2 && s1[j]==s2[k]){
            j++;
            k++;
        }
        if(j!=len1 && k!=len2){
            int u=s1[j]-97;
            int v=s2[k]-97;

            // only from u to v
            adj_list[u].push_back(v);
        }
    }
    
    Solution s;
    vector<int> visited(k,0);
    vector<int> ans;    // stack
    for(int i=0;i<k;i++){
        if(!visited[i]){
            s.dfs(i,adj_list,ans,k,visited);
        }
    }
    string res="";
    for(int i=ans.size()-1;i>=0;i--){
        res+=(char)(ans[i]+97);
    }
    cout<<res<<endl;
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
