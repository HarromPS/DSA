#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Range Query Data structure

- 1. Segment Trees
    - min/max range query
    - point updates
    - sum range query 
    - point updates

- 2. Lazy propagation
- 3. Finwick Trees / BIT or Binary indexed trees
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
    SegmentTrees(int n){
        // initialize segment tree array 
        for(int i=0;i<n;i++) {
            segmentTreeArray.push_back(-1);
        }
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

    void build(vector<int>& array){
        int index=0; // 0 based indexing
        int low=0;  
        int high=array.size()-1;

        buildSegmentTree(index,low,high,array);
    }

    void printTree(int index){
        // base case
        if(index>=segmentTreeArray.size()){
            return;
        }

        cout<<segmentTreeArray[index]<<" "; // preorder traversal
        printTree(2*index+1);
        printTree(2*index+2);
    }

    void printSegmentTree(){
        int index=0;
        // printTree(index);
        for(int i=0;i<segmentTreeArray.size();i++) cout<<segmentTreeArray[i]<<" ";
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
void solve(){
    // finding min and max in an array in a range in O(log n) time complexity
    vector<int> array;
    array.push_back(1);
    array.push_back(3);
    array.push_back(2);
    array.push_back(0);
    array.push_back(4);
    array.push_back(5);

    // seg tree size is 4n
    SegmentTrees s(array.size()*4);

    s.build(array);
    s.printSegmentTree();
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
    solve();
    return 0;
}



