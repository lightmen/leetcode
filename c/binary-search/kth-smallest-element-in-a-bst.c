/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode *root){
    if(root == NULL)
        return 0;
    return helper(root->left) + helper(root->right) + 1;
}

int kthSmallest(struct TreeNode* root, int k) {
    int left;
    left = helper(root->left);
    if(left+1 > k)
        return kthSmallest(root->left,k);
    else if(left + 1 == k)
        return root->val;
    return kthSmallest(root->right,k - left - 1);
}
