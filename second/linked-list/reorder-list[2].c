/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *get_mid(struct ListNode *head)
{
    struct ListNode *slow,*fast;
    slow = head;
    fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode* reverse(struct ListNode *head)
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

struct ListNode* merge(struct ListNode *h1, struct ListNode *h2)
{
    int index = 0;
    struct ListNode root;
    struct ListNode *cur;
    cur = &root;
    while(h1 && h2){
        if(index % 2 == 0){
            cur->next = h1;
            h1 = h1->next;
        }else{
            cur->next = h2;
            h2 = h2->next;
        }
        cur = cur->next;
        index++;
    }

    if(h1){
        cur->next = h1;
    }else{
        cur->next = h2;
    }

    return root.next;
}

void reorderList(struct ListNode* head) {
    struct ListNode *tail;
    struct ListNode *mid;

    if(head == NULL || head->next == NULL)
        return ;

    mid = get_mid(head);
    tail = reverse(mid->next);
    mid->next = NULL;

    merge(head,tail);
}
