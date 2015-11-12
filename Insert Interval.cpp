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
    bool intersects(Interval a, Interval b) {
        if(a.start > b.start)
            swap(a, b);
        return b.start <= a.end;
    }
    
    Interval merge(Interval a, Interval b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        
        bool pushed = false;
        for(auto x: intervals) {
            if(intersects(x, newInterval)){
                newInterval = merge(x, newInterval);
            }
            else{
                if(x.start > newInterval.end && !pushed)
                    ret.push_back(newInterval), pushed = true;
                ret.push_back(x);
            }
        }
        
        if(!pushed)
            ret.push_back(newInterval);
        
        return ret;
    }
};
