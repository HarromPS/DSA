#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].
*/

class Solution {
public:
    void Swap(vector<int>& a,vector<int>& b,int i,int j){
        int temp=a[i];
        a[i]=b[j];
        b[j]=temp;
    }

    void reverse(int start,int end,vector<int>& a){
        while(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
            end--;
        }
    }
    // Brute Solution: TC-O(n^2) SC-O(1)
    void missingAndRepeatingBrute_1(vector<int> arr){
        int missing=-1, repeating=-1;
        int n=arr.size();
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]==i) cnt++;
            }
            if(cnt==0) missing=i;
            else if(cnt==2) repeating=i;
        }
        cout<<missing<<" "<<repeating<<endl;
    }
    // Brute Solution: TC-O(n log n + 2n) SC-O(1)
    void missingAndRepeatingBrute_2(vector<int> arr){
        // for repeating 
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int repeating=-1;
        for(int i=1;i<n;i++){
            if(arr[i] ^ arr[i-1] == 0) {
                repeating=arr[i];
                break;
            }
        }
        // for missing 
        int missing=-1;
        int sa=0;   // sum of array elements 
        int ss=0;   // sum of sequence elements 
        for(int i=0;i<n;i++){
            sa+=arr[i];
            ss+=(i+1);
        }
        missing = ss - (sa - repeating);
        cout<<missing<<" "<<repeating<<endl;
    }

    // Better Solution: TC-O(n) SC-O(n)
    void missingAndRepeatingBetter(vector<int> arr){
        // using hashing 
        int n=arr.size();
        vector<int> mp(n+1,0);
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        int missing=-1, repeating=-1;
        // range is [1,n]
        for(int i=1;i<n+1;i++){
            if(mp[i]==0) missing = i;
            else if(mp[i]==2) repeating = i;
        }
        cout<<missing<<" "<<repeating<<endl;
    }

    // Optimal Solution: TC-O(min(n,m)  + n log n + m log m) SC-O(1)
    void missingAndRepeatingArraysOptimal_1(vector<int> arr){
        int n=arr.size();
        int x=-1;   // repeating 
        int y=-1;   // missing

        long long int sa=0;   // sum of array elements 
        long long int ss=0;   // sum of sequence elements 

        long long int ssa=0;  // sum of square of array elements 
        long long int sss=0;  // sum of square of array elements 

        for(int i=0;i<n;i++){
            sa+=arr[i];
            ss+=(i+1);

            // avoiding overflow 
            ssa+=static_cast<long long int>(arr[i]*arr[i]);
            sss+=static_cast<long long int>((i+1)*(i+1));
        }

        // we know sa-ss === x-y
        long long int x_minus_y = sa-ss;              // we have 2 equations
        long long int x_plus_y = (ssa-sss)/x_minus_y;

        x = (x_minus_y + x_plus_y)/2;
        y = x_plus_y - x;
        cout<<y<<" "<<x<<endl;
        // return {static_cast<int>(x),static_cast<int>(y)};

    }

    // Optimal Solution: TC-O(n x log n), SC-O(n)  
    void missingAndRepeatingArraysOptimal_2(vector<int> arr){
        // a<<b means integer a is left shift by b i.e 2^b
        // 1<<0 => 1
        // 1<<1 => 2
        // 1<<2 => 4
        // 2<<0 => 2
        // 2<<1 => 4
        // 2<<2 => 8

        int xr=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            xr^=arr[i];
            xr^=(i+1);
        }

        // get the differentiating bit
        int bitNo=0;
        while(1){
            // find 1st 1 bit if xor & that bit is 1 i.e number is same
            if((xr & (1<<bitNo))!= 0) {
                break;
            }
            bitNo+=1;
        }

        // create 2 groups and seperate all elements into 0s and 1s categories 
        int zeros=0;
        int ones=0;
        for(int i=0;i<n;i++){
            // part of 0 club
            if(((1<<bitNo) & arr[i]) == 0) zeros^=arr[i];

            // part of one club
            else ones^=arr[i];

            // part of zero club
            if(((1<<bitNo) & (i+1)) == 0) zeros^=(i+1);
            
            // part of one club
            else ones^=(i+1);
        }

        // just check which is repeating 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(zeros==arr[i]) cnt++;
        }

        int missing;
        int repeating;
        if(cnt==2){
            repeating = zeros;
            missing = ones;
        }
        else {
            repeating = ones;
            missing = zeros;
        }
        cout<<missing<<" "<<repeating<<endl;
    }
};

void solve(){
    int n;  // array size
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        arr.push_back(ip);
    }   

    Solution s;
    cout<<"Brute 1: "<<endl;
    s.missingAndRepeatingBrute_1(arr);
    cout<<"Brute 2: "<<endl;
    s.missingAndRepeatingBrute_2(arr);
    cout<<"Better: "<<endl;
    s.missingAndRepeatingBetter(arr);
    cout<<"Optimal 1: "<<endl;
    s.missingAndRepeatingArraysOptimal_1(arr);    
    cout<<"Optimal 2: "<<endl;
    s.missingAndRepeatingArraysOptimal_2(arr);    
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


