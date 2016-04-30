/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode root;
    struct ListNode *cur;

    root.next = head;
    cur = &root;
    while(cur->next){
        if(cur->next->val == val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }

    return root.next;
}
