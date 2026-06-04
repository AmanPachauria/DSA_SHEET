// Solution 1

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

      ListNode* pre = NULL;
      ListNode* current = head;
      ListNode* nextp;
      while(current){
           nextp = current->next;
           current->next = pre;
           pre = current;
           current = nextp;

      }
       head = pre;
       return head;
    }
};



// Solution 2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

      ListNode* newhead = NULL;
      while(head!=NULL){
          ListNode* Next = head->next;
          head->next = newhead;
          newhead = head;
          head = Next;
      }

      return newhead;
    }
};