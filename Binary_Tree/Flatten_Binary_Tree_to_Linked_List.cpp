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
    void findlist(TreeNode* temp){
        if(temp==NULL){
            return;
        }

        
    }
   
    void flatten(TreeNode* root) {
       
        findlist(root);
    }
};



# Solution 2

class Solution {
public:
    TreeNode* prev = NULL;
    void findlist(TreeNode* temp){
        if(temp==NULL){
            return;
        }
        
        stack<TreeNode*> st;
        st.push(temp);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right!=NULL){
                st.push(curr->right);
            }
            if(curr->left!=NULL){
                st.push(curr->left);
            }

            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;

        }
    }
   
    void flatten(TreeNode* root) {
       
        findlist(root);
    }
};