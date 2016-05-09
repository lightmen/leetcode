/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *>* recusive(int start,int end)
    {
        vector<TreeNode *> *vl;
        vector<TreeNode *> *vr;
        vector<TreeNode *> *v;
        TreeNode *root;
        
        v = new vector<TreeNode *>();
        
        if(end < start){
            v->push_back(NULL);
            return v;
        }
        
        for(int i = start; i <= end; ++i){
            vl = recusive(start,i-1);
            vr = recusive(i+1,end);
            int l = vl->size();
            int r = vr->size();

            for(int j = 0; j < l; ++j)
                for(int k = 0; k < r; ++k){
                    root = new TreeNode(i);
                    root->left = (*vl)[j];
                    root->right = (*vr)[k];
                    v->push_back(root);
                }
            delete vl;
            delete vr;
        }
        return v;
    }

    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> *ret = recusive(1,n);
        return *ret;
    }
};
