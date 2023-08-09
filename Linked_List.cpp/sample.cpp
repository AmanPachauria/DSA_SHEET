 #include <bits/stdc++.h>
 using namespace std;

  Definition for linked list.
  class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 

void merge(Node* &head1, Node* temp){
	  
	  Node* temp2 = new Node(0);
	  Node* temp1 = temp2;

	  while(head1!=NULL && temp!=NULL){
           if(head1->data>temp->data){
			   Node* a = new Node(temp->data);
			   temp1->next = a;
			   temp1 = a;
			   temp = temp->child;
		   }
		   else{
			   Node* b = new Node(head1->data);
			   temp1->next = b;
			   temp1 = b;
			   head1 = head1->next;
		   }
	  }

	  while(head1){
         Node* b = new Node(head1->data);
			   temp1->next = b;
			   temp1 = b;
			   head1 = head1->next;
	  }
	  while(temp){
		   Node* a = new Node(temp->data);
			   temp1->next = a;
			   temp1 = a;
			   temp = temp->child;
	  }
      
	//   Node* temp3 = temp2->next;
	//   while(temp3){
	// 	  cout<<temp3->data<<" ";
	// 	  temp3 = temp3->next;
	//   }
	//   cout<<"\n";
     head1 = temp2->next;

	  return;
	  
 }

Node* flattenLinkedList(Node* head) 
{
	  Node* temp = head;
	  Node* head1 = NULL;
	  int cnt = 1;
	  while(temp){
		 merge(head1, temp);
		 Node* temp3 = head1;
		//  while(temp3){
		// 	 cout<<temp3->data<<" ";
		// 	 temp3 = temp3->next;
		//  }
		//  cout<<"\n";
		 temp = temp->next;
		 if(temp==NULL) return temp3;
		//  head1 = head2;
	  }

	  return head1;
}
