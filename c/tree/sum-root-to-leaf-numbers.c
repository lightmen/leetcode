/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum(struct TreeNode *root, int cur_val)
{
    if(root == NULL)
        return 0;

    int val = cur_val * 10 + root->val;
    if(root->left == NULL && root->right == NULL)
        return val;

    return sum(root->left, val) + sum(root->right, val);
}

int sumNumbers(struct TreeNode* root) {
    return sum(root,0);
}
