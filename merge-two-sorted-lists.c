/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *ret,*insert,*cur;
    ret = NULL;
    if(!l1 || !l2){
        return l1 ? l1 : l2;
    }
    while(l1 && l2){
        if(l1->val < l2->val){
            insert = l1;
            l1 = l1->next;
        }else{
            insert = l2;
            l2 = l2->next;
        }
        if(ret == NULL){
            ret = insert;
            cur = ret;
        }else{
            cur->next = insert;
            cur = cur->next;
        }
    }
    if(l1)
        cur->next = l1;
    else if(l2)
        cur->next = l2;
    return ret;
}
