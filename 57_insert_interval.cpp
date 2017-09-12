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
    /*
    static bool compare(Interval a, Interval b){
        return (a.start<b.start);
    }
    */
    public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {intervals.push_back(newInterval); return intervals;}
        // sort(intervals.begin(),intervals.end(),compare);
        /*
        if (newInterval.end < intervals[0].start)
        {intervals.insert(intervals.begin(),newInterval);
         return intervals;
        }
        if (newInterval.start > intervals[intervals.size()-1].end)
        {intervals.push_back(newInterval);
         return intervals;
        }*/
        vector<Interval> ret;
        int i=0;
        int start = newInterval.start;
        int end = newInterval.end;
        while (i<intervals.size()){
            if (newInterval.start > intervals[i].end){
                ret.push_back(intervals[i]);
                if (i==intervals.size()-1){
                    ret.push_back(newInterval);
                    return ret;
                }
                i++;
            }
            else if (newInterval.end < intervals[i].start){
                if (i==0||newInterval.start > intervals[i-1].end){
                    ret.push_back(newInterval);
                }
                ret.push_back(intervals[i]);
                i++;
            }
            else {
            while (i<intervals.size()&&newInterval.end>=intervals[i].start){
                start = min(start,intervals[i].start);
                end = max(end,intervals[i].end);
                i++;
            }
                ret.push_back(Interval(start,end));
                if (i==intervals.size()) return ret;
                //i--;
            }
        }
        return ret;
    }
};
