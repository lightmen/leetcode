/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    int lh = 0;
    int rh = 0;
    struct TreeNode *node;

    if(root == NULL)
        return 0;

    node = root;
    while(node){
        ++lh;
        node = node->left;
    }

    node = root;
    while(node){
        ++rh;
        node = node->right;
    }

    if(lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
