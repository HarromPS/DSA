#include <bits/stdc++.h>
using namespace std;
#define ll int
#define mod 1000000007

/*
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').

The first line contains t, the number of testcases followed by a blank space. 
Each of the t tests start with a number n (n ≤ 200000). 
Then n + 1 lines follow. 
In the ith line a number A[i - 1] is given (A[i - 1] ≤ 107). 
The (n + 1)th line is a blank space.

Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5

*/

struct Node{
    int open;
    int close;
    int full;
    Node(){}
    Node(int _open,int _close,int _full){
        open=_open;
        close=_close;
        full=_full;
    }
}typedef Node;

// Gives range query in O(log n) time complexity & uses recursion
class SegmentTrees{
public:
    vector<int> segmentTreeArray;
    int range=0;
    int size=0;
    SegmentTrees(){}

    SegmentTrees(int n,int _size){
        // initialize segment tree array 
        range=n-1;
        size=_size;
        segmentTreeArray.resize(4*n,0);
    }

    // TC: O(log n) 
    int query(int index,int low,int high,int l,int r){
        // no overlap [low high] [l r] or [l r] [low high]
        if(high<l || r<low){
            return 0;   // 0 full
        }

        // complete overlap [l low high r]
        if(l<=low && high<=r){
            return segmentTreeArray[index];
        }

        // partial overlap
        int mid=low+(high-low)/2;
        int leftFull=query(2*index+1, low,mid, l, r);
        int rightFull=query(2*index+2, mid+1,high, l, r);

        return leftFull+rightFull;   // do or operation
    }   

    int sgQuery(int l,int r){
        int index=0;
        int low=0;
        int high=range;
        int res = query(index,low,high,l,r);
        return res;
    }

    void build(int index,int low,int high,vector<int>& array){
        // base case 
        if(low==high){
            segmentTreeArray[index] = array[low];
            return;   
        }

        int mid=low+(high-low)/2;
        build(2*index+1, low, mid, array);
        build(2*index+2, mid+1, high, array);
        segmentTreeArray[index] = segmentTreeArray[index*2+1] + segmentTreeArray[index*2+2];

    }

    void sgBuild(vector<int>& array){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        build(index,low,high,array);
    }

    void update(int index,int low,int high, int i,int val){
        if(low==high){
            segmentTreeArray[index] += val;
            return;
        }

        int mid=low+(high-low)/2;
        if(i<=mid) update(2*index+1, low, mid, i,val);
        else update(2*index+2, mid+1, high, i,val);
        segmentTreeArray[index] = segmentTreeArray[index*2+1] + segmentTreeArray[index*2+2];
    }

    void sgUpdate(int i,int val){
        int index=0;
        int low=0;
        int high=range;
        update(index,low,high,i,val);
    }
    // print segment tree 
    void sgPrint(){
        for(auto it: segmentTreeArray){
            cout<<it<<" ";;
        }
        cout<<endl;
    }
};

void solve_2(){
    int n;
    cin>>n;
    vector<int> array;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        array.push_back(ip);
        maxi=max(maxi,ip);
    }  
    
    
    vector<int> freq(maxi+1,0);
    for(int i=0;i<n;i++){
        freq[array[i]]++;
    }

    SegmentTrees s(maxi+1,maxi);
    s.sgBuild(freq);
    // s.sgPrint();

    int count=0;
    for(int i=0;i<n;i++){
        freq[array[i]]--;
        s.sgUpdate(array[i],-1);
        count+=s.sgQuery(1,array[i]-1);
    }
    cout<<count<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    solve_2();
    return 0;
}

