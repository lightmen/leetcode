class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> v;
        recursive(n,n,s,v);
        return v;
    }
    void recursive(int left,int right,string s,vector<string> &v){
        if(left == 0 && right == 0){
            v.push_back(s);
            return ;
        }
        if(left > 0){
            recursive(left-1,right,s+'(',v);
        }
        if(right > 0 && right > left){
            recursive(left,right-1,s+')',v);
        }
    }
};
