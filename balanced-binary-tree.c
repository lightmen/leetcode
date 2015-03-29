/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 bool balanced_depth(struct TreeNode *root, int *depth)
 {
     int ld,rd;
     bool lb,rb;
     
     if(root == NULL){
         *depth = 0;
        return true;
     }
     
     lb = balanced_depth(root->left,&ld);
     rb = balanced_depth(root->right,&rd);
     if(lb && rb){
         *depth = (ld > rd) ? ld + 1 : rd + 1;
         if(ld - rd <= 1 && ld - rd >= -1)
            return true;
     }
     return false;
 }
bool isBalanced(struct TreeNode *root) 
{
    int depth;
    return balanced_depth(root,&depth);
}
