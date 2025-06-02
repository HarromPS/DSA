#include <bits/stdc++.h>
using namespace std;
#define ll int
#define mod 1000000007

/*
Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

You can find the definitions for a subsequence and a correct bracket sequence in the notes.
Input

The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.
Output

Print the answer to each question on a single line. Print the answers in the order they go in the input.

())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

0
0
2
10
4
6
6

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
    vector<Node*> segmentTreeArray;
    int range=0;
    int size=0;
    SegmentTrees(){}

    SegmentTrees(int n,int _size){
        // initialize segment tree array 
        range=n-1;
        size=_size;
        for(int i=0;i<4*n;i++){
            segmentTreeArray.push_back(new Node(0,0,0));
        }
        // segmentTreeArray.resize(4*n,0);
    }

    Node* merge(Node* left,Node* right){
        int full = left->full+right->full+min(left->open, right->close);
        int open = left->open + right->open - min(left->open, right->close);
        int close = left->close + right->close - min(left->open, right->close);
        return new Node(open,close,full);
    }

    // TC: O(log n) 
    Node* query(int index,int low,int high,int l,int r){
        // no overlap [low high] [l r] or [l r] [low high]
        if(high<l || r<low){
            return new Node(0,0,0);   // 0 full
        }

        // complete overlap [l low high r]
        if(l<=low && high<=r){
            return segmentTreeArray[index];
        }

        // partial overlap
        int mid=low+(high-low)/2;
        Node* leftFull=query(2*index+1, low,mid, l, r);
        Node* rightFull=query(2*index+2, mid+1,high, l, r);

        return merge(leftFull,rightFull);   // do or operation
    }   

    int sgQuery(int l,int r){
        int index=0;
        int low=0;
        int high=range;
        Node* res = query(index,low,high,l,r);
        return res->full*2;
    }

    void build(int index,int low,int high,string& s){
        // base case 
        if(low==high){
            segmentTreeArray[index]->open=(s[low]=='('?1:0);    // open
            segmentTreeArray[index]->close=(s[low]==')'?1:0);    // close
            segmentTreeArray[index]->full=0;    // full brackets
            return;   
        }

        int mid=low+(high-low)/2;
        build(2*index+1, low, mid, s);
        build(2*index+2, mid+1, high, s);

        // update segment tree while backtracking 
        int leftOpen=segmentTreeArray[2*index+1]->open;
        int leftClose=segmentTreeArray[2*index+1]->close;
        int leftFull=segmentTreeArray[2*index+1]->full;

        int rightOpen=segmentTreeArray[2*index+2]->open;
        int rightClose=segmentTreeArray[2*index+2]->close;
        int rightFull=segmentTreeArray[2*index+2]->full;

        segmentTreeArray[index]->full=leftFull+rightFull+min(leftOpen, rightClose);
        segmentTreeArray[index]->open=rightOpen+max(0, leftOpen - rightClose);
        segmentTreeArray[index]->close=leftClose+max(0, rightClose - leftOpen);

        // or 
        // segmentTreeArray[index]->open = leftOpen + rightClose - min(leftOpen, rightClose);
        // segmentTreeArray[index]->close=leftClose + rightClose - min(leftOpen, rightClose);
    }

    void sgBuild(string& s){
        int index=0;    // start
        int low=0;
        int high=range;   // 6-1=5
        build(index,low,high,s);
    }

    // print segment tree 
    void sgPrint(){
        for(auto it: segmentTreeArray){
            cout<<it->open<<" "<<it->close<<" "<<it->full<<endl;
        }
        cout<<endl;
    }
};

void solve_2(){
    string str;
    cin>>str;
    int q;
    cin>>q;
    int n=str.size();

    SegmentTrees s(n,n);
    s.sgBuild(str);
    // s.sgPrint();

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;    // 0 based indexing
        r--;    // 0 based indexing

        int res=s.sgQuery(l,r);
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

