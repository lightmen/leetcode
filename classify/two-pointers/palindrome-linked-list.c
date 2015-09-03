/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode *head)
{
    struct ListNode root;
    struct ListNode *tmp;
    root.next = NULL;
    while(head){
        tmp = head->next;
        head->next = root.next;
        root.next = head;
        head = tmp;
    }

    return root.next;
}

bool isPalindrome(struct ListNode* head) {
    int count = 0;
    int i;
    struct ListNode root;
    struct ListNode *right;
    struct ListNode *mid,*tmp;

    root.next = head;
    while(head){
        count++;
        head = head->next;
    }

    head = &root;
    i = 0;
    while(i < ((count+1)/2)){
        head = head->next;
        i++;
    }

    mid = head;
    right = reverse(head->next);
    tmp = right;
    head = root.next;
    while(right){
        if(right->val != head->val){
            mid->next = reverse(tmp);
            return false;
        }
        right = right->next;
        head = head->next;
    }

    mid->next = reverse(tmp);
    return true;
}
