/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *arr;
    int i;
    int carry = 1;
    int offset = 1;

    arr = (int *)malloc(sizeof(int) * (digitsSize+1));

    for(i = digitsSize-1; i >= 0; --i){
        int  tmp = digits[i] + carry;
        carry = tmp / 10;
        arr[i+1] = tmp % 10;
    }

    if(carry){
        arr[0] = carry;
        offset--;
    }

    *returnSize = digitsSize + 1 - offset;
    return arr + offset;
}
