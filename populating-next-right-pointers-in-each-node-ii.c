/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *cur,*parent,*first,*first_child;
    cur = root;
    while(cur){
        parent = cur;
        first = NULL;
        while(parent){
            first_child = NULL;
            if(parent->left){
                first_child = parent->left;
            }else if(parent->right){
                first_child = parent->right;
            }
            if(first && first_child){
                first->next = first_child;
                first = first->next;
            }else if(!first){
                first = first_child;
                cur = first; // first TreeLinkNode is first node of the next loop
            }
            if(parent->left && parent->right){
                first->next = parent->right;
                first = first->next;
            }
            parent = parent->next;
        }
    }
}
