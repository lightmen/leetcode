/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getKth(struct TreeNode *root, int k, int *val)
{
    if(root == NULL)
        return 0;

    int left = getKth(root->left,k, val);
    if(left + 1 > k)
        return left;
    else if(left + 1 == k){
        *val = root->val;
        return left + 1;
    }

    return left + 1 + getKth(root->right, k - left - 1, val);
}

int kthSmallest(struct TreeNode* root, int k) {
    int val;
    getKth(root,k,&val);

    return val;
}
