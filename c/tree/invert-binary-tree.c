/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root)
        return NULL;

    struct TreeNode *node = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = node;

    return root;
}
