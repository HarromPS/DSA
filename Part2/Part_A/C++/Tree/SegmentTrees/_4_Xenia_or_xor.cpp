#include <bits/stdc++.h>
using namespace std;
#define ll int
#define mod 1000000007

/*
Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. 
To better understand how they work, Xenia decided to calculate some value v for a.

Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. 
In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. 
At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. 
In the end, she obtains a sequence consisting of one element, and that element is v.

Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.
Input

The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.
Output

Print m integers — the i-th integer denotes value v for sequence a after the i-th query.
*/

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(){}
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
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
    int query(int index,int low,int high,vector<int>& array){
        // base case 
        if(low==high){
            segmentTreeArray[index]=array[low];
            return 1;   // starting with OR operation 
        }

        int mid=low+(high-low)/2;
        int leftNode=query(2*index+1, low,mid,array);
        int rightNode=query(2*index+2, mid+1,high,array);

        // left and right both node will be pointing to same value because 2^n elements
        if(leftNode==1){
            segmentTreeArray[index] = segmentTreeArray[2*index+1] | segmentTreeArray[2*index+2];
            return 2;   // now previous layer will do xor operation
        }
       
        segmentTreeArray[index] = segmentTreeArray[2*index+1] ^ segmentTreeArray[2*index+2];
        return 1;   // do or operation

    }

    void build(int index,int low,int high,vector<int>& array,int flag){
        // base case 
        if(low==high){
            segmentTreeArray[index]=array[low];
            return;   // starting with OR operation 
        }

        int mid=low+(high-low)/2;
        build(2*index+1, low, mid, array, !flag);
        build(2*index+2, mid+1, high, array, !flag);

        // or is 1
        if(flag==1) {
            segmentTreeArray[index] = segmentTreeArray[2*index+1] | segmentTreeArray[2*index+2];
        }
        else{
            segmentTreeArray[index] = segmentTreeArray[2*index+1] ^ segmentTreeArray[2*index+2];
        }
    }

    
    int orXorBuild(vector<int>& array){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        int flag=1;

        // needed size, as array sieze will always be even because of 2^n elements
        if(this->size%2==0){
            // even start with xor
            flag=0;
        }
        
        build(index,low,high,array,flag);  // start with xor first 

        // or
        // query(index,low,high,array);
        return segmentTreeArray[0];
    }

    void queryUpdate(int index,int low,int high,int i,int value,int flag){
        // base case 
        if(i>high || i<low) {
            return;
        }

        if(low==high){
            segmentTreeArray[index]=value;
            return;   // starting with OR operation 
        }

        int mid=low+(high-low)/2;
        if(i<=mid) queryUpdate(2*index+1, low,mid,i,value,!flag);
        else queryUpdate(2*index+2, mid+1,high,i,value,!flag);

        // or is 1
        if(flag==1) {
            segmentTreeArray[index] = segmentTreeArray[2*index+1] | segmentTreeArray[2*index+2];
        }
        else{
            segmentTreeArray[index] = segmentTreeArray[2*index+1] ^ segmentTreeArray[2*index+2];
        }
    }

    int orXorPointUpdate(int i,int value,int flag){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        queryUpdate(index,low,high,i,value,flag);
        return segmentTreeArray[0];
    } 
};

void solve_2(){
    int n,q;
    cin>>n>>q;
    int ele=pow(2,n);
    vector<int> arr;
    for(int i=0;i<ele;i++){
        int ip;
        cin>>ip;
        arr.push_back(ip);
    }

    SegmentTrees s(ele,n);
    s.orXorBuild(arr);

    while(q--){
        int i,val;
        cin>>i>>val;
        i--;    // o based indexing
        int res;
        if(n%2==0) res=s.orXorPointUpdate(i,val,0);
        else res=s.orXorPointUpdate(i,val,1);
        cout<<res<<endl;
    }
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

