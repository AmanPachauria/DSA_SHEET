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
    void allnext(TreeNode* root, stack<TreeNode*> &next){
        while(root){
            next.push(root);
            root = root->left;
        }
    }

    void allbefore(TreeNode* root, stack<TreeNode*> &before){
        while(root){
            before.push(root);
            root = root->right;
        }
    }
    
    bool findk(TreeNode* root, int k){
        stack<TreeNode*> next;
        stack<TreeNode*> before;

        allnext(root, next);
        allbefore(root, before);

        while(next.size() && before.size()){
             TreeNode* a = next.top();
             TreeNode* b = before.top();
             if(a==b){
                 break;
             }
             if(a->val+b->val==k){
                 return true;
             }
             if(a->val+b->val<k){
                 next.pop();
                 allnext(a->right, next);
             }
             else{
                 before.pop();
                 allbefore(b->left, before);
             }
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
       return findk(root, k);
    }
};