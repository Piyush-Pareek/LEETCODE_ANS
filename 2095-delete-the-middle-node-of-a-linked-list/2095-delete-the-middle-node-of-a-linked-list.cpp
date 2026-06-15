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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 0;

        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        if(size == 1)return NULL;
        temp = head;
        for(int i = 1;i<size/2;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head; 

    }
};