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
    struct TreeNode **st;
    struct TreeNode *cur, *pre = NULL;
    int top;
    int *data;
    int idx;
    int st_count = 32;
    int data_count = 32;

    data = malloc(sizeof(int) * data_count);
    st = malloc(sizeof(struct TreeNode *) * st_count);
    top = -1;
    idx = 0;

    if(root)
        st[++top] = root;

    while(top > -1){
        cur = st[top];
        if((cur->left == NULL && cur->right == NULL) ||
            (pre != NULL && (pre == cur->left || pre == cur->right))){
            if(idx == data_count) {
                data_count <<= 1;
                data = realloc(data,sizeof(int) * data_count);
            }
            data[idx++] = cur->val;
            top--;
            pre = cur;
        }else{
            if(top + 2 >= st_count){
                st_count <<= 1;
                st = realloc(st, sizeof(struct TreeNode *) * st_count);
            }
            if(cur->right != NULL)
                st[++top] = cur->right;
            if(cur->left != NULL)
                st[++top] = cur->left;
        }
    }

    free(st);
    *returnSize = idx;
    return data;
}
