/**
 * Merge overlapping intervals
 * https://www.interviewbit.com/problems/merge-overlapping-intervals/
 */
 
/*
    We sort the intervals by starting time. Starting with the 1st interval, we take its end
    time and check for each  interval whether its starting time is lesser than it or 
    not, if lesser then it will also lie in the same interval, also check whether the end 
    interval greater than current has been found or not, if yes then update. 
    Once a start time greater than current end time is found, we add an interval 
    consisting of tracked start and current time. Then repeat the process from the 
    current interval.
*/
vector<Interval> Solution::merge(vector<Interval> &arr) {
    vector<Interval> result;
    int start = 0;
    int end = 0;
    
    // sort the intervals by starting time
    sort(arr.begin(), arr.end(), [](const Interval a, const Interval b)->bool{
        return a.start < b.start;
    });
    
    start = arr[0].start;
    end = arr[0].end;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].start > end) {
            result.emplace_back(Interval(start, end));
            start = arr[i].start;
            end = arr[i].end;
        }
        else {
            end = max(end, arr[i].end);
        }
    }
    result.emplace_back(Interval(start, end));
    return result;
}
