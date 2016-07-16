/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSame(struct TreeNode *left, struct TreeNode *right)
{
    if(left && right){
        if(left->val != right->val)
            return false;

        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }

    return left == NULL && right == NULL;
}

bool isSymmetric(struct TreeNode* root) {
    if(root)
        return isSame(root->left,root->right);

    return true;
}
