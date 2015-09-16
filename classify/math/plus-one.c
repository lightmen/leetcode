/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int *ret;
    int count;
    int i;

    count = digitsSize + 1;
    ret = (int *)malloc(sizeof(int) * count);

    for(i = digitsSize - 1; i >= 0; --i){
        ret[--count] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }

    if(carry)
        ret[--count] = 1;

    *returnSize = digitsSize + 1 - count;

    return ret + count;
}
