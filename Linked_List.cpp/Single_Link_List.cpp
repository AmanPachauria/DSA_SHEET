#include <bits/stdc++.h>
using namespace std;

class ListNode{

    public:
    int val;
    ListNode *next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

void print(ListNode* &temp){
     ListNode *temp1 = temp;
     while(temp1){
        cout<<temp1->val<<" ";
        temp1 = temp1->next;
     }
     cout<<"\n";
}

void Insertathead(ListNode* &head, int data){
      ListNode *temp1 = new ListNode(data);
      temp1->next = head;
      head = temp1;
}

void Insertattail(ListNode* &tail, int data){
      ListNode *temp1 = new ListNode(data);
      tail->next = temp1;
      tail = temp1;
}

void DeleteNode(ListNode* &head, int pos){

     if(pos==1){
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

     }

     return;
}

int main(){

    ListNode* temp = new ListNode(10);

    print(temp);

    ListNode* head = temp;
    ListNode* tail = temp;
    Insertathead(head,12);
    Insertathead(head,13);
    print(head);
    Insertattail(tail,15);
    Insertattail(tail,14);
    print(head);
    DeleteNode(head, 5);
    print(head);
    return 0;
}