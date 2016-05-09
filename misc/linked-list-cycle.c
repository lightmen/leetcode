/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *one_step,*two_step;
    if(head == NULL)
        return false;
    one_step = head;
    two_step = head->next;
    while(one_step && two_step && one_step != two_step){
        one_step = one_step->next;
        two_step = two_step->next;
        if(two_step)
            two_step = two_step->next;
    }
    if(!one_step || !two_step)
        return false;
    return true;
}
