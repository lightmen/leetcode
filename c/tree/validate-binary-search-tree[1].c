/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *lastnode;
bool isValid(struct TreeNode* root)
{
    if(root == NULL)
        return true;

    if(!isValid(root->left))
        return false;

    if(lastnode != NULL && lastnode->val >= root->val)
        return false;

    lastnode = root;
    return isValid(root->right);
}

bool isValidBST(struct TreeNode* root) {
    lastnode = NULL;
    return isValid(root);
}
