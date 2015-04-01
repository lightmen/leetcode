/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
void flatten(struct TreeNode *root) {
    struct TreeNode *l;
    while(root){
        if(!root->left)
            root = root->right;
        else{
            if(root->right){
                l = root->left;
                while(l->right)
                    l = l->right;
                l->right = root->right;
            }
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}
