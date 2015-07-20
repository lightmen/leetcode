/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *one;
    struct ListNode *two;

    one = head;
    two = head;

    while(one && two){
        one = one->next;
        two = two->next;

        if(two)
            two = two->next;
        if(one && one == two)
            return true;
    }

    return false;
}
