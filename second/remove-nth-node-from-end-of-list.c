/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *prev;
    struct ListNode root;
    int i;

    root.next = head;
    prev = &root;

    for(i = 0; i < n; ++i)
        head = head->next;

    while(head){
        head = head->next;
        prev = prev->next;
    }

    prev->next = prev->next->next;

    return root.next;
}
