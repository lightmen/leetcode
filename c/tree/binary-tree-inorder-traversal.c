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
    int *arr;
    struct TreeNode **st;
    struct TreeNode *cur;
    int top = -1;
    int arr_count  = 32;
    int st_count = 32;
    int idx = 0;

    st = malloc(sizeof(struct TreeNode *) * st_count);
    arr = malloc(sizeof(int) * arr_count);

    cur = root;
    while(cur || top > -1){
        while(cur){
            if(top + 1 == st_count){
                st_count <<= 1;
                st = realloc(st,sizeof(struct TreeNode *) * st_count);
            }
            st[++top] = cur;
            cur = cur->left;
        }

        struct TreeNode *tmp = st[top--];
        cur = tmp->right;
        if(idx == arr_count){
            arr_count <<= 1;
            arr = realloc(arr, sizeof(int) * arr_count);
        }
        arr[idx++] = tmp->val;
    }

    *returnSize = idx ;
    free(st);
    return arr;
}
