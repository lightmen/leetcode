/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int my_abs(int a, int b)
{
    if(a > b)
        return a - b;
    return b - a;
}
bool getResult(struct TreeNode *root, int *height)
{
    if(root == NULL){
        *height = 0;
        return true;
    }

    int left = 0;
    int right = 0;
    bool bleft = getResult(root->left,&left);
    bool bright = getResult(root->right,&right);
    bool isbalanced = my_abs(left,right) <= 1;

    *height = (left > right ? left : right)+1;
    return bleft && bright && isbalanced;
}

bool isBalanced(struct TreeNode* root) {
    int height;
    return getResult(root,&height);
}
