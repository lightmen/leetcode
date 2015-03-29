/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int maxDepth(struct TreeNode *root) {
    int lc,rc;
    if(root == NULL)
        return 0;
    lc = maxDepth(root->left);
    rc = maxDepth(root->right);
    
    return lc > rc ? lc + 1 : rc + 1;
}
