/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode root;
    struct ListNode *end;
    int size = 0;
    
    if(!head)
        return NULL;

    root.next = head;
    end = &root;
    
    while(head){
        end = head;
        head = head->next;
        size++;
    }
    
    k %= size;
    head = root.next;
    while(k < size-1){
        head = head->next;
        k++;
    }
    end->next = root.next;
    root.next = head->next;
    head->next = NULL;
    
    return root.next;
}
