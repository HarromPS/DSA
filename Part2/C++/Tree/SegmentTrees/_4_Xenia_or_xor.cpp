#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    
    /*
    Thumb rule: 

    for 0 based indexing 
                index
              /       \
        2*index+1   2*index+2

    3 Things are used to build a segment tree
    - range L,R
    - index
    - segment tree size (4n) 
    */

    vector<int> segmentTreeArray;
    int range=0;
    SegmentTrees(){}

    SegmentTrees(int n){
        // initialize segment tree array 
        range=n;
        segmentTreeArray.resize(4*n+1);
    }

    void buildSegmentTree(int index,int low,int high,vector<int>& array){
        // base case 
        if(low==high){
            segmentTreeArray[index] = array[low];
            return;
        }

        // divide array into two halves 
        int mid = low + (high-low)/2;
        buildSegmentTree(2*index+1, low, mid, array); // left
        buildSegmentTree(2*index+2, mid+1, high, array); // right

        // backtrack, find min/max of current index 
        segmentTreeArray[index] = min(segmentTreeArray[2*index+1], segmentTreeArray[2*index+2]);
    }
    
    // TC: O(log n)
    void build(vector<int>& array){
        int index=0; // 0 based indexing
        int low=0;  
        int high=array.size()-1;

        buildSegmentTree(index,low,high,array);
    }

    void printSegmentTree(){
        int index=0;
        for(int i=0;i<segmentTreeArray.size();i++) cout<<segmentTreeArray[i]<<" ";
        cout<<endl;
    }

    /*
    3 conditions
    - partial overlap: some part is present, some is outside 
    - no overlap: lies outside range query, node does not contribute any to query result
    - complete overlap: completely reside inside range 

    for min(2,4)

    partial: [0,5], [0,2], [3,5] are partially in range(2,4)
        - left node
        - right node
        - return min(left, right)

    no overlap: [0,1], [5,5] are outside range(2,4)
        - return INT_MAX

    complete overlap; [2,2], [3,4] lies entirely in range(2,4)
        - return segmentTree[index] (min value of that range)
    */

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

    void query_2(int index,int low,int high,vector<int>& array,int flag){
        // base case 
        if(low==high){
            segmentTreeArray[index]=array[low];
            return;   // starting with OR operation 
        }

        int mid=low+(high-low)/2;
        query_2(2*index+1, low,mid,array, !flag);
        query_2(2*index+2, mid+1,high,array, !flag);

        // or is 1
        if(flag==1){
            segmentTreeArray[index] = segmentTreeArray[2*index+1] | segmentTreeArray[2*index+2];
        }
        // xor is 0
        else segmentTreeArray[index] = segmentTreeArray[2*index+1] ^ segmentTreeArray[2*index+2];
    }

    void queryUpdate(int index,int low,int high,int i,int value,int flag){
        // base case 
        if(low==high){
            segmentTreeArray[index]=value;
            return;   // starting with OR operation 
        }

        int mid=low+(high-low)/2;
        if(i<=mid){ 
            // left
            queryUpdate(2*index+1, low,mid,i,value,!flag);
        }else{
            // right
            queryUpdate(2*index+2, mid+1,high,i,value,!flag);
        }

        // or is 1
        if(flag==1){
            segmentTreeArray[index] = segmentTreeArray[2*index+1] | segmentTreeArray[2*index+2];
        }
        // xor is 0
        else segmentTreeArray[index] = segmentTreeArray[2*index+1] ^ segmentTreeArray[2*index+2];
    }

    int orXorQuery(vector<int>& array){
        int index=0;    // start
        int low=0;
        int high=range-1;   // 6-1=5
        if(array.size()%2==0)
            query_2(index,low,high,array,0);  // start with xor first 
        else
            query_2(index,low,high,array,1); // start with or first 

        // or
        // query(index,low,high,array);
        return segmentTreeArray[0];
    }

    int orXorPointUpdate(int i,int value,int flag){
        int index=0;    // start
        int low=0;
        int high=range-1;   // 6-1=5
        queryUpdate(index,low,high,i,value,flag);
        return segmentTreeArray[0];
    }

    // TC: O(log n)
    // Type 2: index, value, update array [index]=value, then preform query
    void update(int index,int low,int high,int i,int value){
        // base case 
        if(low==high){
            segmentTreeArray[index]=value;
            return;
        }

        // search for index
        int mid=low+(high-low)/2;
        if(i<=mid){ 
            // left
            update(2*index+1, low,mid,i,value);
        }else{
            // right
            update(2*index+2, mid+1,high,i,value);
        }

        // backtrack, keep updating parent nodes 
        segmentTreeArray[index]=min(segmentTreeArray[2*index+1], segmentTreeArray[2*index+2]);
    }

    void pointUpdate(int i,int value){
        int index=0;
        int low=0;
        int high=range-1;
        update(index,low,high,i,value);
    }
    
};

/*
        1
       /  \
      2    2
     / \  / \
    3   4 4  3
       /  \ 
       5   5

*/


void solve_2(){
    vector<int> sg1;
    int n1;
    cin>>n1;

    int q;
    cin>>q;

    int n=pow(2,n1);
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        sg1.push_back(ip);
    }
    // seg tree size is 4n
    SegmentTrees s1(n);
    s1.orXorQuery(sg1);
  
    // build + querying    

    // 1 is type 1 ie query
    // 2 is type 2 i.e point update
    while(q--){
        // point update and query result return only 
        int ind,val;
        cin>>ind>>val;
        ind--;  // 1<=ind<=2^n

        // point update first thing
        sg1[ind]=val; 

        if(n1%2==0){
            int res=s1.orXorPointUpdate(ind,val,0);
            cout<<res<<endl;
        }
        else{
            int res=s1.orXorPointUpdate(ind,val,1);
            cout<<res<<endl;
        }
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

    // ll test;
    // cin>>test;
    // while(test--)
    // {
    //     solve();
    // }
    // solve();
    solve_2();
    return 0;
}



