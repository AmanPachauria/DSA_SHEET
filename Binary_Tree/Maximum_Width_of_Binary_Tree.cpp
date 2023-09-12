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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int currmin = q.front().second;
            int leftmost, rightmost;
            for(int i = 0; i < size; i++ ){
                long long curr_id = q.front().second - currmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0) leftmost = curr_id;
                if(i==size-1) rightmost = curr_id;
                if(temp->left){
                    q.push({temp->left, curr_id*2+1});
                }
                if(temp->right){
                    q.push({temp->right, curr_id*2+2});
                }

            }

            ans = max(ans, rightmost-leftmost+1);
        } 

        return ans; 
    }
};