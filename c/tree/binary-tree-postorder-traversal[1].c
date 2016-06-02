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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr;
    int arr_count = 32;
    struct TreeNode **st;
    struct TreeNode *pre = NULL;
    int st_count = 32;
    int idx = 0;
    int top = -1;

    arr = malloc(sizeof(int) * arr_count);
    st = malloc(sizeof(struct TreeNode *) * st_count);
    if(root)
        st[++top] = root;

    while(top > -1){
        struct TreeNode *cur = st[top];
        if((cur->left == NULL && cur->right == NULL) ||
            (pre && (pre == cur->left || pre == cur->right))){
            --top;
            if(idx == arr_count){
                arr_count <<= 1;
                arr = realloc(arr, sizeof(int) * arr_count);
            }
            arr[idx++] = cur->val;
            pre = cur;
        }else{
            if(top + 2 >= st_count){
                st_count <<= 1;
                st = realloc(st,sizeof(struct TreeNode *) * st_count);
            }
            if(cur->right)
                st[++top] = cur->right;
            if(cur->left)
                st[++top] = cur->left;
        }
    }

    *returnSize = idx;
    free(st);
    return arr;
}
