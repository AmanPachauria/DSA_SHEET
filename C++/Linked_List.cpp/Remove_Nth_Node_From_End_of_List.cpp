// Solution 1

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

         ListNode* temp = head;
         int cnt = 0;
         while(temp){
            cnt++;
            temp=temp->next;
         }
         
         if(cnt==n){
             head = head->next;
         }
         else{
             ListNode* pre = NULL;
             ListNode* curr = head;

             while(cnt!=n){
                 pre = curr;
                 curr = curr->next;
                 cnt--;
             }
             pre->next = curr->next;
         }

         return head;
        
    }
};



// Solution 2

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         
         ListNode* start = new ListNode();
         start->next = head;
          
          ListNode* slow = start, *fast  = start;
          for( int i = 1; i <= n; i++ ) fast = fast->next;
          while(fast->next!=NULL){
              slow = slow->next;
              fast = fast->next;
          }
          slow->next = slow->next->next;

          return start->next;

        
    }
};