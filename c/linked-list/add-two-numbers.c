/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *get_node(int val)
{
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = NULL;

    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode root;
    struct ListNode *cur = &root;
    struct ListNode *l;
    int carry = 0;
    int sum;

    while(l1 && l2){
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        cur->next = get_node(sum % 10);
        cur = cur->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    l = l1 ? l1 : l2;
    while(l){
        sum = carry + l->val;
        carry = sum / 10;
        cur->next = get_node(sum % 10);
        cur = cur->next;

        l = l->next;
    }

    if(carry)
        cur->next = get_node(carry);

    return root.next;
}
