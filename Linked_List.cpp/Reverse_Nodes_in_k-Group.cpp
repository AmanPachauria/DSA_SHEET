// Solution 1

class Solution {
public:

   void ReverseList(ListNode* &temp){
       ListNode* newhead = NULL;
      while(temp!=NULL){
          ListNode* Next = temp->next;
          temp->next = newhead;
          newhead = temp;
          temp = Next;
      }

      temp = newhead;
      return;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* head1 = NULL, * tail1 = NULL;

        while(head){
            int k1 = k;
            ListNode* temp = new ListNode(head->val);
            ListNode* temp0 = temp;
            cout<<k1<<"\n";
            while(k1){
                
                if(k1!=k){
                     if(head==NULL) break;
                    ListNode* temp1 = new ListNode(head->val);
                    temp->next = temp1;
                    temp = temp1;

                }
                head = head->next;
                k1--;
            }

            if(k1==0){
               ReverseList(temp0);
            }
            
            if(head1==NULL){
                 ListNode * temp3 = new ListNode(temp0->val);
                 head1 = temp3;
                 tail1 = temp3;
                 temp0 = temp0->next;
            }

            while(temp0){
                ListNode* temp4 = new ListNode(temp0->val);
                tail1->next = temp4;
                tail1 = temp4;
                temp0 = temp0->next;
            }
        }
        return head1;    
    }
};


// Solution 2

