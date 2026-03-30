class EventManager {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if(a.first == b.first)
                return a.second > b.second; // smaller eventId first
            return a.first < b.first;       // higher priority first
        }
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    unordered_map<int, int> latest; 

    EventManager(vector<vector<int>>& events) {
        for(auto& i : events) {
            int eventId = i[0], priority = i[1];
            pq.push({priority, eventId});
            latest[eventId] = priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        latest[eventId] = newPriority;
        pq.push({newPriority, eventId}); 
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto [priority, eventId] = pq.top();
            pq.pop();

            if(latest.find(eventId) == latest.end()) continue;

            if(latest[eventId] != priority) continue;

            latest.erase(eventId); 
            return eventId;
        }
        return -1;
    }
};