class Solution {
  public:
    
    void findbottomview(Node* temp, vector<int> &ans){
        map<int, int> mp;
        if(temp == NULL) return; 
        queue<pair<Node*, int>> q;
        q.push({temp, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node *temp1 = it.first;
            int line = it.second;
            mp[line] = temp1->data;
            
            if(temp1->left!=NULL){
                q.push({temp1->left, line-1});
            }
            if(temp1->right!=NULL){
                q.push({temp1->right, line+1});
            }
        }
        
        for( auto it:mp){
            ans.push_back(it.second);
        }
    }
  
    vector <int> bottomView(Node *root) {
         
         vector<int> ans;
         findbottomview(root, ans);
         return ans;
    }
};