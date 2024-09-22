#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution {
public:
   
    // Dutch National Flag Algorithm
    void Sort012Optimal(vector<int> arr){
        // Dutch National Flag Algorithm
        int n = arr.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(mid,high,arr);
                mid++;
                low++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(mid,high,arr);
                high--;
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }

    void swap(int i,int j,vector<int>& arr){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    Solution s;
    cout<<"Optimal: "<<endl;
    s.Sort012Optimal(arr);
    
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


