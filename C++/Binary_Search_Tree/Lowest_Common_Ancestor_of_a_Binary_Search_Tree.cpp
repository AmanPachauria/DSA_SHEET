/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

# Solution 1

class Solution {
public:
    
    void findLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==NULL) return;
         if(p->val<=root->val && q->val>=root->val){
             ans = root;
             return;
         }
         if(p->val>=root->val && q->val<=root->val){
             ans = root;
             return;
         }

         if(root->val>p->val){
             findLCA(root->left, p, q, ans);
         }
         else{
              findLCA(root->right, p, q, ans);
         } 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        findLCA(root, p, q, ans);
        return ans;
    }
};




# Solution 2

class Solution {
public:
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr = root->val;
        if(p->val<curr && q->val<curr){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val>curr && q->val>curr){
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};