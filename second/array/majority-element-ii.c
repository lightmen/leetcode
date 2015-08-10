/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *ret;
    int c1,c2,arr1,arr2;
    int i;
    int size = 0;

    arr1 = nums[0];
    arr2 = nums[0];
    c1 = 0;
    c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i]){
            c1++;
            continue;
        }

        if(arr2 == nums[i]){
            c2++;
            continue;
        }

        if(c1 == 0){
            arr1 = nums[i];
            c1++;
            continue;
        }

        if(c2 == 0){
            arr2 = nums[i];
            c2++;
            continue;
        }

        c1--;
        c2--;
    }

    c1 = 0;
    c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i])
            c1++;
        else if(arr2 == nums[i])
            c2++;
    }

    ret = (int *)malloc(sizeof(int) * 2);
    if(c1 > numsSize / 3)
        ret[size++] = arr1;
    if(c2 > numsSize / 3)
        ret[size++] = arr2;

    *returnSize = size;

    return ret;
}
