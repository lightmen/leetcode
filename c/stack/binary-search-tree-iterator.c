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
    int top;
    int count;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *iter;
    iter = malloc(sizeof(struct BSTIterator));
    iter->count = 20;
    iter->cur = root;
    iter->top = -1;
    iter->st = malloc(sizeof(struct TreeNode *) * iter->count);

    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->cur != NULL || iter->top > -1;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    while(iter->cur){
        if(iter->top + 1 == iter->count){
            iter->count <<= 1;
            iter->st = realloc(iter->st, iter->count * sizeof(struct TreeNode *));
        }
        iter->st[++iter->top] = iter->cur;
        iter->cur = iter->cur->left;
    }
    struct TreeNode *t = iter->st[iter->top];
    iter->top--;
    iter->cur = t->right;

    return t->val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    free(iter->st);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
