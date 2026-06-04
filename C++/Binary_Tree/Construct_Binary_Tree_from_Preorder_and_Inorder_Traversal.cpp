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

    TreeNode* CTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is,int ie, map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int ind = mp[root->val];
        int num = ind - is;

        root->left = CTree(preorder, ps+1, ps+num, inorder, is, ind-1, mp);
        root->right = CTree(preorder, ps+num+1, pe, inorder, ind+1, ie, mp);

        return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          
         map<int,int> mp;
         for( int i = 0; i < inorder.size(); i++ ){
             mp[inorder[i]] = i;
         }

         return CTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};