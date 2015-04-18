/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pre_order(TreeNode *root,TreeNode *&prev)
    {
        if(!root)
            return true;
        if(!pre_order(root->left,prev))
            return false;
        if(prev && prev->val >= root->val)
            return false;
        prev = root;
        return pre_order(root->right,prev);
    }
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = NULL;
        return pre_order(root,prev);
    }
};
