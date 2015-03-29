/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    int link_count = 0;
    struct ListNode *tmp;
    tmp = head;
    while(tmp){
        link_count++;
        tmp = tmp->next;
    }
    n = link_count - n - 1;
    if(n < 0)
        return head->next;
    tmp = head;
    while(n){
        n--;
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    return head;
}
