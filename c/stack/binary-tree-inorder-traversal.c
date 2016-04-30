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
    struct TreeNode **st;
    struct TreeNode *cur;
    int *arr;
    int top;
    int idx = 0;
    int st_count = 50;
    int arr_count = 50;

    st = malloc(sizeof(struct TreeNode *) * st_count);
    arr = malloc(sizeof(int) * arr_count);
    top = -1;

    cur = root;
    while(cur || top > -1){
        while(cur){
            if(top + 1 == st_count){
                st_count <<= 1;
                st = realloc(st,st_count * sizeof(struct TreeNode *));
            }
            st[++top] = cur;
            cur = cur->left;
        }

        cur = st[top];
        top--;
        arr[idx++] = cur->val;
        cur = cur->right;
        if(idx == arr_count){
            arr_count <<= 1;
            arr = realloc(arr, arr_count * sizeof(int));
        }
    }

    free(st);
    *returnSize = idx;

    return arr;
}
