/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    int m1 = rob(root->left) + rob(root->right);
    int m2 = root->val;
    if(root->left)
        m2 += rob(root->left->left) + rob(root->left->right);
    if(root->right)
        m2 += rob(root->right->left) + rob(root->right->right);

    return m2 > m1 ? m2 : m1;
}
