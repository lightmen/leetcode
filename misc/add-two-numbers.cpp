/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = NULL;
        ListNode *p = NULL;
        ListNode *tmp = NULL;
        int d = 0;
        
        while(l1 && l2){
            tmp = new ListNode((l1->val + l2->val + d) % 10);
            d = (l1->val + l2->val + d) / 10;
            if(!ret){
                ret = tmp;
                p = ret;
            }else{
                p->next = tmp;
                p = tmp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            tmp = new ListNode((l1->val + d) % 10);
            d = (l1->val + d) / 10;
            if(!ret){
                ret = tmp;
                p = ret;
            }else{
                p->next = tmp;
                p = tmp;
            }
            l1 = l1->next;
        }
        
        while(l2){
            tmp = new ListNode((l2->val + d) % 10);
            d = (l2->val + d) / 10;
            if(!ret){
                    ret = tmp;
                    p = ret;
            }else{
                p->next = tmp;
                p = tmp;
            }
            l2 = l2->next;
        }
        
        if(d && !l1 && !l2){
            tmp = new ListNode(d);
            p->next = tmp;
        }
        
        return ret;
    }
};
