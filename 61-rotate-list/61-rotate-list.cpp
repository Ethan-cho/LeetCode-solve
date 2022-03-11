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
    ListNode* solve(ListNode *node){
        ListNode* head = node;
        while(head->next->next){
            head=head->next;
        }
        ListNode* tail = head->next;
        head->next = NULL;
        tail->next = node;
        return tail;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* bakup = head;
        
        int len = 1;
        while(head->next){
            ++len; head = head->next;
        }
        head = bakup;
        
        for(int i=0;i<k%len;++i)
            head = solve(head);
        
        return head;
    }
};