/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len_a = 0;
    int len_b = 0;
    int n;
    struct ListNode *la = headA;
    struct ListNode *lb = headB;

    while(la){
        len_a++;
        la = la->next;
    }
    while(lb){
        len_b++;
        lb = lb->next;
    }

    la = (len_a > len_b) ? headA : headB;
    lb = (la == headA) ? headB : headA;

    n = abs(len_a - len_b);
    while(n){
        la = la->next;
        n--;
    }

    while(la && lb){
        if(la == lb)
            return la;
        la = la->next;
        lb = lb->next;
    }

    return NULL;
}
