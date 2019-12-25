/*
    https://www.interviewbit.com/problems/merge-intervals/
    TC: O(n)
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool isConflict(Interval& a, Interval& b) {
    return (a.start >= b.start && a.start <= b.end) ||
            (a.end >= b.start && a.end <= b.end);     
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // contains new merged intervals
    vector<Interval> new_intervals;
    
    // reorder the start and end of newInterval if needed
    if(newInterval.start > newInterval.end) {
        swap(newInterval.start, newInterval.end);    
    }
    
    if(intervals.empty()) {
        new_intervals.emplace_back(newInterval);
        return new_intervals;
    }
    
    // push all the intervals before the first conflicting interval
    // or the first intterval with start time greater than new intterval
    int i = 0;
    for(i = 0; i < intervals.size(); i++) {
        if((!isConflict(newInterval, intervals[i]) &&
            !isConflict(intervals[i], newInterval)) &&
            newInterval.start > intervals[i].start) {
            new_intervals.emplace_back(intervals[i]);
        }
        else
            break;
    }
    
    // tracks the last interval pushed
    Interval last_interval = newInterval;
    // we push the incoming interval knowing that it overlaps
    // with the current interval
    new_intervals.emplace_back(newInterval);
    
    // for every interval 'i', we check if it has merge conflict
    // with the last pushed interval
    for(; i< intervals.size(); i++) {
        // if there is conflict, merge the intervals and push
        if(isConflict(last_interval, intervals[i]) ||
            isConflict(intervals[i], last_interval)) {
            
            Interval merged_interval = Interval(
                                        min(last_interval.start, intervals[i].start),
                                        max(last_interval.end, intervals[i].end));
        
            new_intervals.back() = merged_interval;
            last_interval = new_intervals.back();
        }
        else {
            new_intervals.emplace_back(intervals[i]);
        }
    }
    
    return new_intervals;
}
