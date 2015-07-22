/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    do {
        if(!slow || !fast || !fast->next)
            return NULL;

        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    while(head != slow){
        head = head->next;
        slow = slow->next;
    }

    return head;
}
