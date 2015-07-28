/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *cur;

    root.next = head;
    cur = &root;
    while(head && head->next){
        struct ListNode *tmp = head->next->next;

        cur->next = head->next;
        head->next->next = head;
        head->next = tmp;

        cur = head;
        head = head->next;
    }

    return root.next;
}
