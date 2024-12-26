#include <bits/stdc++.h>
using namespace std;
#define ll int
#define mod 1000000007

/*
Given a range L,R, update it to value +val
We know,
    point update takes O(log n) time, so for range L,R it will take O(log n * (R-L+1))
    so to reduce this we can use lazy propagation nodes 

    - we have a corresponding lazy node with each node in tree which will update in future 
    - initial value assigned to these nodes is 0
    - range update rules
        - traverse segment tree and see overlaps, & update the previous remaining updates 
        - check complete overlap
            - update the node 
            - lazy propagate down & return
        - check partial overlap
            - left 
            - right
            - return left+right
        - check no overlap
            - update the previous remaining updates 
            - lazy propagate down & return if any

*/

struct Node{
    int node;   // original node
    int lazyNode;   // corresponding node
    Node(){}
    Node(int _node,int _lazyNode){
        node=_node;
        lazyNode=_lazyNode;
    }
}typedef Node;

// Gives range query in O(log n) time complexity & uses recursion
class SegmentTrees{
public:
    vector<Node*> segmentTreeArray;
    int range=0;
    SegmentTrees(){}

    SegmentTrees(int n){
        // initialize segment tree array 
        range=n-1;
        for(int i=0;i<4*n;i++){
            segmentTreeArray.push_back(new Node(-1,0));
        }
        // segmentTreeArray.resize(4*n,0);
    }

    // Given coins array [1 1 0 0 1 0 1] where 1 is head or tail otherwise 
    // Type 1 is query: how many heads in a range l,r
    // Type 2 is update: flip coins in range l,r i.e h->t or t->h

    /*
    ip: 7
        1 1 0 0 1 0 1
        1 1 5 
        2 2 4 
        1 1 5

    op: 2
        3
     */

    // TC: O(log n) 
    int query(int index,int low,int high,int l,int r){
        // update any remaining updates for fresh values

        // 1 means we have to flip value 
        if(segmentTreeArray[index]->lazyNode!=0){
            // total coins in range - number of heads 
            segmentTreeArray[index]->node = (high-low+1)-segmentTreeArray[index]->node;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                // flip down lazy propagate
                segmentTreeArray[index*2+1]->lazyNode^=1;
                segmentTreeArray[index*2+2]->lazyNode^=1;
            }

            segmentTreeArray[index]->lazyNode=0;
        }

        // no overlap [low high] [l r] or [l r] [low high]
        if(high<l || r<low){
            return 0;   // 0 full
        }

        // complete overlap [l low high r]
        if(l<=low && high<=r){
            return segmentTreeArray[index]->node;
        }

        // partial overlap
        int mid=low+(high-low)/2;
        int left=query(2*index+1, low,mid, l, r);
        int right=query(2*index+2, mid+1,high, l, r);

        return left+right;   
    }

    int sgQuery(int l,int r){
        int index=0;
        int low=0;
        int high=range;
        int res=query(index,low,high,l,r);
        return res;
    }

    void build(int index,int low,int high,vector<int>& array){
        // base case 
        if(low==high){
            segmentTreeArray[index]->node = array[low];
            segmentTreeArray[index]->lazyNode = 0;
            return;   
        }

        int mid=low+(high-low)/2;
        build(2*index+1, low, mid, array);
        build(2*index+2, mid+1, high, array);
        segmentTreeArray[index]->node = segmentTreeArray[index*2+1]->node + segmentTreeArray[index*2+2]->node;

    }

    void sgBuild(vector<int>& array){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        build(index,low,high,array);
    }

    void update(int index,int low,int high, int l,int r){
        // traverse segment tree and see overlaps, & update the previous remaining updates 
        if(segmentTreeArray[index]->lazyNode!=0){
            segmentTreeArray[index]->node = (high-low+1)-segmentTreeArray[index]->node;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                // flip down lazy propagate
                segmentTreeArray[index*2+1]->lazyNode^=1;
                segmentTreeArray[index*2+2]->lazyNode^=1;
            }

            segmentTreeArray[index]->lazyNode=0;
        }
        
        // no overlap [low high][l r] or [l r][low high]
        if(high<l || r<low){
            return;
        }

        // complete overlap [l low high r]
        if(l<=low && high<=r){
            // previous update
            // lazy propagation 
            segmentTreeArray[index]->node = (high-low+1)-segmentTreeArray[index]->node;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                // flip down lazy propagate
                segmentTreeArray[index*2+1]->lazyNode = !segmentTreeArray[index*2+1]->lazyNode;
                segmentTreeArray[index*2+2]->lazyNode = !segmentTreeArray[index*2+2]->lazyNode;
            }
            return;
        }

        // partial overlap
        int mid=low+(high-low)/2;
        update(index*2+1, low,mid,l,r);
        update(index*2+2, mid+1,high,l,r);

        // backtrack 
        segmentTreeArray[index]->node=segmentTreeArray[2*index+1]->node+segmentTreeArray[2*index+2]->node;
    }

    void sgUpdate(int l,int r){
        int index=0;
        int low=0;
        int high=range;
        update(index,low,high,l,r);
    }

    // print segment tree 
    void sgPrint(){
        for(auto it: segmentTreeArray){
            cout<<it->node<<" "<<it->lazyNode<<endl;
        }
        cout<<endl;
    }
};

void solve_2(){
    int n;
    cin>>n;
    vector<int> array(n,0);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    SegmentTrees s(n);
    s.sgBuild(array);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        int l,r;
        cin>>l>>r;
        if(type==1){    // query             
            int res=s.sgQuery(l,r);
            cout<<res<<endl;
        }else{
            s.sgUpdate(l,r);
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
    solve_2();
    return 0;
}

