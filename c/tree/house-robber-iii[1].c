/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y; \
})

void dfs(struct TreeNode* root, int *rob, int *not_rob)
{
    if(root == NULL){
        *rob = 0;
        *not_rob = 0;
        return ;
    }

    int left, not_left;
    int right, not_right;
    dfs(root->left, &left, &not_left);
    dfs(root->right, &right, &not_right);

    *rob = root->val + not_left + not_right;
    *not_rob = max2(left, not_left) + max2(right, not_right);
}

int rob(struct TreeNode* root) {
    int rob, not_rob;

    dfs(root,&rob, &not_rob);

    return max2(rob, not_rob);
}
