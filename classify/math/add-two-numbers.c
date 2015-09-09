/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* get_node(int val)
{
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = NULL;
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry;
    int val;
    struct ListNode root;
    struct ListNode *cursor;

    carry = 0;
    cursor = &root;
    while(l1 && l2){
        val = l1->val + l2->val + carry;
        carry = val / 10;
        val %= 10;
        cursor->next = get_node(val);
        cursor = cursor->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l2)
        l1 = l2;

    while(l1){
        val = l1->val + carry;
        carry = val / 10;
        val %= 10;
        cursor->next = get_node(val);
        cursor = cursor->next;

        l1 = l1->next;
    }

    if(carry)
        cursor->next = get_node(carry);

    return root.next;
}
