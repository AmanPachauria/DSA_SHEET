// Solution 1

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        cnt = cnt/2;
        while(cnt){
            head = head->next;
            cnt--;
        }
        return head;    
    }
};


// Solution 2

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode *slow = head, *fast = head;
        while((fast) && (fast->next))
            slow = slow->next, fast = fast->next->next;    

        return slow;
    }
};