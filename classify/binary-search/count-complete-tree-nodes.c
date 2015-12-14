/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root == NULL)
        return 0;

    int lh,rh;
    struct TreeNode *tmp;

    tmp = root->left;
    lh = 0;
    while(tmp){
        lh++;
        tmp = tmp->left;
    }

    tmp = root->right;
    rh = 0;
    while(tmp){
        rh++;
        tmp = tmp->right;
    }

    if(lh == rh)
        return (2<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
