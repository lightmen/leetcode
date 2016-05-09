/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int minDepth(struct TreeNode *root) {
    int lc,rc;
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    lc = minDepth(root->left);
    rc = minDepth(root->right);
    if(root->left == NULL || root->right == NULL)
        return root->left ? lc + 1 : rc + 1;
    return lc < rc ? lc + 1 : rc + 1;
}
