/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int *get_3sum(int a, int b, int c)
{
    int *arr = (int *)malloc(sizeof(int) * 3);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    return arr;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret;
    int count = 0;
    int i,start,end;
    int sum;
    int alloc = numsSize;

    ret = (int **)malloc(sizeof(int *) * alloc);

    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 0; i < numsSize - 2; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            if(start > i + 1 && nums[start-1] == nums[start]){
                ++start;
                continue;
            }

            sum = nums[i] + nums[start] + nums[end];
            if(sum == 0){
                ret[count++] = get_3sum(nums[i],nums[start],nums[end]);
                if(alloc == count){
                    alloc <<= 1;
                    ret = realloc(ret,sizeof(int *) * alloc);
                }
            }
            if(sum > 0)
                --end;
            else
                ++start;
        }
    }

    *returnSize = count;
    return ret;
}
