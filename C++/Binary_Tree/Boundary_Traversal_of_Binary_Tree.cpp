/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <bits/stdc++.h>


void findleft(TreeNode<int> *temp, vector<int> &ans){
     TreeNode<int> *temp1 = temp;
     while (temp1) {
         if(temp1->left!=NULL || temp1->right!=NULL){
             ans.push_back(temp1->data);
         }
         if(temp1->left) temp1 = temp1->left;
         else temp1 = temp1->right;
     }

     return;
} 

void findleaf(TreeNode<int> *temp, vector<int> &ans){
    if(temp==NULL){
        return;
    }

    if(temp->left==NULL && temp->right==NULL){
        ans.push_back(temp->data);
    }

    findleaf(temp->left, ans);
    findleaf(temp->right, ans);
}

void findright(TreeNode<int> *temp, vector<int> &ans){
    vector<int> vec;
    while(temp){
        if(temp->left!=NULL || temp->right!=NULL){
            vec.push_back(temp->data);
        }
        if(temp->right) temp = temp->right;
        else temp = temp->left;
    }

    for( int i = vec.size()-1; i>=0; i--){
        ans.push_back(vec[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(root==NULL) return ans;
    ans.push_back(root->data);
    findleft(root->left, ans);
    findleaf(root, ans);
    findright(root->right, ans);
   
    return ans;
}
