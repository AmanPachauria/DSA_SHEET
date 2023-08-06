// Solution 1 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp = new ListNode();
        ListNode* temp1 = temp;
        int pre = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = (l1->val)+(l2->val)+pre;
            if(sum>9){
                pre = 1;
                sum = sum%10;
            }else{
                pre = 0;
            }
            ListNode* l12 = new ListNode(sum);
            temp1->next = l12;
            temp1 = l12;
            l1 = l1->next;
            l2 = l2->next;
            // if(l1==NULL) break;
        }

        while(l1!=NULL){
            int sum = (l1->val)+pre;
            if(sum>9){
                pre = 1;
                sum = sum%10;
            }
            else{
                pre = 0;
            }
            ListNode* l12 = new ListNode(sum);
            temp1->next = l12;
            temp1 = l12;
            l1 = l1->next;
        }

         while(l2!=NULL){
            int sum = (l2->val)+pre;
            if(sum>9){
                pre = 1;
                sum = sum%10;
            }else{
                pre = 0;
            }
            ListNode* l12 = new ListNode(sum);
            temp1->next = l12;
            temp1 = l12;
            l2 = l2->next;
        }

        if(pre){
              ListNode* l12 = new ListNode(pre);
              temp1->next = l12;
              temp1 = l12;
        }

        return temp->next;
        
    }
};


// Solution 2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp = new ListNode();
        ListNode* temp1 = temp;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
             int sum = 0;
             if(l1!=NULL){
                 sum += l1->val;
                 l1 = l1->next;
             }
             if(l2!=NULL){
                 sum += l2->val;
                 l2 = l2->next;
             }

             sum += carry;
             carry = sum/10;
             sum = sum%10;
             ListNode* NewNode = new ListNode(sum);
             temp1->next = NewNode;
             temp1 = NewNode;
        }
           

        return temp->next;
        
    }
};