class EventManager {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    unordered_map<int, int> latest;

    EventManager(vector<vector<int>>& events) {
        for(auto& i : events) {
            pq.push({i[1], i[0]});
            latest[i[0]] = i[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        latest[eventId] = newPriority;
        pq.push({newPriority, eventId}); 
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto [p, v] = pq.top();
            pq.pop();
            if(p != latest[v]) continue;
            latest.erase(v);
            return v;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */