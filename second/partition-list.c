/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode left;
    struct ListNode right;
    struct ListNode *lit;
    struct ListNode *rit;

    lit = &left;
    rit = &right;
    while(head){
        if(head->val < x){
            lit->next = head;
            lit = lit->next;
        }else{
            rit->next = head;
            rit = rit->next;
        }
        head = head->next;
    }

    rit->next = NULL;
    lit->next = right.next;

    return left.next;
}
