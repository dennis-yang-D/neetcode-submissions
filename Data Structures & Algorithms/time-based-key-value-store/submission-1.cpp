class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>> timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(timemap.size() == 0 || timemap[key].size() == 0) {return "";}
        auto loc = timemap[key].lower_bound(timestamp);
        if(loc == timemap[key].end()) {return "";}
        return (loc)->second;
    }
};
