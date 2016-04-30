/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize,
    struct Interval newInterval, int* returnSize) {
    struct Interval *ret;
    int count = 0;
    int i;

    ret = (struct Interval *)malloc(sizeof(struct Interval) * (intervalsSize + 1));

    for(i = 0; i < intervalsSize; ++i){
        if(intervals[i].end < newInterval.start){
            ret[count].start = intervals[i].start;
            ret[count].end = intervals[i].end;
            count++;
        }else if(intervals[i].start > newInterval.end){
            break;
        }else{
            newInterval.start = intervals[i].start < newInterval.start ?
                intervals[i].start : newInterval.start;
            newInterval.end = intervals[i].end > newInterval.end ?
                intervals[i].end : newInterval.end;
        }
    }

    ret[count].start = newInterval.start;
    ret[count].end = newInterval.end;
    count++;

    for(; i < intervalsSize; ++i){
        ret[count].start = intervals[i].start;
        ret[count].end = intervals[i].end;
        count++;
    }

    *returnSize = count;
    return ret;
}
