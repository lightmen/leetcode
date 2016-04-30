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

        tmp = head->next;
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    return root.next;
}
