/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *start,*tmp;
    struct ListNode right;
    int len,i;
    len = 0;
    start = head;
    while(head){
        len++;
        head = head->next;
    }

    head = start;
    i = 0;
    while(i < (len+1)/2){
        head = head->next;
        i++;
    }

    right.next = NULL;
    while(head){
        tmp = head;
        head = head->next;
        tmp->next = right.next;
        right.next = tmp;
    }

    tmp = right.next;
    while(tmp){
        if(start->val != tmp->val)
            return false;
        start = start->next;
        tmp = tmp->next;
    }

    return true;
}
