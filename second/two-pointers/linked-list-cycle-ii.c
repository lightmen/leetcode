/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *l1,*l2;

    l1 = head;
    l2 = head;
    do{
        if(!l1 || !l2 || !l2->next)
            return NULL;
        l2 = l2->next->next;
        l1 = l1->next;
    }while(l1 != l2);

    l1 = head;
    while(l1 && l2 && l1 != l2){
        l1 = l1->next;
        l2 = l2->next;
    }

    return l1;
}
