/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max_2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y ;\
})
int depth(struct TreeNode *root)
{
    if(root == NULL)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if(left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    return max_2(left,right) + 1;
}
bool isBalanced(struct TreeNode* root) {
    return depth(root) != -1;
}
