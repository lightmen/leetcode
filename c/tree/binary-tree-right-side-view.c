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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    struct TreeNode **st;
    struct TreeNode **next_st;
    int top = -1;
    int next_top = -1;
    int *arr;
    int idx = 0;
    int arr_size = 32;

    arr = malloc(arr_size * sizeof(int));
    st = malloc(100 * sizeof(struct TreeNode *));
    next_st = malloc(100 * sizeof(struct TreeNode *));


    if(root)
        st[++top] = root;

    while( top > -1){
        if(idx >= arr_size){
            arr_size <<= 1;
            arr = realloc(arr, sizeof(int) * arr_size);
        }
        arr[idx++] = st[top]->val;
        for(int i = 0; i <= top; ++i){
            if(st[i]->left)
                next_st[++next_top] = st[i]->left;
            if(st[i]->right)
                next_st[++next_top] = st[i]->right;
        }

        struct TreeNode **swap = st;
        st = next_st;
        next_st = swap;

        top = next_top;
        next_top = -1;
    }

    *returnSize = idx;
    free(st);
    free(next_st);
    return arr;
}
