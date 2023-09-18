#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

void FindFloor(TreeNode<int> *root, int x, int &floor){
    
    while(root){
        if(root->val>x){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        }
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    FindFloor(root, X, floor);
    return floor;
}