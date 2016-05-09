/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    while(head != NULL){
        if(INT_MIN != head->val)
            head->val = INT_MIN;
        else
            return head;
        head = head->next;
    }
    return NULL;
}
