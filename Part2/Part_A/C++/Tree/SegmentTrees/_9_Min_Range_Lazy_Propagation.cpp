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

// find min range query 
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

    // TC: O(log n) 
    int query(int index,int low,int high,int l,int r){
        // update any remaining updates for fresh values
        if(segmentTreeArray[index]->lazyNode!=0){
            segmentTreeArray[index]->node+=segmentTreeArray[index]->lazyNode;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                segmentTreeArray[index*2+1]->lazyNode+=segmentTreeArray[index]->lazyNode;
                segmentTreeArray[index*2+2]->lazyNode+=segmentTreeArray[index]->lazyNode;
            }

            segmentTreeArray[index]->lazyNode=0;
        }

        // no overlap [low high] [l r] or [l r] [low high]
        if(high<l || r<low){
            return INT_MAX;   // 0 full
        }

        // complete overlap [l low high r]
        if(l<=low && high<=r){
            return segmentTreeArray[index]->node;
        }

        // partial overlap
        int mid=low+(high-low)/2;
        int left=query(2*index+1, low,mid, l, r);
        int right=query(2*index+2, mid+1,high, l, r);

        return min(left,right);   // do or operation
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
            segmentTreeArray[index]->node = array[low];
            segmentTreeArray[index]->lazyNode = 0;
            return;   
        }

        int mid=low+(high-low)/2;
        build(2*index+1, low, mid, array);
        build(2*index+2, mid+1, high, array);
        segmentTreeArray[index]->node = min(segmentTreeArray[index*2+1]->node, segmentTreeArray[index*2+2]->node);

    }

    void sgBuild(vector<int>& array){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        build(index,low,high,array);
    }

    void update(int index,int low,int high, int l,int r,int value){
        // traverse segment tree and see overlaps, & update the previous remaining updates 
        if(segmentTreeArray[index]->lazyNode!=0){
            segmentTreeArray[index]->node+=segmentTreeArray[index]->lazyNode;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                segmentTreeArray[index*2+1]->lazyNode+=segmentTreeArray[index]->lazyNode;
                segmentTreeArray[index*2+2]->lazyNode+=segmentTreeArray[index]->lazyNode;
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
            segmentTreeArray[index]->node+=(high-low+1)*value;

            // propagte lazy update down for remaining nodes to get updated
            if(low!=high){
                segmentTreeArray[index*2+1]->lazyNode+=value;
                segmentTreeArray[index*2+2]->lazyNode+=value;
            }
            return;
        }

        // partial overlap
        int mid=low+(high-low)/2;
        update(index*2+1, low,mid,l,r,value);
        update(index*2+2, mid+1,high,l,r,value);

        // backtrack 
        segmentTreeArray[index]->node=min(segmentTreeArray[2*index+1]->node,segmentTreeArray[2*index+2]->node);
    }

    void sgUpdate(int l,int r,int val){
        int index=0;
        int low=0;
        int high=range;
        update(index,low,high,l,r,val);
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
        if(type==1){    // query 
            int l,r;
            cin>>l>>r;
            int res=s.sgQuery(l,r);
            cout<<res<<endl;
        }else{
            int l,r,value;
            cin>>l>>r>>value;
            s.sgUpdate(l,r,value);
        }
    }
    // s.sgUpdate(2,4,5);
    // s.sgPrint();
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

