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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr;
    struct TreeNode **st;
    int idx = 0;
    int arr_size = 32;
    int st_size = 32;
    int top = -1;

    arr = malloc(sizeof(int) * arr_size);
    st = malloc(sizeof(struct TreeNode *) * st_size);
    if(root)
        st[++top] = root;

    while(top > -1){
        struct TreeNode *cur = st[top--];
        if(idx == arr_size){
            arr_size <<= 1;
            arr = realloc(arr,sizeof(int) * arr_size);
        }

        arr[idx++] = cur->val;
        if(top + 2 >= st_size){
            st_size <<= 1;
            st = realloc(st, sizeof(struct TreeNode *) * st_size);
        }

        if(cur->right)
            st[++top] = cur->right;
        if(cur->left)
            st[++top] = cur->left;
    }

    *returnSize = idx;
    free(st);
    return arr;
}
