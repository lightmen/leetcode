/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    int val;
    int index;
};

static int cmp(const void *a, const void *b)
{
    return ((struct node *)a)->val - ((struct node *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target) {
    int *ret;
    struct node *head;
    int i,j;
    int sum;
    
    ret = (int *)malloc(sizeof(int) * 2);
    head = (struct node *)malloc(sizeof(struct node) * numsSize);
    for(i = 0; i < numsSize; ++i){
        head[i].index = i + 1;
        head[i].val = nums[i];
    }
    
    qsort(head,numsSize,sizeof(struct node),cmp);
    
    i = 0;
    j = numsSize - 1;
    while(i < j){
        sum = head[i].val + head[j].val;
        if(sum == target){
            ret[0] = head[i].index < head[j].index ? head[i].index : head[j].index;
            ret[1] = head[i].index >= head[j].index ? head[i].index : head[j].index;
            break;
        }else if(sum > target){
            --j;
        }else{
            ++i;
        }
    }
    return ret;
}
