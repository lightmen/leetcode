/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int get_size(struct ListNode *head)
{
    int size = 0;
    while(head){
        head = head->next;
        ++size;
    }

    return size;
}

struct TreeNode* bst_helper(struct ListNode **head, int size)
{
  if(size == 0)
    return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = bst_helper(head,size/2);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = bst_helper(head,size - size/2 - 1);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = get_size(head);
    if(head == NULL)
        return NULL;

    return bst_helper(&head,size);
}
