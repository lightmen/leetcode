/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode root;
    struct ListNode *prev,*tmp,*end;
    int count = 0;
    int i;
    
    root.next = head;
    prev = &root;

    while(head){
        if(count == m-1)
            break;
        prev = head;
        count++;
        head = head->next;
    }

    end = head;
    for(i = m; i <= n; ++i){
        tmp = head->next;
        head->next = prev->next;
        prev->next = head;
        head = tmp;
    }

    end->next = head;

    return root.next;
}
