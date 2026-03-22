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
       int c=0;
        struct ListNode *head=NULL,*cur;
        cur = new struct ListNode();
        cur->next = NULL;
      
    while(l1!=NULL&&l2!=NULL){
        struct ListNode *p;
        p = new struct ListNode();
       
        p->val = ((l1->val+l2->val)+c)%10;
        p->next  = NULL;
        
        if(head == NULL){
            head = p;
        }
        cur->next = p;
        cur = p;
        c = (l1->val+l2->val+c)/10;
        
        l1 = l1->next;
        l2 = l2->next;
        
    }
    while(l1!=NULL){
       struct ListNode *p ;
        p = new struct ListNode();
        p->val = ((l1->val)+c)%10;
        p->next  = NULL;
        
        if(head == NULL){
            head = p;
        }
        cur->next = p;
        cur =p;
        c = (l1->val+c)/10;
   
    l1 = l1->next;
    
    }
     while(l2!=NULL){
         struct ListNode *p ;
          p = new struct ListNode();
        p->val = ((l2->val)+c)%10;
        p->next  = NULL;
        
        if(head == NULL){
            head = p;
        }
        cur->next = p;
        cur =p;
        c = (l2->val+c)/10;
  
    l2 = l2->next;
    }
    if(c  !=0){
        struct ListNode *p ;
          p = new struct ListNode();
        p->val = (c)%10;
        p->next  = NULL;
        cur->next =p;
    }
   
        return head;
    }
};