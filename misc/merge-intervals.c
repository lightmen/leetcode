/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        int size,i;
        sort(intervals.begin(),intervals.end(),cmp);
        size = intervals.size();
        for(i = 0; i < size; ++i){
            if(i == size -1 || intervals[i].end < intervals[i+1].start){
                ret.push_back(intervals[i]);
            }else{
                intervals[i+1].start = intervals[i].start;
                intervals[i+1].end = intervals[i+1].end > intervals[i].end
                    ? intervals[i+1].end : intervals[i].end;
            }
        }
        return ret;
    }
};
