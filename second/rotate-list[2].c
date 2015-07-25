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
        ret++;
        head = head->next;
    }

    return ret;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len;
    int i;
    struct ListNode root;
    struct ListNode *prev;

    if(head == NULL)
        return NULL;

    root.next = head;
    prev = root.next;

    len = get_length(head);
    k %= len;

    for(i = 0; i < k; ++i)
        head = head->next;

    while(head->next){
        head = head->next;
        prev = prev->next;
    }

    head->next = root.next;
    root.next = prev->next;
    prev->next = NULL;

    return root.next;
}
