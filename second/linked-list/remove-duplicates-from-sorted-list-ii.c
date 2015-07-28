/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *cur;
    int count;
    int val;

    cur = &root;
    while(head){
        count = 1;
        val = head->val;
        while(head->next && head->next->val == val){
            head = head->next;
            count++;
        }

        if(count > 1)
            goto next_loop;

        cur->next = head;
        cur = cur->next;

next_loop:
        head = head->next;
    }

    cur->next = NULL;
    return root.next;
}
