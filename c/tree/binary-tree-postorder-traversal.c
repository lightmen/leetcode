/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count = 32;
void post_order(struct TreeNode *root, int **arr, int *idx)
{
    if(root == NULL)
        return ;
    post_order(root->left,arr,idx);
    post_order(root->right,arr,idx);
    if(*idx == count){
        count <<= 1;
        *arr = realloc(*arr,sizeof(int) * count);
    }
    (*arr)[(*idx)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr;
    int idx = 0;
    arr = malloc(sizeof(int) * count);
    post_order(root,&arr,&idx);

    *returnSize = idx;
    return arr;
}
