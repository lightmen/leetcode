/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int list_count(struct ListNode *head)
{
    int count = 0;

    while(head){
        count++;
        head = head->next;
    }

    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode root;
    struct ListNode *l1,*l2;

    root.next = head;
    l1 = &root;
    l2 = &root;

    if(head == NULL)
        return NULL;

    k %= list_count(head);
    while(k-- > 0)
        l2 = l2->next;

    while(l2->next){
       l1 = l1->next;
       l2 = l2->next;
    }

    l2->next = root.next;
    root.next = l1->next;
    l1->next = NULL;

    return root.next;
}
