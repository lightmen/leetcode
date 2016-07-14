/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *prev, *t2,*t1;

void inorder(struct TreeNode *root){
    if(root == NULL)
        return;

    inorder(root->left);

    if(prev && prev-> val > root->val){
        t2 = root;
        if(t1 == NULL)
            t1 = prev;
    }

    prev = root;
    inorder(root->right);
}

void recoverTree(struct TreeNode* root) {
    prev = NULL;
    t1 = NULL;
    t2 = NULL;
    inorder(root);

    if(t1 && t2){
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }
}
