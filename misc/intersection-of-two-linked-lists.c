/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *la,*lb;
    la = headA;
    lb = headB;
    while(la && lb){
        if(la->val > lb->val)
            lb = lb->next;
        else if(la->val < lb->val)
            la = la->next;
        else
            return la;
    }
    return NULL;
}
