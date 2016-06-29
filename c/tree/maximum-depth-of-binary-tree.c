/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void depth(struct TreeNode *root, int cur_h, int *max_h)
{
    if(root == NULL)
        return ;

    cur_h++;
    if(cur_h > *max_h)
        *max_h = cur_h;

    depth(root->left, cur_h, max_h);
    depth(root->right, cur_h, max_h);
}
int maxDepth(struct TreeNode* root) {
    int max_h = 0;
    int cur_h = 0;

    depth(root, cur_h, &max_h);

    return max_h;
}
