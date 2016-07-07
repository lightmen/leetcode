/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */

struct TreeLinkNode *get_next_child(struct TreeLinkNode *root)
{
    while(root){
        if(root->left)
            return root->left;
        if(root->right)
            return root->right;
        root = root->next;
    }

    return NULL;
}

struct TreeLinkNode *get_next(struct TreeLinkNode *root)
{
    while(root && root->left == NULL && root->right == NULL)
        root = root->next;

    return root;
}

void connect(struct TreeLinkNode *root) {
    if(root == NULL)
        return;

    struct TreeLinkNode *parent = get_next(root);
    struct TreeLinkNode *next = get_next_child(root);
    while(parent && next){
        while(parent){
            if(parent->left)
                parent->left->next = parent->right ? parent->right : get_next_child(parent->next);

            if(parent->right)
                parent->right->next = get_next_child(parent->next);

            parent = get_next(parent->next);
        }
        parent = get_next(next);
        next = get_next_child(next);
    }
}
