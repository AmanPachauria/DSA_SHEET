/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void findallorder(TreeNode* temp, vector<int> &postorder, vector<int> & inorder, vector<int> &preorder){
    if(temp==NULL) return;
    postorder.push_back(temp->data);
    findallorder(temp->left, postorder, inorder, preorder);
    inorder.push_back(temp->data);
    findallorder(temp->right, postorder, inorder, preorder);
    preorder.push_back(temp->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> postorder, inorder, preorder;
    findallorder(root, postorder, inorder, preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
    ans.push_back(preorder);

    return ans;
}
