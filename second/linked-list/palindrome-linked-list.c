/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int get_length(struct ListNode *head)
{
    int ret = 0;
    while(head){
        head = head->next;
        ret++;
    }
    return ret;
}

bool isPalindrome(struct ListNode* head) {
    int len;
    int i;
    struct ListNode root;
    struct ListNode *left;
    struct ListNode *tmp;

    root.next = NULL;
    left = head;
    len = get_length(head);

    for(i = 0; i < (len+1) / 2; i++)
        head = head->next;

    while(head){
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    tmp = root.next;
    while(tmp){
        if(tmp->val != left->val)
            return false;
        tmp = tmp->next;
        left = left->next;
    }

    return true;
}
