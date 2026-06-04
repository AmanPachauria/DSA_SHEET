// Solution 1

class Solution {
public:

    void AddnewNode(ListNode* &tail, int data){
         ListNode* temp = new ListNode(data);
         tail->next = temp;
         tail = tail->next;

         return;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


          ListNode* tail = new ListNode(1);
        // ListNode* tail = NULL;
         ListNode* temp = tail;
         while(list1 && list2){
             if(list1->val>list2->val){
                 AddnewNode(tail, list2->val);
                 list2 = list2->next;
             }
             else{
                 AddnewNode(tail, list1->val);
                 list1 = list1->next;
             }
         }

         while(list1){
             AddnewNode(tail, list1->val);
             list1 = list1->next;
         }
         while(list2){
             AddnewNode(tail, list2->val);
             list2 = list2->next;
         }

        //  ListNode* tail1 = tail->next;
         
         return temp->next;
    }
};



// Solution 2

