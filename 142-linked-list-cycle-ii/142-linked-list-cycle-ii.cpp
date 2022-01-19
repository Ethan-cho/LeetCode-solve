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
    ListNode *detectCycle(ListNode *head) {
        ListNode *walker = head;
        ListNode *runner = head;
        
        while(runner != NULL){
            runner = runner->next;
            if(runner != NULL){
                runner = runner->next;
                walker = walker->next;
                if(runner == walker) break;
            }else break;
        }
        if(runner == NULL) return NULL;
        
        ListNode *check = head;
        while(check != walker){
            check = check->next;
            walker = walker->next;
        }
        return check;
    }
};