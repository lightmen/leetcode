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
struct TreeNode* build(int *arr, int start, int end)
{
    struct TreeNode *root;
    int mid = (start + end) / 2;
    if(start > end)
        return NULL;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = build(arr,start,mid - 1);
    root->right = build(arr,mid+1,end);
    
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = 0;
    int i;
    int *arr;
    struct ListNode *tmp;
    tmp = head;
    while(head){
        size++;
        head = head->next;
    }
    head = tmp;
    arr = (int *)malloc(sizeof(int) * size);
    i = 0;
    while(head){
        arr[i++] = head->val;
        head = head->next;
    }
    
    return build(arr,0,size-1);
}
