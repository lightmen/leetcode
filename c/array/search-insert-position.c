int searchInsert(int* nums, int numsSize, int target) {
    int start,end,mid;

    start = 0;
    end = numsSize - 1;
    while(start < end){
        mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return nums[start] < target ? start + 1 : start;
}
