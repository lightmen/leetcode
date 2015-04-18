/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
bool pre_order(struct TreeNode *root,struct TreeNode **prev)
{
    if(!root)
        return true;
    if(root->left && !pre_order(root->left,prev))
        return false;
    if(*prev && (*prev)->val >= root->val)
        return false;
    *prev = root;
    if(!root->right)
        return true;
    return pre_order(root->right,prev);
}
bool isValidBST(struct TreeNode *root) {
    struct TreeNode *prev = NULL;
    return pre_order(root,&prev);
}
