/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode root;
    struct ListNode *l1,*l2;

    root.next = head;
    l1 = &root;
    l2 = &root;

    while(n--){
        l2 = l2->next;
    }

    while(l2->next){
        l1 = l1->next;
        l2 = l2->next;
    }

    l1->next = l1->next->next;

    return root.next;
}
