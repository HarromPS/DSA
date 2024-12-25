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
    int range=0;
    SegmentTrees(int n){
        // initialize segment tree array 
        range=n;
        segmentTreeArray.resize(4*n+1,-1);
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
    int query(int index,int low,int high, int left,int right){
        // no overlap [low high] [l r] or [l r] [low high] this side or that side 
        if(high<left || right<low){
            return INT_MAX;
        }

        // complete overlap [low l r high]
        if(low<=left && right<=high){
            return segmentTreeArray[index];
        }

        // rest is partial overlap 
        int mid=low+(high-low)/2;
        int leftNode=query(2*index+1,low,mid,left,right);
        int rightNode=query(2*index+2,mid+1,high,left,right);

        return min(leftNode,rightNode);

    }
    int minRangeQuery(int left,int right){
        int index=0;    // start
        int low=0;
        int high=range-1;   // 6-1=5
        int res=query(index,low,high,left,right);
        return res;
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
void solve(){
    // finding min and max in an array in a range in O(log n) time complexity
    vector<int> array;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ip;
        cin>>ip;
        array.push_back(ip);
    }

    // seg tree size is 4n
    SegmentTrees s(array.size());
    s.build(array);
    // s.printSegmentTree();
    
    int q;
    cin>>q;
    // 1 is type 1 ie query
    // 2 is type 2 i.e point update
    while(q--){
        int type;
        cin>>type;
        int l,r;
        cin>>l>>r;

        if(type==1){
            int res=s.minRangeQuery(l,r);   // left right
            cout<<res<<endl;
        }else{
            s.pointUpdate(l,r); // index value
        }
    }
    
}

void solve_2(){
    vector<int> sg1;
    vector<int> sg2;

    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int ip;
        cin>>ip;
        sg1.push_back(ip);
    }
    // seg tree size is 4n
    SegmentTrees s1(n1);
    s1.build(sg1);
    // s1.printSegmentTree();

    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++){
        int ip;
        cin>>ip;
        sg2.push_back(ip);
    }
    // seg tree size is 4n
    SegmentTrees s2(n1);
    s2.build(sg2);
    // s2.printSegmentTree();
    
    int q;
    cin>>q;
    // 1 is type 1 ie query
    // 2 is type 2 i.e point update
    while(q--){
        int type;
        cin>>type;

        // find min of minimim of 2 segment trees
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1=s1.minRangeQuery(l1,r1);   // left right
            int min2=s2.minRangeQuery(l2,r2);   // left right
            cout<<min(min1,min2)<<endl;
        }else{
            // point update of 1 array
            int arrayNo;
            cin>>arrayNo;
            int ind,val;
            cin>>ind>>val;
            
            if(arrayNo==1){
                s1.pointUpdate(ind,val);
                sg1[ind]=val;
            }else{
                s2.pointUpdate(ind,val);
                sg2[ind]=val;
            }
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



