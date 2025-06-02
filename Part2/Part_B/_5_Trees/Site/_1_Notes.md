## In trees Try Bottom up approach first. Building from leaf node to root node

```cpp

/*
You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.

Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

Examples:

Input: tree = 5
            /   \
          7     8
        / 
      2
Output: 2 5 8
Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
*/

class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // Bottom up approach
        if(root==NULL){
            return root;
        }
        
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        if(root->left!=NULL && root->right==NULL){
            return root->left;
        }else if(root->left==NULL && root->right!=NULL){
            return root->right;
        }
        
        // if both are null or both are not null simultaneously return root
        return root;
    }
};

```


### BST
> 1. A single node(leaf node) is a BST
> 2. An empty node is also a BST
```cpp

/*
    2
  /   \
  1   3      is a bst


    3         is a bst

    ""        is a bst


    1
  /   \ 
  2    3     is not a bst

*/
```