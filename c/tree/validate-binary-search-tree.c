/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    if(root == NULL)
        return true;

    struct TreeNode *node = root->left;
    while(node && node->right)
        node = node->right;

    if(node && node->val >= root->val)
        return false;

    node = root->right;
    while(node && node->left)
        node = node->left;

    if(node && node->val <= root->val)
        return false;

    return isValidBST(root->left) && isValidBST(root->right);
}
