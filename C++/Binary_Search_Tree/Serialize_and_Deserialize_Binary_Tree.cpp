/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
     void finds(TreeNode* root, string &s){
          if(root==NULL){
              return;
          }
          queue<TreeNode*> q;
          q.push(root);
          while(!q.empty()){
              TreeNode* temp = q.front();
              q.pop();
              if(temp==NULL){
                  s += "#";
                  s += ',';
              }else{
                  s += to_string(temp->val);
                  s += ',';
              }
              
              if(temp!=NULL){
                  q.push(temp->left);
                  q.push(temp->right);
              }
          }
     }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string s = "";
         finds(root, s);
         return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<"\n";
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
             
             getline(s, str, ',');
             if(str == "#"){
                 temp->left = NULL;
             }
             else{
                 TreeNode* temp1 = new TreeNode(stoi(str));
                 q.push(temp1);
                 temp->left = temp1;
             }
             
             getline(s, str, ',');
             if(str=="#"){
                 temp->right = NULL;
             }
             else {
                 TreeNode* temp1 = new TreeNode(stoi(str));
                 q.push(temp1);
                 temp->right = temp1;
             }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));