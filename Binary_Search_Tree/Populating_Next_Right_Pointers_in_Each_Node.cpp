/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void pointonext(Node* root){
        if(root==NULL) return;
        Node* temp = root;
        queue<Node*> q;
        q.push(temp);
        while(!q.empty()){
            int size = q.size();
            for( int i = 0; i < size; i++ ){
                Node* temp1 = q.front();
                q.pop();

                if(temp1->left!=NULL){
                    q.push(temp1->left);
                }
                if(temp1->right!=NULL){
                    q.push(temp1->right);
                }

                if(i<size-1){
                    temp1->next = q.front();
                }
                else{
                    temp1->next = NULL;
                }
            }

        }

    }
    Node* connect(Node* root) {
        pointonext(root);
        return root;
    }
};