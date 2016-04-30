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
    struct TreeNode **st;
    struct TreeNode *cur;
    int *data;
    int idx = 0;
    int top = -1;
    int data_count = 32;
    int st_count = 32;

    st = malloc(sizeof(struct TreeNode *) * st_count);
    data = malloc(sizeof(int) * data_count);

    if(root)
        st[++top] = cur;

    while(top > -1){
        cur = st[top--];

        data[idx++] = cur->val;
        if(idx == data_count){
            data_count <<= 1;
            data = realloc(data, sizeof(int) * data_count);
        }

        if(cur->right)
            st[++top] = cur->right;

        if(cur->left)
            st[++top] = cur->left;

        if(top+1 == st_count){
            st_count <<= 1;
            st = realloc(st, sizeof(struct TreeNode *) * st_count);
        }
    }

    *returnSize = idx;

    free(st);
    return data;
}
