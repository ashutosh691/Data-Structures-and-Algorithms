class MyCalendarTwo {
public:
    vector<pair<int, int>> booked, overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto& [l, r] : overlaps) 
            if(startTime < r && endTime > l) return false;
        
        for(auto& [l, r] : booked) 
            if(startTime < r && endTime > l)
                overlaps.push_back({max(startTime, l), min(endTime, r)});
            
        booked.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */