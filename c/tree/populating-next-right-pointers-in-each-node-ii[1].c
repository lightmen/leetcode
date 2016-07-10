/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *parent;
    struct TreeLinkNode *arr[2];
    struct TreeLinkNode *first, *last;
    int idx;

    parent = root;
    while(parent){
        first = NULL;
        last = NULL;

        while(parent){
            idx = 0;
            if(parent->left)
                arr[idx++] = parent->left;
            if(parent->right)
                arr[idx++] = parent->right;

            for(int i = 0; i < idx; ++i){
                if(first == NULL){
                    first = arr[i];
                    last = arr[i];
                    continue;
                }
                last->next = arr[i];
                last = last->next;
            }

            parent = parent->next;
        }

        parent = first;
    }
}
