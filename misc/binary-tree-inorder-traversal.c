/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    struct TreeNode *st[500];
    int *ret;
    int top = -1;
    
    ret = (int *)malloc(sizeof(int) * 500);
    *returnSize = 0;
    while(root || top != -1){
        while(root){
            top++;
            st[top] = root;
            root = root->left;
        }
        root = st[top];
        top--;
        ret[*returnSize] = root->val;
        (*returnSize)++;
        root = root->right;
    }
    
    return ret;
}
