/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 struct TreeNode *bst(int num[], int beg, int end)
 {
     if(beg > end)
        return NULL;
    struct TreeNode *head;
    int mid = (beg + end) / 2;
    head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    head->val = num[mid];
    head->left = bst(num,beg,mid-1);
    head->right = bst(num,mid+1,end);
    return head;
 }
struct TreeNode *sortedArrayToBST(int num[], int n) {
    return bst(num,0,n-1);
}
