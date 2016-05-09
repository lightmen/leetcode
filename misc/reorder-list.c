/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode left,right;
    struct ListNode *tmp;
    struct ListNode *l,*r;
    int size = 0;
    int i = 0;
    
    left.next = head;

    while(head){
        size++;
        head = head->next;
    }
    
    head = &left;
    while(i != ((size+1) / 2)){
        i++;
        head = head->next;
    }
    
    tmp = head->next;
    head->next = NULL;
    head = tmp;
    
    right.next = NULL;
    while(i != size){
        i++;
        tmp = head->next;
        head->next = right.next;
        right.next = head;
        head = tmp;
    }
    
    l = left.next;
    r = right.next;
    while(l && r){
        tmp = r->next;
        r->next = l->next;
        l->next = r;
        
        l = r->next;
        r = tmp;
    }
    head = left.next;
}
