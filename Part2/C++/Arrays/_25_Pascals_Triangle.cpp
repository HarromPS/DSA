#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

class Solution {
public:
    void reverse(int start,int end,vector<int>& arr){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    void Swap(int i,int j,vector<int>& arr){
        int temp=arr[j];
        arr[j]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(n^2), SC-O(1)
    void pascalsTriangleBrute(int n){
        vector<vector<int>> ans;
        if(n==1){
            cout<<1<<endl;
            return;
        }else if(n==2){
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
        }

        // if n>=2
        ans.push_back({1});
        ans.push_back({1,1});

        int j=1;    // 1st index 
        while(j<n-1){
            vector<int> temp;
            int m=ans[j].size();

            temp.push_back(1);
            for(int i=1;i<m;i++){
                int x=ans[j][i]+ans[j][i-1];
                temp.push_back(x);
            }
            temp.push_back(1);
            ans.push_back(temp);
            temp.clear();
            j++;
        }
        for(int i=0;i<ans.size();i++){
            for(auto it:ans[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    
    // Type 1: Print the element on rth row and cth column
    // TC:O(R)
    long long pascalElementFunction(int n,int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    long long pascalElement(int row,int col){
        long long res = pascalElementFunction(row-1,col-1);
        return res;
    }

    // Type 2: Print nth row 
    // TC:O(N*R)
    void printNthRow(int n){
        for(int i=0;i<n;i++){
            long long res = pascalElementFunction(n-1,i);
            cout<<res<<" ";
        }
        cout<<endl;
    }

    // TC:O(N)
    void printNthRowOptimal(int n){
        long long ans=1;
        cout<<ans<<" ";
        for(int i=1;i<n;i++){
            ans=(ans*(n-i))/i;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    // Optimal TC:O(N*M) SC:O(N*M) + O(1)
    void pascalsTriangleOptimal(int n){
        for(int i=1;i<=n;i++){
            printNthRowOptimal(i);
        }
    }

};

void solve(){
    int n;  // array size
    cin>>n;
    Solution s;

    cout<<"Brute: "<<endl;
    s.pascalsTriangleBrute(n);

    cout<<"element: ";
    long long res=s.pascalElement(5,3);
    cout<<res<<endl;

    s.printNthRow(6);
    s.printNthRowOptimal(6);

    cout<<"Optimal: "<<endl;
    s.pascalsTriangleOptimal(n);
    

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


