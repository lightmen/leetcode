/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Key idea: Construct in bottom up way, 
 * store the part lists which increase in
 * 1,2,4,8,16,..2^k order.
 */
static struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode head,*tail = &head;
    while(l1 && l2){
        if(l1->val < l2->val){
            tail->next = l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return head.next;
}

struct ListNode *sortList(struct ListNode *head) {
    struct ListNode *cur,*list;
    struct ListNode *part[32];
    int lev; /* index into part[] */
    int max_lev = 0;
    memset(part,0,sizeof(part));
    list = head;
    while(list){
        cur = list;
        list = list->next;
        cur->next = NULL;
        for(lev = 0; part[lev]; ++lev){
            cur = merge(cur,part[lev]);
            part[lev] = NULL;
        }
        part[lev] = cur;
        if(lev > max_lev)
            max_lev = lev;
    }
    for(lev = 0; lev <= max_lev; ++lev)
        if(part[lev])
            list = merge(list,part[lev]);
    return list;
}
