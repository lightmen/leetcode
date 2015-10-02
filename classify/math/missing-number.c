int missingNumber(int* nums, int numsSize) {
    int *arr;
    int i;
    int ret;

    arr = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(arr,0,sizeof(int) * (numsSize+1));

    for(i = 0; i < numsSize; ++i)
        arr[nums[i]] = 1;

    for(i = 0; i <= numsSize; ++i)
        if(arr[i] == 0){
            ret = i;
            break;
        }

    free(arr);
    return ret;
}
