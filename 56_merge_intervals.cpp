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
    // need to be a static compare function, why??
    static bool compare(Interval x, Interval y){
        return x.start<y.start;
    }
    public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        // deal with empty input
        if (intervals.empty()){
            return vector<Interval>();
        }
        // sort the vector in the accending order of interval.start;
        sort(intervals.begin(),intervals.end(),compare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        // compare the start of coming interval with current end val
        for (int i=1;i<intervals.size();i++){
            if (intervals[i].start<=end){
                end = max(end,intervals[i].end);
            }
            else{
                ret.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        // need to push_back again in the end
        ret.push_back(Interval(start,end));
        return ret;
    }
};
