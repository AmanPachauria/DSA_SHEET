/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
#include <bits/stdc++.h>

void findpre(TreeNode* root, int key, int &predecessor){

    while(root){
        if(root->data>=key){
            root = root->left;
        }
        else{
            predecessor = root->data;
            root = root->right;
        }
    }
}

void findsucc(TreeNode* root, int key, int &successor){
    while(root){
        if(root->data<=key){
            root = root->right;
        }
        else{
            successor = root->data;
            root = root->left;
        }
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    findpre(root, key, predecessor);
    int successor = -1;
    findsucc(root, key, successor);

    pair<int,int> p = {predecessor, successor};
    return p;
}