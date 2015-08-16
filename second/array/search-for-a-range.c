/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int start, end, mid;
    int *ret;

    ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = -1;
    ret[1] = -1;

    start = 0;
    end = numsSize - 1;

    while(start <= end){
        mid = (start + end) / 2;
        if((mid - 1 < 0 || nums[mid-1] != target) &&
            target == nums[mid]){
            ret[0] = mid;
            ret[1] = mid;
            break;
        }else if(nums[mid] >= target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    start = mid+1;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if((mid + 1 == numsSize || target != nums[mid+1]) &&
            target == nums[mid]){
            ret[1] = mid;
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return ret;
}
