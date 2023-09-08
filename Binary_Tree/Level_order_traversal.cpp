#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void levelorder(struct Node* root, queue<int> &q){
    if()
}

int main(){

    struct Node* root = new Node(2);
    //  root->left = new Node(NULL);
     root->right = new Node(3);
     root->right->left = new Node(3);
     root->right->right = new Node(5);

     queue<int> q;
     levelorder(root, q);
    
}