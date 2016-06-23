/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if(root == NULL)
        return ;

    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;

    root->left = NULL;
    root->right = left;

    flatten(left);
    flatten(right);

    while(root->right)
        root = root->right;

    root->right = right;
}
