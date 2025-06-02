#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
You are given root node of the BST and the key node of the tree. 
You need to find the in-order successor and predecessor of a given key. 
If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

               10
            /      \
           5        13
          /  \     /  \ 
          3   6   11  14
         / \   \ 
        2   4   9

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

class BSTIterator_1{
public:
    void inorderTraversal(Node* node,vector<int>& v){
        if(node==nullptr) return ;
        inorderTraversal(node->left,v);
        v.push_back(node->data);
        inorderTraversal(node->right,v);
    }   

    vector<int> bstDs;
    int ind=-1;
    int size=0;

    BSTIterator_1(Node* root) {
        // do a inorder traversal and save all nodes in a ds
        if(root==nullptr) return;
        Node* node=root;
        while(node!=nullptr){
            if(node->left==nullptr){
                bstDs.push_back(node->data);
                node=node->right;
            }else{
                Node* prev=node->left;
                while(prev->right!=nullptr && prev->right!=node){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    // create thread 
                    prev->right=node;
                    node=node->left;
                }else{
                    // remove thread 
                    prev->right=nullptr;
                    bstDs.push_back(node->data);
                    node=node->right;
                }
            }
        }
        size=bstDs.size();
    }
    
    int next() {
        ind++;
        if(ind < size) {
            return bstDs[ind];
        }
        return -1;
    }
    
    bool hasNext() {
        if(ind+1<size) return true;;
        return false;
    }
};

class BSTIterator_2{
private:
    stack<Node*> st;
public:
    BSTIterator_2(Node* root){
        // push initially all nodes to stack till left is null
        pushAllNodes(root);
    }

    int next(){
        Node* node=st.top();
        st.pop();

        // push all nodes in right to stack
        pushAllNodes(node->right);
        return node->data;
    }

    bool hasNext(){
        if(st.empty()) return false;
        return true;
    }

    void pushAllNodes(Node* node){
        while(node!=nullptr){
            st.push(node);
            node=node->left;
        }
    }
};
void solve(){
    Node root(10);
    Node two(5);
    Node three(13);
    Node four(3);
    Node five(6);
    Node six(11);
    Node seven(14);
    Node eight(2);
    Node nine(4);
    Node ten(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.left=&six;
    three.right=&seven;

    four.left=&eight;
    four.right=&nine;

    five.right=&ten;
    
    BSTIterator_1 s(&root);

    int res;
    bool res_2;
    res=s.next();
    cout<<res<<endl;
    res=s.next();
    cout<<res<<endl;
    res_2=s.hasNext();
    cout<<res_2<<endl;
    res=s.next();
    cout<<res<<endl;
    res_2=s.hasNext();
    cout<<res_2<<endl;
    res=s.next();
    cout<<res<<endl;
    res_2=s.hasNext();
    cout<<res_2<<endl;
    res=s.next();
    cout<<res<<endl;
    res_2=s.hasNext();
    cout<<res_2<<endl<<endl;

    BSTIterator_2 s2(&root);

    res=s2.next();
    cout<<res<<endl;
    res=s2.next();
    cout<<res<<endl;
    res_2=s2.hasNext();
    cout<<res_2<<endl;
    res=s2.next();
    cout<<res<<endl;
    res_2=s2.hasNext();
    cout<<res_2<<endl;
    res=s2.next();
    cout<<res<<endl;
    res_2=s2.hasNext();
    cout<<res_2<<endl;
    res=s2.next();
    cout<<res<<endl;
    res_2=s2.hasNext();
    cout<<res_2<<endl;
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
    // int t;
    // cin>>t;
    // while(t--){
    // solve();
        
    // }
    solve();
    return 0;
}


