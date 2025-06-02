#include <bits/stdc++.h>
using namespace std;

// Top down approach
// int subArrayPrefix(int* arr,int size,vector<int> & res,int k){
//     // base condition
//     if(k>=size){
//         return 1;
//     }
//     else{
//         for(int i=k;i<size;i++){
//             if(arr[i])            
//         }
//     }
// }

// Bottom Up approach

int Solution(int*arr, int k,int size){
    int dp[size+1][size+1];
    for(int i=0;i<=size;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<=size;i++){
        dp[0][i]=1;
    }

    for(int i=1;i<size+1;i++){
        int x=k;
        for(int j=1;j<size+1;j++){
            // if same sign
            if((arr[k]<=0 && arr[x]<=0) || (arr[k]>=0 && arr[x]>=0)){
                dp[i][j]=dp[i-1][j];
            }
            // if different sign
            else if((arr[k]<0 && arr[x]>0) || (arr[k]>0 && arr[x]<0)){
                dp[i][j]=dp[i-1][j]+1;
            }
            x++;
        }
        k++;
    }

    for(int i=1;i<size+1;i++){
        for(int j=0;j<size+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[size][size]+1;
}
vector<int> subArrayPrefix(int* arr,int size,vector<int> & res){
    for(int i=0;i<size;i++){
        res[i] = Solution(arr,i,size-i);
    }

    return res;
}
int main() {
	// your code goes here
    cout<<"Enter\n";
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    vector<int> res(n,0);
        res = subArrayPrefix(arr,n,res);
	    for(int i=0;i<res.size();i++){
	        cout<<res[i]<<" ";
	    }
	    cout<<endl;
	    
	}

}
