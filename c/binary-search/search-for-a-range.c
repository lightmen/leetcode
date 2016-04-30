/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret;
    int start, end, mid;

    ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;

    start = 0;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target &&
            (mid == 0 || nums[mid] != nums[mid-1])){
            ret[0] = mid;
            break;
        }else if(nums[mid] >= target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    if(ret[0] == -1)
        return ret;

    start = mid;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target &&
            (mid == numsSize -1 || nums[mid] != nums[mid+1])){
            ret[1] = mid;
            break;
        }else if(nums[mid] <= target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ret;
}
