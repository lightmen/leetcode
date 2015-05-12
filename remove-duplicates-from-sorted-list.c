/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode root;
    struct ListNode *prev;
    root.next = head;
    prev = head;
    while(prev && prev->next){
        head = prev->next;
        if(prev->val ==  head->val){
            prev->next = head->next;
        }else{
            prev = prev->next;
        }
    }
    return root.next;
}
