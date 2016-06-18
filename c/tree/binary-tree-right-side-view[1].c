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
int arr_size;
int idx;

void dfs(struct TreeNode *root,int depth)
{
    if(!root)
        return;

    if(depth >= idx)
        idx = depth;
    if(depth >= arr_size){
        arr_size <<= 1;
        arr = realloc(arr, sizeof(int) * arr_size);
    }
    arr[depth] = root->val;
    dfs(root->left, depth+1);
    dfs(root->right, depth+1);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    arr_size = 32;
    idx = -1;
    arr = malloc(sizeof(int) * arr_size);
    dfs(root,0);

    *returnSize = idx+1;

    return arr;
}
