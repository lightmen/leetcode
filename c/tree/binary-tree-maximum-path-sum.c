/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int get_max(struct TreeNode *root, int *node)
{
    if(root == NULL)
        return 0;

    int left = get_max(root->left,node);
    int right = get_max(root->right,node);
    int ret;
    int tmp;

    ret = root->val;
    ret += left > right ? left : right;

    tmp = root->val + left + right;
    *node = tmp > *node ? tmp : *node;

    return ret < 0 ? 0 : ret;
}

int maxPathSum(struct TreeNode* root) {
    int node = INT_MIN;

    get_max(root,&node);

    return node;
}
