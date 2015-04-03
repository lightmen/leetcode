class Solution {
public:
    static bool cmp(const int a, const int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &num) {
        sort(num.begin(),num.end(),cmp);
        string ret;
        int len = num.size();
        for(int i = 0; i < len; ++i)
            ret += to_string(num[i]);
            
        return ret[0] == '0' ? "0" : ret;
    }
};
