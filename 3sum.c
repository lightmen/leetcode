/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret = NULL;
    int total = 64;
    int size = 0;
    int i,start,end;
    int sum;
    
    ret = (int **)malloc(sizeof(int *) * total);
    for(i = 0; i < total; ++i)
        ret[i] = (int *)malloc(sizeof(int) * 3);
    
    qsort(nums,numsSize,sizeof(int),cmp);
    
    for(i = 0; i < numsSize-2; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];
            if(sum == 0){
                if(size > 0 && ret[size-1][0] == nums[i] && 
                    ret[size-1][1] == nums[start] && ret[size-1][2] == nums[end]){
                    ++start;
                    --end;
                    continue;
                }
                ret[size][0] = nums[i];
                ret[size][1] = nums[start];
                ret[size][2] = nums[end];
                size++;
                
                if(size == total){
                    total <<= 1;
                    int t;
                    ret = (int **)realloc(ret,sizeof(int *) * total);
                    for(t = size; t < total; ++t)
                        ret[t] = (int *)malloc(sizeof(int) * 3);
                }
                ++start;
                --end;
            } else if(sum > 0){
                --end;
            }else{
                ++start;
            }
        } // end while(start < end)
    } // end for(i = 0; i < numsSize-2; ++i)
    
    *returnSize = size;
    return ret;
}
