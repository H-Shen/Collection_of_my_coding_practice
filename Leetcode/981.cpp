class TimeMap {
private:
    struct Node {
        string value;
        int timestamp;
        explicit Node(string value, int timestamp) :
        value(value), timestamp(timestamp) {}
        bool operator < (const Node &o) const {
            if (timestamp == o.timestamp) return value > o.value;
            return timestamp < o.timestamp;
        }
    };
    unordered_map<string, set<Node> > unmap;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        unmap[key].insert(Node(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (unmap.find(key) == unmap.end()) return "";
        if (timestamp < unmap[key].begin()->timestamp) {
            return "";
        }
        auto iter = unmap[key].upper_bound(Node(string(), timestamp));
        --iter;
        return iter->value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */