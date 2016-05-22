/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode **st;
    struct TreeNode *cur;
    int count;
    int top;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *it = malloc(sizeof(struct BSTIterator));
    it->count = 20;
    it->st = malloc(sizeof(struct TreeNode *) * it->count);
    it->top = -1;
    it->cur = root;

    return it;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *it) {
    return it->top > -1 || it->cur != NULL;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *it) {
    while(it->cur){
        if(it->top == it->count){
            it->count <<= 1;
            it->st = realloc(it->st, sizeof(struct TreeNode *) * it->count);
        }
        it->st[++(it->top)] = it->cur;
        it->cur = it->cur->left;
    }
    struct TreeNode *tmp = it->st[(it->top)--];
    it->cur = tmp->right;
    return tmp->val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *it) {
    free(it->st);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
