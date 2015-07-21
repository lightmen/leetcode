/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *cur;
    struct ListNode *tmp;

    root.next = NULL;
    while(head){
        cur = &root;
        while(cur->next && cur->next->val < head->val)
            cur = cur->next;

        tmp = cur->next;
        cur->next = head;
        head = head->next;
        cur->next->next = tmp;
    }

    return root.next;
}
