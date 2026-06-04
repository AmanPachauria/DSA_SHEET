class Solution {
  public:
    
    void fidnmirror(Node* root){
        
        if(root==NULL) return;
         if(root->left!=NULL || root->right!=NULL){
            swap(root->left, root->right);
         }
        fidnmirror(root->left);
        fidnmirror(root->right);
    }
    void mirror(Node* node) {
        fidnmirror(node);
    }
};