/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *ret;
    struct ListNode *prev;
    ret = head;

    while(head && head->next){
        prev = head;
        head = head->next;
        if(prev->val == head->val){
            prev->next = head->next;
            head = prev;
        }
    }

    return ret;
}
