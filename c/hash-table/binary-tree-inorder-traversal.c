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

int *arr;
int count;
int idx;

void dfs(struct TreeNode* root)
{
    if(root == NULL)
        return;

    dfs(root->left);

    if(idx == 0 || idx == count){
        count <<= 1;
        arr = realloc(arr,sizeof(int) * count);
    }
    arr[idx++] = root->val;

    dfs(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    arr = NULL;
    count = 32;
    idx = 0;

    dfs(root);

    *returnSize = idx;
    return arr;
}
