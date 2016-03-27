/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *dp;
    int cnt;
    int i;
    int tmp;

    dp = (int *)malloc(sizeof(int) * (num + 1));
    for(i = 0; i <= num; ++i){
        cnt = 0;
        tmp = i;
        while(tmp){
            cnt += (tmp & 0x1);
            tmp >>= 1;
        }

        dp[i] = cnt;
    }

    *returnSize = num + 1;
    return dp;
}
