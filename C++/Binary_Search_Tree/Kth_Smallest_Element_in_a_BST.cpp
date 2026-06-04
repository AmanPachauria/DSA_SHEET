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
    int findk(TreeNode* root, int &k){
        if(root==NULL){
            return 0;
        }
          int l = findk(root->left, k);
          if(l!=0) return l;
             k--;
             if(k==0){
                 return root->val;
             }
             return findk(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        return findk(root, k);
        // return 0;
    }
};