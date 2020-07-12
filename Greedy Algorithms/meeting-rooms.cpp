/*
    https://www.interviewbit.com/problems/meeting-rooms/
    TC: O(nlogn)
*/
int Solution::solve(vector<vector<int> > &timings) {
    int rooms_req = 0;
    
    struct Event {
        int t = 0;
        bool start = false;
        Event(int t, bool start): t(t), start(start) {};
    };
    
    vector<Event> events;
    for(auto &event: timings) {
        events.emplace_back(Event(event[0], true));
        events.emplace_back(Event(event[1], false));
    }
        
    /// sort the events 
    sort(events.begin(), events.end(), [](Event& a, Event& b )->bool{
        return a.t < b.t || (a.t == b.t && !a.start);
    });
    
    int curr_req = 0;
    for(auto &event: events) {
        curr_req = curr_req + (event.start ? 1 : -1);
        rooms_req = max(rooms_req, curr_req);
    }
    return rooms_req;
}
