#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
// using namespace std;

/*
You're given a binary tree. 
Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). 
The size of a subtree is defined as the number of nodes it contains.

A subtree of the binary tree is considered a BST if for every node in that subtree, 
the left child is less than the node, and the right child is greater than the node, 
without any duplicate values in the subtree.


               10
            /      \
           5        13
          /  \     /  \ 
          3   5   11  14
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

class NodeValues{
public:
    int size;
    int largest;    // needed from left child
    int smallest;   // needed from right child

    NodeValues(int _size,int _largest,int _smallest){
        size=_size;
        largest=_largest;
        smallest=_smallest;
    }
};

class Solution{
public:
    bool validateBST(Node* node,int* nodeCount,long low,long high){
        if(node==nullptr) return true;

        if(!(low<node->data && node->data<high)){
            return false;
        }

        bool left=validateBST(node->left,nodeCount,low,node->data);
        bool right=validateBST(node->right,nodeCount,node->data,high);

        if(!left || !right) return false;
        *nodeCount+=1;
        return true;
    }

    void preorderTraversal(Node* node){
        if(node==nullptr) return;
        
        int tempCount=0;
        bool res = validateBST(node,&tempCount,LLONG_MIN,LLONG_MAX);
        if(res==true){       
            // if its a valid bst get all nodes 
            count=std::max(count,tempCount);
        }
        tempCount=0;

        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // there will always be a subtree with a valid bst and size 1
    int count=1 ;    // a global variable 

    // TC:O(N^2) SC:O(N^2)
    int largestBstBrute(Node *root){
        // traverse tree and return the max nodes in a subtree
        preorderTraversal(root);
        return count;
    }

    NodeValues solveLargestBst(Node* root){
        // if null node 
        if(root==nullptr) {
            return NodeValues(0,INT_MIN,INT_MAX);
        }

        // post order traversal
        NodeValues left = solveLargestBst(root->left);
        NodeValues right = solveLargestBst(root->right);

        // if it is a valid bst 
        if(left.largest < root->data && root->data < right.smallest){
            return NodeValues(1+left.size+right.size, std::max(root->data, right.largest), std::min(root->data, left.smallest));
        }

        // else not a bst, so return values such that its parents cant be a valid bst
        return NodeValues(std::max(left.size,right.size), INT_MAX, INT_MIN);
    }
    int largestBst(Node *root){
        NodeValues n = solveLargestBst(root);
        return n.size;
    }
};

void solve(){
    Node root(10);
    Node two(5);
    Node three(15);
    Node four(1);
    Node five(8);
    Node six(7);

    Node seven(14);
    Node eight(2);
    Node nine(4);
    Node ten(9);

    root.left = &two;
    root.right = &three;

    two.left=&four;
    two.right=&five;

    three.right=&six;
    // three.right=&seven;

    // four.left=&eight;
    // four.right=&nine;

    // five.right=&ten;
    
    Solution s;
    int res=s.largestBstBrute(&root);
    std::cout<<res<<std::endl;
    res=s.largestBst(&root);
    std::cout<<res<<std::endl;
   
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    solve();
    return 0;
}