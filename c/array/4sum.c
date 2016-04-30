/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int *get_4sum(int a, int b, int c, int d)
{
    int *ret = (int *)malloc(sizeof(int) * 4);
    ret[0] = a;
    ret[1] = b;
    ret[2] = c;
    ret[3] = d;

    return ret;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j,start,end;
    int sum;
    int **arr;
    int size = 0;
    int count = 500;

    arr = (int **)malloc(sizeof(int *) * count);

    qsort(nums,numsSize, sizeof(int),cmp);
    for(i = 0; i < numsSize - 3; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(j = i + 1; j < numsSize - 2; ++j){
            if(j > i + 1 && nums[j] == nums[j-1])
                continue;

            start = j + 1;
            end = numsSize - 1;
            while(start < end){
                if(start > j + 1 && nums[start] == nums[start-1]){
                    start++;
                    continue;
                }

                sum = nums[i] + nums[j] + nums[start] + nums[end];
                if(sum == target){
                    arr[size++] = get_4sum(nums[i],nums[j],nums[start],nums[end]);
                    if(size >= count){
                        count <<= 1;
                        arr = realloc(arr,sizeof(int *) * count);
                    }
                }

                if(sum > target)
                    --end;
                else
                    ++start;
            }
        }
    }

    *returnSize = size;
    return arr;
}
