/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *dp;
    int i;

    dp = (int *)malloc(sizeof(int) * (num + 1));
    dp[0] = 0;
    for(i = 1; i <= num; ++i)
        dp[i] = dp[i >> 1] + (i & 0x1);

    *returnSize = num + 1;
    return dp;
}
