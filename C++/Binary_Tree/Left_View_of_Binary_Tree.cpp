/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

void findallleftview(Node *root, int level, vector<int>&ans){
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->data);
    findallleftview(root->left, level+1, ans);
    findallleftview(root->right, level+1,ans);
    
    
}
vector<int> leftView(Node *root)
{
  vector<int> ans;
  findallleftview(root, 0, ans);
  
  return ans;
}
