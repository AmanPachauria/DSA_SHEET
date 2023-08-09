// Solution 1

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow = head, * fast = head;

         while(slow && fast->next!=NULL){
             
             slow  = slow->next;

             fast = fast->next->next;
             if(slow==fast){
                 ListNode* a = slow;
                 while(slow){
                     a = min(a,slow);
                     slow = slow->next;
                     if(slow==fast) return a;

                 }
             }

             if(fast==NULL || fast->next==NULL) break;
             
         }
         return NULL;
    }
};