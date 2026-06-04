#include <bits/stdc++.h>
using namespace std;

class ListNode{

    public:
    int val;
    ListNode* next;
    ListNode* pre;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
    return;
}

void InsertAtHead(ListNode* &head, int data){
     ListNode* temp = new ListNode(data);
     temp->next = head;
     head->pre = temp;
     head = temp;
     return;
}

void InsertAtTail(ListNode* &tail, int data){
    ListNode* temp = new ListNode(data);
    tail->next = temp;
    temp->pre = tail;
    tail = temp;
    return;
}

void DeleteNode(ListNode* &head, int pos){
    if(pos==1){
        head->next->pre = NULL;
        head = head->next;   
    }
    else{
        ListNode* pre = head, * curr = head;
        while(pos>1){
            pre = curr;
            curr = curr->next;
            pos--;
        }

        pre->next = curr->next;
        curr->next->pre = pre;
    }
    return;
}

int main(){
    ListNode* head = new ListNode(10);
    print(head); 

    ListNode* tail = head;

    InsertAtHead(head, 9);
    InsertAtHead(head, 8); 
    print(head);  

    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    print(head);

    DeleteNode(head, 2);
    print(head);


    return 0;
}