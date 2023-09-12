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
    
    void finmaxdepth(TreeNode* node, int ind, int &ans){
        if(node==NULL){
            ans = max(ans, ind);
            return;
        }

        finmaxdepth(node->left, ind+1, ans);
        finmaxdepth(node->right, ind+1, ans);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        finmaxdepth(root, 0, ans);
        return ans;
    }
};