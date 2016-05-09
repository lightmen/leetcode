/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *prev,*first,*second,*tmp;
    root.next = head;
    prev = &root;
    first = head;
    while(first){
        second = first->next;
        if(second){
            tmp = second->next;
            prev->next = second;
            second->next = first;
            first->next = tmp;
            prev = first;
        }
        first = first->next;
    }
    return root.next;
}
