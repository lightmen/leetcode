/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node{
    int val;
    int index;
};

int cmp(const void *a, const void *b)
{
    return ((struct node *)a)->val - ((struct node *)b)->val;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *ret;
    struct node *arr;
    int i,j;
    int sum;
    ret = (int *)malloc(sizeof(int) * 2);
    arr = (struct node *)malloc(sizeof(struct node) * numsSize);
    for(i = 0; i < numsSize; ++i){
        arr[i].val = nums[i];
        arr[i].index = i + 1;
    }

    qsort(arr,numsSize,sizeof(struct node),cmp);

    i = 0;
    j = numsSize - 1;
    while(i < j){
        sum = arr[i].val + arr[j].val;
        if(sum == target){
            ret[0] = arr[i].index < arr[j].index ? arr[i].index : arr[j].index;
            ret[1] = arr[i].index > arr[j].index ? arr[i].index : arr[j].index;
            break;
        }
        if(sum > target){
            j--;
        }else{
            i++;
        }
    }

    free(arr);
    return ret;
}
