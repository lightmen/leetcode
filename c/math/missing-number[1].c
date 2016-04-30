int missingNumber(int* nums, int numsSize) {
    int i;
    int sum;

    sum = numsSize * (1 + numsSize) / 2;
    for(i = 0; i < numsSize; ++i)
        sum -= nums[i];

    return sum;
}
