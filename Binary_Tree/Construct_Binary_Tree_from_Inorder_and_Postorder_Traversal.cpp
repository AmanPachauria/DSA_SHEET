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
    
    TreeNode* CTree(vector<int> &postorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int ind = mp[root->val];
        int num = ind - is;
        int num1 = ie - ind;
        
        root->left = CTree(postorder, ps, ps+num-1, inorder, is, ind-1, mp);
        root->right = CTree(postorder, pe-num1, pe-1, inorder, ind+1, ie, mp);

        return root;

    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for( int i = 0; i < inorder.size(); i++ ){
            mp[inorder[i]] = i;
        }    

       return CTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};