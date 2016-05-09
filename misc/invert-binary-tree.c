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

    struct TreeNode *tmp;
    tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);

    return root;
}
