/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse_range(struct ListNode *head,struct ListNode *tail)
{
    struct ListNode root;
    struct ListNode *tmp,*prev,*ret;

    ret = head;
    root.next = NULL;
    prev = &root;

    while(head){
        tmp = head->next;
        head->next = prev->next;
        prev->next = head;
        head = tmp;
    }
    tail->next = root.next;
    return ret;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode root;
    struct ListNode *tail,*cur,*tmp;
    int i;
    int count = 0;
    if(!k)
        return head;

    root.next = head;
    tail = &root;
    cur = head;
    while(cur){
        count++;
        if(count % k == 0){
            tmp = cur->next;
            
            cur->next = NULL;
            tail = reverse_range(tail->next,tail);
            tail->next = tmp;

            cur = tmp;
            continue;
        }
        cur = cur->next;
    }

    return root.next;
}
