/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *ret = NULL;
    int i,c1,c2,arr1, arr2;

    arr1 = arr2 = 0;
    c1 = c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i])
            c1++;
        else if(arr2 == nums[i])
            c2++;
        else if(c1 == 0){
            arr1 = nums[i];
            c1++;
        }else if(c2 == 0){
            arr2 = nums[i];
            c2++;
        }else{
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i])
            c1++;
        else if(arr2 == nums[i])
            c2++;
    }

    *returnSize = 0;
    if(c1 > numsSize / 3 && c2 > numsSize/3){
        ret = (int *)malloc(sizeof(int) * 2);
        ret[0] = arr1;
        ret[1] = arr2;
        *returnSize = 2;
    }else if(c1 > numsSize / 3 || c2 > numsSize/3 ){
        if(c2 > numsSize/3)
            arr1 = arr2;
        ret = (int *)malloc(sizeof(int));
        ret[0] = arr1;
        *returnSize = 1;
    }

    return ret;
}
