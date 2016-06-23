/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(!root)
        return ;

    while(root){
        if(root->left){
            struct TreeNode *node = root->left;
            while(node->right)
                node = node->right;

            node->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        root = root->right;
    }
}
