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

    int pairSum(ListNode* head) {
        int size = 0;
        vector<int>num;
        ListNode* temp = head;
        while(temp){
            size++;
            num.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* tail = head;
        temp = head;
        int sum =0;
        int x = size-1;
        for(int i =1;i<=size/2;i++){
        
         sum = max(head->val+num[size-i],sum);
         head = head->next;
         tail =  head;
        }
        return sum;
    }
};

// 0 1 2 3 4 5 6 7 