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

    int right;
    int left = getKth(root->left,k,val);
    if(left > k){
        return left;
    }

    if(k - left == 1){
        *val = root->val;
        return left + 1;
    }

    right = getKth(root->right,k - left - 1, val);
    return left + 1 + right;
}

int kthSmallest(struct TreeNode* root, int k) {
    int val;
    getKth(root,k,&val);

    return val;
}
