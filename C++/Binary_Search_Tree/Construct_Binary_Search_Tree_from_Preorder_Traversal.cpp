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


# Solution1

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        for( int i = 1; i < preorder.size(); i++ ){
            TreeNode* temp = root;
            TreeNode* temp1 = new TreeNode(preorder[i]);
            while(root){
                if(temp1->val>temp->val){
                    if(temp->right==NULL){
                        temp->right = temp1;
                         break;
                    }
                    else{
                        temp = temp->right;
                    }
                     
                }
                 if(temp1->val<temp->val){
                    if(temp->left==NULL){
                       temp->left = temp1;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
            }
        }

        return root;
    }
};


# Solution 2

class Solution {
public:
   
    TreeNode* ConstructTree(vector<int> &nums, int &ind, int mx){
        if(ind==nums.size()){
            return NULL;
        }
        if(nums[ind]>mx){
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[ind]);
        ind++;
        root->left = ConstructTree(nums, ind, root->val);
        root->right = ConstructTree(nums, ind, mx);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return ConstructTree(preorder, ind, INT_MAX);
    }
};