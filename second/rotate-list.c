/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode root;
    struct ListNode *prev;
    struct ListNode *tail;
    int i;
    int count;

    if(head == NULL)
        return NULL;

    root.next = head;
    prev = &root;

    count = 0;
    while(head){
        tail = head;
        head = head->next;
        count++;
    }
    head = root.next;
    k %= count;

    for(i = 0; i < count-k; ++i){
        prev = prev->next;
    }

    tail->next = root.next;
    root.next = prev->next;
    prev->next = NULL;

    return root.next;
}
