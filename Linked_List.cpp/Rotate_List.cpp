// Solution 1

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int cnt = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp->next = head;
        k = k%cnt;
        int end = cnt-k;
        while(end--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;

      return head;   
    }
};