/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int find;
int top;
int ptop;
int qtop;
struct TreeNode *parr[5000];
struct TreeNode *qarr[5000];
struct TreeNode *arr[5000];

void scan(struct TreeNode *root, struct TreeNode *node, int flag)
{
    if(root == NULL || find)
        return ;

    arr[++top] = root;
    if(root == node){
        find = 1;
        if(flag){
            ptop = top;
            for(int i = 0; i <= top; ++i)
                parr[i] = arr[i];
        }else{
            qtop = top;
            for(int i = 0; i <= top; ++i)
                qarr[i] = arr[i];
        }
        return;
    }

    scan(root->left, node, flag);
    if(find)
        return;

    scan(root->right, node, flag);
    if(find)
        return;

    --top;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    find = 0;
    top = -1;
    scan(root,p,0);

    find = 0;
    top = -1;
    scan(root,q,1);

    int m = ptop < qtop ? ptop : qtop;
    while(parr[m] != qarr[m])
        m--;

    return parr[m];
}
