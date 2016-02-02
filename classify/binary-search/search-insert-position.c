int searchInsert(int* nums, int numsSize, int target) {
    int ret = -1;
    int start,end,mid;

    start = 0;
    end = numsSize - 1;

    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target){
            ret = mid;
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    if(ret == -1)
        ret = nums[mid] > target ? mid : mid + 1;

    return ret;
}
