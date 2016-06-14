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
void recursive(struct TreeNode* root, int **array, int *idx, int *arr_size)
{
    if(!root)
        return ;


    if(*idx >= *arr_size){
        *arr_size <<= 1;
        *array = realloc(*array, sizeof(int) * (*arr_size));
    }

    int *arr = *array;
    arr[(*idx)++] = root->val;
    recursive(root->left,&arr,idx,arr_size);
    recursive(root->right,&arr,idx,arr_size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = NULL;
    int arr_size = 32;
    *returnSize = 0;

    arr = malloc(sizeof(int) * arr_size);
    recursive(root,&arr,returnSize,&arr_size);

    return arr;
}
