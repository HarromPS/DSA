#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Account Merge

Minimum Spanning Tree | Min cost to all nodes with n nodes and n-1 edges

Given a list of accounts of size n where each element accounts [ i ] is a list of strings,
where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Geek wants you to merge these accounts. 
Two accounts belong to the same person if there is some common email to both accounts. 
Note that even if two accounts have the same name, 
they may belong to different people as people could have the same name. 
A person can have any number of accounts initially, 
but all of their accounts have the same name.
After merging the accounts, return the accounts in the following format: 
The first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.

*/

class DisjointSet
{
    // create a rank, parent size array for Union by rank
    // create a size, parent size array for Union by size
    vector<int> rank, parent, size;
public:
    // Constructor function to get initial configurations
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    // function to find the ultimate parent recursively along with path compression 
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        // return by finding its ultimate parent while backtracking
        return parent[node] = findParent(parent[node]);
    }

    // get the union by rank 
    void UnionByRank(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(rank[pu] < rank[pv]){
            parent[pu] = parent[pv];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
        }else{
            parent[pv] = parent[pu];
            // update the rank 
            rank[pu]++;
        }
    }

    // union by size -> keeps the track of the size of the component
    void UnionBySize(int u,int v){
        // get the ultimate parents of u and v nodes
        int pu = findParent(u);
        int pv = findParent(v);

        // if they have same parnent, just return 
        if(pu == pv) return;

        // else if check the rank 
        if(size[pu] < size[pv]){
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }else{
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
    }

    vector<vector<string>> accountsMerge(int n, vector<vector<string>>& accounts) {
        // map every mail with its owner as index
        unordered_map<string,int> mailNode;
        
        // traverse all the nodes 
        for(int i=0;i<n;i++){
            // start from index 1-> starting index of mails 
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailNode.find(mail)==mailNode.end()){
                    // if not present in list then add 
                    mailNode[mail]=i;
                }else{
                    // merge the component 
                    UnionByRank(i, mailNode[mail]);
                }
            }
        }
        vector<vector<string>> ans;

        // merge mails 
        vector<string> mergeMail[n];
        for(auto it: mailNode){
            string mail = it.first;
            int node = findParent(it.second);   // get the ultimate parent 
            mergeMail[node].push_back(mail);
        }

        // sort the mails and add it to the answers
        for(int i=0;i<n;i++){
            // if blank mails for any account
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            // push name and mail to answer
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto mail: mergeMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);            
        }
    
        return ans;
    }

};

void solve(){
    int n;  // number of accounts 
    cin>>n;

    DisjointSet s(n);
    vector<vector<string>> accounts;
    for(int i=0;i<n;i++){
        vector<string> temp;    
        int accountSize;
        cin>>accountSize;
        for(int j=0;j<accountSize;j++){
            string str;
            cin>>str;
            temp.push_back(str);
        }
        accounts.push_back(temp);
    }

    // for(int i=0;i<accounts.size();i++){
    //     for(int j=0;j<accounts[i].size();j++){
    //         cout<<accounts[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    vector<vector<string>> res = s.accountsMerge(n,accounts);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
   
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


