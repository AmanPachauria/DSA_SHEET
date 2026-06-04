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
    int findmaxsum(TreeNode* node, int &ans){
        if(node==NULL){
            return  0;
        }

        int l = max(0, findmaxsum(node->left, ans));
        int r = max(0, findmaxsum(node->right, ans));
        ans = max({ans, l+r+node->val});
        return node->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        if(root==NULL) return ans;
        findmaxsum(root, ans);
        return ans;
    }
};