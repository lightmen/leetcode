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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *st[1000];
    int top = -1;
    int *arr;
    int idx = 0;
    int count = 32;

    arr = malloc(sizeof(int) * count);
    while(root != NULL || top > -1){
        while(root){
            st[++top] = root;
            root = root->left;
        }

        root = st[top--];
        if(idx == count){
            count <<= 1;
            arr = realloc(arr, sizeof(int) * count);
        }
        arr[idx++] = root->val;
        root = root->right;
    }

    *returnSize = idx;
    return arr;
}
