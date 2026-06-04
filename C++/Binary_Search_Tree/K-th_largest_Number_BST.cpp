#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int findk(TreeNode<int>* root, int &k){
    if(root==NULL){
        return -1;
    }

    int l = findk(root->right, k);
    if(l!=-1) return l;
    k--;
    if(k==0){
        return root->data;
    }

    return findk(root->left, k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    return findk(root, k);
}
