/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *convert_summary(int start, int end){
    char *buf;
    buf = (char *)malloc(sizeof(char) * 20);
    if(end > start){
        sprintf(buf,"%d->%d",start,end);
    }else{
        sprintf(buf,"%d",start);
    }

    return buf;
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char **ret;
    int start,i;

    ret = (char **)malloc(sizeof(char *) * numsSize);
    start = nums[0];
    *returnSize = 0;
    for(i = 0; i < numsSize; ++i){
        if(i == numsSize - 1 || nums[i]+1 != nums[i+1]){
            ret[*returnSize] = convert_summary(start,nums[i]);
            if(i != numsSize - 1)
                start = nums[i+1];
            (*returnSize)++;
        }
    }

    return ret;
}
