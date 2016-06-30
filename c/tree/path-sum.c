/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL)
        return root->val == sum;

    bool bleft = hasPathSum(root->left,sum - root->val);
    if(bleft)
        return true;

    bool bright = hasPathSum(root->right, sum - root->val);

    return bright;
}
