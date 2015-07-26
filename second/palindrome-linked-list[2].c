/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *glist;
bool helper(struct ListNode *head)
{
    if(head == NULL)
        return true;
    if(!helper(head->next))
        return false;
    if(head->val != glist->val)
        return false;

    glist = glist->next;
    return true;
}

bool isPalindrome(struct ListNode* head) {
    glist = head;
    return helper(head);
}
