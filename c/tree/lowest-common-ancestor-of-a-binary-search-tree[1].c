/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define min_2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y;\
})

#define max_2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y; \
})

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(min_2(p->val, q->val) > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else if(max_2(p->val, q->val) < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}
