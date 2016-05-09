/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int is_ancestor(struct TreeNode *root, struct TreeNode *child)
{
    if(root == NULL)
        return 0;
    if(root == child)
        return 1;
    return is_ancestor(root->left,child) || is_ancestor(root->right,child);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(is_ancestor(root->left,p) && is_ancestor(root->left,q))
        return lowestCommonAncestor(root->left,p,q);
    if(is_ancestor(root->right,p) && is_ancestor(root->right,q))
        return lowestCommonAncestor(root->right,p,q);

    return root;
}
