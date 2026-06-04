# Solution 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool symmetric(TreeNode* l, TreeNode* r){
        if(r==NULL && l!=NULL) return false;
        if(l==NULL && r!=NULL) return false;
        if(r!=NULL && l!=NULL && r->val!=l->val) return false;
    
        if(l==NULL || r==NULL){
            return true;
        }
        
        bool lh = symmetric(l->left, r->right);
        bool rh = symmetric(l->right, r->left);
        
        return (lh && rh);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        return symmetric(root->left, root->right);
    }
};



# Solution 2 

class Solution {
public:
    
    bool symmetric(TreeNode* l, TreeNode* r){
    
        if(l==NULL || r==NULL){
            return (l==r);
        }
         
        return (l->val==r->val && symmetric(l->left, r->right) && symmetric(l->right, r->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        return symmetric(root->left, root->right);
    }
};