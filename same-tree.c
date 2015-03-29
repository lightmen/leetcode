/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if(!p && !q)
        return true;
    if((!p && q) || (p && !q))
        return false;
    if(p->val == q->val){
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    return false;
}
