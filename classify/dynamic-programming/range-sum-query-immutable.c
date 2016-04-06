struct NumArray {
    int size;
    int *dp;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* na;
    int i;
    int *dp;

    na = malloc(sizeof(struct NumArray));
    na->size = numsSize + 1;
    na->dp = malloc(sizeof(int) * na->size);
    dp = na->dp;

    dp[0] = 0;
    for(i = 0; i < numsSize; ++i)
        dp[i+1] = dp[i] + nums[i];

    return na;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return numArray->dp[j+1] - numArray->dp[i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->dp);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
