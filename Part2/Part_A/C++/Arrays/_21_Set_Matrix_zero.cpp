#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

input:      output: 
1 1 1       1 0 1 
1 0 1       0 0 0
1 1 1       1 0 1

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
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    // Brute force Solution:TC-O(n*m(n+m)), SC-O(n*m)
    void setMatrixZeroBrute(vector<vector<int>> arr){
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) temp[i][j]=arr[i][j];
        }

        // traverse and convert the rows and columns
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==0){
                    // convert rows 
                    for(int k=0;k<m;k++) arr[i][k]=0;

                    // convert column 
                    for(int k=0;k<n;k++) arr[k][j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(auto it:arr[i]) cout<<it<<" ";
            cout<<endl;
        }
    }
    
    // mark all the elements around 0 to be -1 
    // TC:O(N^3) SC:O(N*M)
    void setMatrixZeroBruteBetter(vector<vector<int>> arr){
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    // convert row to -1 for all 1s
                    for(int k=0;k<m;k++) {
                        if(arr[i][k]==1) arr[i][k]=-1;
                    }
                    // convert col to -1 for all 1s
                    for(int k=0;k<n;k++) {
                        if(arr[k][j]==1) arr[k][j]=-1;
                    }
                }
            }
        }
        // iterate once again to convert all -1 to 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==-1){
                    arr[i][j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    // TC:O(N*M) SC:O(N+M)
    void setMatrixZeroBetter(vector<vector<int>> arr){
        // using extra space 
        int n=arr.size();
        int m=arr[0].size();
        vector<int> row(n,0), col(m,0);
        // mark row x col for any row or column is 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        // convert if row[..] =1 | col[..] = 1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 || col[j]==1){
                    arr[i][j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // Optimal Solution:TC-O(n*m), SC-O(n*m)
    void setMatrixZeroOptimal(vector<vector<int>> arr){
        int n=arr.size();
        int m=arr[0].size();
        int col0=arr[0][0];

        // vector<int> row(n,0);   -> matrix[..][0]
        // vector<int> col(m,0);   -> matrix[0][..]
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    // mark ith row
                    arr[i][0]=0;

                    // mark jth col
                    if(j!=0){    // j has 1 cell for 1st col
                        arr[0][j]=0;
                    }else{
                        col0=0;
                    }
                }
            }
        }
        // solve all except forst row and column
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[0][j]==0 || arr[i][0]==0){
                    arr[i][j]=0;
                }
            }
        }

        // solve row first 
        for(int j=m-1;j>=0;j--){
            if(arr[0][j]==0 || arr[0][0]==0){
                arr[0][j]=0;
            }
        }

        // solve col
        if(col0==0){
            for(int i=0;i<n;i++){
                arr[i][0]=0;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

void solve(){
    int n,m;  // array size
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }   

    Solution s;
    cout<<"Brute: "<<endl;
    s.setMatrixZeroBrute(arr);

    cout<<"Brute Better: "<<endl;
    s.setMatrixZeroBruteBetter(arr);
    
    cout<<"Better: "<<endl;
    s.setMatrixZeroBetter(arr);
    
    cout<<"Optimal: "<<endl;
    s.setMatrixZeroOptimal(arr);

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


