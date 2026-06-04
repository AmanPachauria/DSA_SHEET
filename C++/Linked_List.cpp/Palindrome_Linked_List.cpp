// Solution 1

class Solution {
public:
    void addnode(ListNode* & head, ListNode* &rehead){
         ListNode* temp = head;
         while(temp){
             ListNode* temp1 = new ListNode(temp->val);
             if(rehead==NULL){
                 rehead = temp1;
             }
             else{
                 temp1->next = rehead;
                 rehead = temp1;
             }
             temp = temp->next;
         }
    }
    bool isPalindrome(ListNode* head) {

       ListNode* rehead = NULL;
       addnode(head, rehead);
      
       while(head!=NULL && rehead!=NULL){
           if(head->val!=rehead->val) return false;
           head = head->next;
           rehead = rehead->next;
       }

        return true;
    }
};


// Solution 2

