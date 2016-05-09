/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int is_symmetric(struct TreeNode *left, struct TreeNode *right)
{
    if(!left && !right)
        return 1;
    if(!left || !right || left->val != right->val)
        return 0;
    return is_symmetric(left->right,right->left) 
        & is_symmetric(left->left,right->right);
}
bool isSymmetric(struct TreeNode *root) {
    if(!root)
        return true;
    return is_symmetric(root->left,root->right);
}
