/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *next_parent,*cursor;
    if(!root)
        return ;
    cursor = root;
    cursor->next = NULL;
    while(cursor){
        next_parent = cursor;
        while(next_parent){
            if(next_parent->left){
                next_parent->left->next = next_parent->right;
                next_parent->right->next = NULL;
            }
            if(next_parent->next && next_parent->right)
                next_parent->right->next = next_parent->next->left;
            next_parent = next_parent->next;
        }
        cursor = cursor->left;
    }
    
}
