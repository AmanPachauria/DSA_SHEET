#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d){

     Node* temp = new Node(d);
     temp -> next = head;
     head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

// void print
int main(){
    
    // created a new node
    Node* node1 = new Node(10);
    cout<<node1<<"\n";
    // Node* node1 = new Node(10);
    cout<< node1->data <<"\n";
    cout<< node1->next <<"\n";

    // head pointed to nodel
    Node* head = node1;

    // InsertAtHead(head, 12);
    // InsertAtHead(head, 15);
    // print(head);

    return 0;
}