/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
struct TreeNode *t1,*t2,*prev;
void in_order(struct TreeNode *root)
{
    if(root->left)
        in_order(root->left);
    if(prev && prev->val > root->val){
        t2 = root;
        if(t1 == NULL)
            t1 = prev;
    }
    prev = root;
    if(root->right)
        in_order(root->right);
}
void recoverTree(struct TreeNode *root) {
    int tmp;
    t1 = NULL;
    t2 = NULL;
    prev = NULL;
    
    if(root)
        in_order(root);
    if(t1 && t2){
        tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }
}
