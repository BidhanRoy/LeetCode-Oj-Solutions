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
    static bool compare(Interval a, Interval b) {
        if(a.start == b.start)
            return a.end > b.end;
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int size = min(1, (int)intervals.size());
        for(int i = 1; i < intervals.size(); i++) {
            auto &current = intervals[i];
            auto &previous = intervals[size-1];
            
            if(current.start <= previous.end)
                previous.end = max(previous.end, current.end);
            else
                intervals[size++] = current;
        }

        intervals.resize(size);
        return intervals;
    }
};
