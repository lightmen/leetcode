/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseNode(struct ListNode *head)
{
    struct ListNode root;
    root.next = NULL;
    while(head){
        struct ListNode *tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    return root.next;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *begin;
    struct ListNode *tail;
    struct ListNode root;
    struct ListNode *prev;
    int i;

    root.next = head;
    prev = &root;
    while(head){
        i = 1;
        begin = head;
        while(head && i < k){
            head = head->next;
            i++;
        }

        if(head == NULL)
            goto out;
        tail = head->next;
        head->next = NULL;
        prev->next = reverseNode(begin);
        prev = begin;
        prev->next = tail;
        head = prev->next;
    }

out:
    return root.next;
}
