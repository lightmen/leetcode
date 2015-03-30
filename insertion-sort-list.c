i/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *insertionSortList(struct ListNode *head) {
    struct ListNode *prev,*point,*tmp,*ln_insert;
     if(head == NULL || head->next == NULL)
        return head;
    tmp = head->next;
    head->next = NULL;
    while(tmp){
        prev = NULL;
        point = head;
        while(point && point->val < tmp->val){
            prev = point;
            point = point->next;
        }
        
        ln_insert = tmp;
        tmp = tmp->next;
        ln_insert->next = point; 
        if(prev == NULL){
            head = ln_insert;
        }else{
            prev->next = ln_insert;
        }
    }
    return head;
}
