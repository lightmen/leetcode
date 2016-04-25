/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode *st[1000];
    struct TreeNode *cur;
    int top;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *iter;
    iter = malloc(sizeof(struct BSTIterator));
    iter->cur = root;
    iter->top = -1;

    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->cur != NULL || iter->top > -1;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    while(iter->cur){
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

}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
