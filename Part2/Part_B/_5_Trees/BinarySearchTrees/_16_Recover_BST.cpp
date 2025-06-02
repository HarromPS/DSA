
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.
               10
            /      \
           5        13
          /  \     /  \ 
          3   5   11  14
         / \   \ 
        2   4   9


               10
            /      \
           6        13
          /  \     /  \ 
          3   5   11  14
         / \   \ 
        2   4   9

        inorder: 2 3 4 "6 5" 10 11 13 14
        swap 6 and 5 

               10
            /      \
           5        6
          /  \     /  \ 
          3   13   11  14
         / \   \ 
        2   4   9

        inorder: 2 3 4 5 "13" 9 10 "6" 11 14
        swap 13 and 6 

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

class Solution{
public:
    void printTree(Node* node){
        if(node==nullptr) return;
        printTree(node->left);
        cout<<node->data<<" ";
        printTree(node->right);
    }

    // TC:O(N) SC:O(1)
    void recoverTree(Node* root) {
        // doing a morris inorder traversal 
        Node* prev=nullptr;
        Node* first_prev = nullptr;
        Node* first_curr = nullptr;
        Node* second = nullptr;
        if(root==nullptr) return;

        Node* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(prev!=nullptr && curr->data < prev->data){
                    if(first_prev==nullptr){
                        first_prev=prev;
                        first_curr=curr;
                    }else{
                        second=curr;
                        // break;
                    }
                }
                prev=curr;
                curr=curr->right;
            }else{
                Node* thread=curr->left;
                while(thread->right!=nullptr && thread->right!=curr){
                    thread=thread->right;
                }
                if(thread->right==nullptr){
                    thread->right=curr;
                    curr=curr->left;
                }else{
                    thread->right=nullptr;
                    if(prev!=nullptr && curr->data < prev->data){
                        if(first_prev==nullptr){
                            first_prev=prev;
                            first_curr=curr;
                        }else{
                            second=curr;
                            // break;
                        }
                    }
                    prev=curr;
                    curr=curr->right;
                }
            }
        }

        // swaps 
        // Tree is already valid or pointers are null
        if (first_prev == nullptr || first_curr == nullptr) {
            return;
        }

        if(second==nullptr){
            // swap first prev and first curr 
            int temp=first_prev->data;
            first_prev->data=first_curr->data;
            first_curr->data=temp;
        }else{
            // swap first curr and second 
            int temp=first_prev->data;
            first_prev->data=second->data;
            second->data=temp;
        }
    }
};
void solve(){
    Node root(10);
    Node two(6);
    Node three(13);
    Node four(3);
    Node five(5);
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
    
    Solution s;
    s.printTree(&root);
    cout<<endl;
    s.recoverTree(&root);    
    s.printTree(&root);
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
