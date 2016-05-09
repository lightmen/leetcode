/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
        const int MaxSize = 500;
        struct TreeNode *st[MaxSize];
        struct TreeNode *tmp,*p;
        int *ret;
        int top = -1;
        int flag;
       
        *returnSize = 0;
        if(!root)
            return NULL;
        
        ret = (int *)malloc(sizeof(int) * MaxSize);
        tmp = root;
        do{
            while(tmp){
                top++;
                st[top] = tmp;
                tmp = tmp->left;
            }
            p = NULL;
            flag = 1;
            while(top != -1 && flag){
                tmp = st[top];
                if(tmp->right == p){
                    ret[*returnSize] = tmp->val;
                    (*returnSize)++;
                    top--;
                    p = tmp;
                }else{
                    tmp = tmp->right;
                    flag = 0;
                }
            }
        }while(top != -1);
        
        return ret; 
}
