/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(left == 0)
        left = INT_MAX;
    if(right == 0)
        right = INT_MAX;

    return left < right ? left + 1 : right + 1;
}
