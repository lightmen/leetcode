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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> vec;
        int i,size;
        size = intervals.size();
        for(i = 0; i < size; ++i){
            if(intervals[i].end < newInterval.start){
                vec.push_back(intervals[i]);
            }else if(newInterval.end < intervals[i].start){
                vec.push_back(newInterval);
                vec.insert(vec.end(),intervals.begin() + i,intervals.end());
                return vec;
            }else{
                newInterval.start = intervals[i].start < newInterval.start ? 
                    intervals[i].start : newInterval.start;
                newInterval.end = intervals[i].end > newInterval.end ?
                    intervals[i].end : newInterval.end;
            }
        }
        vec.push_back(newInterval);
        return vec;
    }
};
