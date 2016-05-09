/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *tmp;
    root.next = NULL;
    while(head){
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }
    return root.next;
}
