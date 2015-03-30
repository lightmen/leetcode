/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
static void get_num(struct TreeNode *head, int num, int *sum)
{
    int tmp = 0;
    tmp = num * 10 + head->val;
    if(head->left == NULL && head->right == NULL){
        *sum += tmp;
    }else{
        if(head->left)
            get_num(head->left,tmp,sum);
        if(head->right)
            get_num(head->right,tmp,sum);
    }
}
int sumNumbers(struct TreeNode *root) {
    int sum = 0;
    if(root == NULL)
        return 0;
    get_num(root,0,&sum);
    return sum;
}
