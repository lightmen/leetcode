/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *invert(struct TreeNode *root)
{
    if(!root)
        return NULL;
    struct TreeNode *tmp;
    tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    invert(root->left);
    invert(root->right);

    return root;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    return invert(root);
}
