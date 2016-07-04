/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL)
        return;
    struct TreeLinkNode *parent = root;
    struct TreeLinkNode *next = root->left;

    while(parent && next){
        struct TreeLinkNode *pre = NULL;
        while(parent){
            if(pre == NULL){
                pre = parent->left;
            }else{
                pre->next = parent->left;
                pre = pre->next;
            }
            pre->next = parent->right;
            pre = pre->next;
            parent = parent->next;
        }

        parent = next;
        next = next->left;
    }
}
