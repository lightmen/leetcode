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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        list<TreeNode *> lt;
        int left = 0;
        
        if(root){
            lt.push_back(root);
        }

        while(!lt.empty()){
            vector<int> tmp;
            list<TreeNode *> tmp_list;
            list<TreeNode *>::iterator lit;
            
            for(lit = lt.begin(); lit != lt.end(); ++lit){
                tmp.push_back((*lit)->val);
                if(left){
                    if((*lit)->right){
                        tmp_list.push_front((*lit)->right);
                    }
                    if((*lit)->left){
                        tmp_list.push_front((*lit)->left);
                    }
                }else{
                    if((*lit)->left){
                        tmp_list.push_front((*lit)->left);
                    }
                    if((*lit)->right){
                        tmp_list.push_front((*lit)->right);
                    }
                }
            }
            
            left ^= 1;
            lt = tmp_list;
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
