// Solution 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* temp = new ListNode(node->next->val);
        node->val = temp->val;
        node->next = node->next->next;
        // ListNode* pre = node;
        // ListNode* curr = node->next;
        // pre->next = curr->next;
        
    }
};