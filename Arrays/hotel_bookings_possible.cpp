/*
  Check if hotel bookings can be done with limited no. of rooms
  https://www.interviewbit.com/problems/hotel-bookings-possible/
*/

/*
  We just need to know at a particular time how many people are staying, if after that one more wants
  to book, then it is not possible. Also when somebody leaves a room becomes vacant.
  So we sort both arrival and departure times, and start traversal, if we get arrival time first then increment
  counter, else if a departure time is encountered decrement counter, when counter becomes greater than no. of romms K, not possible
*/
// solution taking more memory
bool bookingsPossible(vector<int>& arrive, vector<int>& depart, int rooms) {
    struct TimeEntry {
      int t;
      bool arrival;
      TimeEntry(int t, bool arrival) : t(t), arrival(arrival) {}
    };
    
    vector<TimeEntry> times;
    for(int i = 0; i < arrive.size(); i++) {
        if(arrive[i] != depart[i]) {
            times.emplace_back(TimeEntry(arrive[i], true));
            times.emplace_back(TimeEntry(depart[i], false));
        }
    }
    
    // sort the times 
    sort(times.begin(), times.end(), [](const TimeEntry& a, const TimeEntry& b)->bool{
        return a.t < b.t;
    });
    
    //for(const auto& a: times)cout<<a.t<<" "<<a.arrival<<endl;
    int curr_guests = 0;
    for(int i = 0; i < times.size(); i++) {
        if(curr_guests > rooms)
            return false;
        if(times[i].arrival)
            ++curr_guests;
        else
            --curr_guests;
    }
    return true;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    //return bookingsPossible(arrive, depart, k);

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    int curr_guests = 0;
    int i = 0, j = 0;
    while(i < arrive.size() && j < depart.size()) {
        if(arrive[i] < depart[j]) {
            ++curr_guests;
            ++i;
        }
        else {
            --curr_guests;
            ++j;
        }
        
        if(curr_guests > k)
            return false;
            
    }
    return true;
}
