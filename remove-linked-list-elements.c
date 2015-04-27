/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode root;
    struct ListNode *prev;
    
    root.next = head;
    prev = &root;
    
    while(head){
        if(head->val == val){
            prev->next = head->next;
            //free(head);
            head = prev;
        }
        prev = head;
        head = head->next;
    }
    
    return root.next;
}
