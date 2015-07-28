/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge(struct ListNode *left, struct ListNode *right)
{
    struct ListNode root;
    struct ListNode *cur = &root;
    while(left && right){
        if(left->val < right->val){
            cur->next = left;
            left = left->next;
        }else{
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    cur->next = left ? left : right;
    return root.next;
}

struct ListNode *split(struct ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode *right = split(slow->next);
    slow->next = NULL;
    struct ListNode *left = split(head);

    return merge(left,right);
}

struct ListNode* sortList(struct ListNode* head) {
    return split(head);
}
