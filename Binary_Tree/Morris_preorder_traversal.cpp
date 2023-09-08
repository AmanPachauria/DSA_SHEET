#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void preorder(TreeNode* root, vector<int> &ans){
    while(root!=NULL){
        if(root->left==NULL){
            ans.push_back(root->data);
            root = root->right;
        }
        else{
            TreeNode* pre = root->left;
            while(pre->right!=NULL && pre->right!=root){
                pre = pre->right;
            }

            if(pre->right==NULL){
                pre->right = root;
                ans.push_back(root->data);
                root = root->left;
            }
            else{
                pre->right = NULL;
                root = root->right;
            }
        }
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{   
    vector<int> ans;
    preorder(root, ans);
    return ans;
}