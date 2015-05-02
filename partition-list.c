/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode left,right;
    struct ListNode *left_cursor,*right_cursor;

    left_cursor = &left;
    right_cursor = &right;

    while(head){
        if(head->val < x){
            left_cursor->next = head;
            left_cursor = left_cursor->next;
        }else{
            right_cursor->next = head;
            right_cursor = right_cursor->next;
        }
        head = head->next;
    }
    
    right_cursor->next = NULL;
    left_cursor->next = right.next;
    
    return left.next;
}
