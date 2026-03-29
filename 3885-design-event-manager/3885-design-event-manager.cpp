class EventManager {
public:
    set<pair<int,int>>s;
    unordered_map<int,int>m;
    EventManager(vector<vector<int>>& events) {
        for(auto event:events){
        m[event[0]] = event[1];
        s.insert({-event[1],event[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(m.find(eventId)==m.end()) return;
        int id = m[eventId];
        s.erase({-id,eventId});
        m[eventId] = newPriority;
        s.insert({-newPriority,eventId});
    }
    
    int pollHighest() {
        if(s.empty()) return -1;
        auto it = s.begin();
        int id = it->second;
        s.erase(it);
        m.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */