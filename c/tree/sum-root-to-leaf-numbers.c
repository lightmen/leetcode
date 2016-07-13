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
        return cur_val;

    int val = cur_val * 10 + root->val;
    int left = 0;
    if(root->left)
        left = sum(root->left, val);
    int right = 0;
    if(root->right)
        right = sum(root->right, val);


    if(left == 0 && right == 0)
        return val;

    return left + right;
}

int sumNumbers(struct TreeNode* root) {
    return sum(root,0);
}
