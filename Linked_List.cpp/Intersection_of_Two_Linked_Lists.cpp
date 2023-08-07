// Solution 1

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

          unordered_set<ListNode *> st;
          while(headA){
              st.insert(headA);
              headA = headA->next;
          }

          while(headB){
              if(st.find(headB)!=st.end()){
                  return headB;
              }
              headB = headB->next;
          }

          return NULL;     
    }
};

// Solution 2

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

         ListNode* a = headA;
         ListNode* b = headB;

         while(a!=b){

             if(a==NULL) a = headB;
             else a = a->next;
             if(b==NULL) b = headA;
             else b = b->next; 
         }
         return a;
        
    }
};