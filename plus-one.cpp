class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int carry = 1;
        int i = n - 1;
        while(carry && i >= 0){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }
        if(carry){
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};
