/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode root;
    struct ListNode *cur;
    struct ListNode *tmp;
    struct ListNode *tail;
    int i = 1;

    root.next = head;
    cur = &root;

    while(i < m){
        i++;
        cur = cur->next;
    }

    head = cur->next;
    tail = head;
    cur->next = NULL;
    while(i <= n){
        i++;
        tmp = head->next;
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    tail->next = head;

    return root.next;
}
