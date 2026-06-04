// Solution 1

class Solution {
public:
    bool hasCycle(ListNode *head) {
         
         unordered_set<ListNode*> st;
         while(head){
             if(st.find(head)!=st.end()){
                 return true;
             }
             st.insert(head);
             head = head->next;
         }
         return false;
    }
};

// Solution 2

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL) return false;
        ListNode* slow = head, * fast = head;
        while(slow && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
            if(fast==NULL) return false;
        }

        return false;
    }
};