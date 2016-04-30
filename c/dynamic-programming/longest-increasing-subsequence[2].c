int get_first_greater_index(int *arr, int start, int end, int target)
{
    int mid;

    while(start < end){
        mid = (start + end) / 2;
        if(arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

int lengthOfLIS(int* nums, int numsSize) {
    int *dp;
    int top;
    int i,index;

    top = -1;
    dp = (int *)malloc(sizeof(int) * numsSize);

    for(i = 1; i <= numsSize; ++i){
        if(top == -1 || nums[i-1] > dp[top]){
            dp[++top] = nums[i-1];
        }else{
            index = get_first_greater_index(dp,0,top,nums[i-1]);
            dp[index] = nums[i-1];
        }
    }

    free(dp);
    return top+1;
}
