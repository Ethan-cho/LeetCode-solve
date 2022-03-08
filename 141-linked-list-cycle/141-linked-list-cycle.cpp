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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next ==NULL){
            return false;
        }
        ListNode* x = head;
        ListNode* y = head->next;
        
        while(y != x) {
            if(y==NULL || y->next == NULL) return false;
            x = x->next;
            y = y->next->next;
        }
        return true;
    }
};