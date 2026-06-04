#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void FindCeil(BinaryTreeNode<int> *root, int x, int &ceil){
    while(root){
        if(root->data<x){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;
    FindCeil(node, x, ceil);
    return ceil;
}