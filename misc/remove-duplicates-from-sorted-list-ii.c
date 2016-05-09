/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *prev,*tmp;
    int start_val;
    int count;
    
    root.next = NULL;
    prev = &root;
    while(head)
    {
        start_val = head->val;
        count = 1;
        while(head->next && head->next->val == start_val){
            ++count;
            head = head->next;
        }
        tmp = head->next;
        if(count == 1){
            head->next = prev->next;
            prev->next = head;
            prev = head;
        }
        head = tmp;
    }

    return root.next;
}
