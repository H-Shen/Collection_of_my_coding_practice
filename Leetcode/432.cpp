class AllOne {
private:
    unordered_map<string,int> unmap1;
    unordered_map<int, unordered_set<string> > unmap2;
    multiset<int> minSet;
    multiset<int, greater<> > maxSet;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (unmap1.find(key) == unmap1.end()) {
            unmap1[key] = 1;
            unmap2[1].insert(key);
            minSet.insert(1);
            maxSet.insert(1);
        } else {
            int original = unmap1[key];
            ++unmap1[key];
            unmap2[original].erase(key);
            unmap2[original+1].insert(key);
            minSet.erase(minSet.find(original));
            minSet.insert(original+1);
            maxSet.erase(maxSet.find(original));
            maxSet.insert(original+1);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (unmap1[key] == 1) {
            unmap1.erase(key);
            unmap2[1].erase(key);
            minSet.erase(minSet.find(1));
            maxSet.erase(maxSet.find(1));
        } else {
            int original = unmap1[key];
            --unmap1[key];
            unmap2[original].erase(key);
            unmap2[original-1].insert(key);
            minSet.erase(minSet.find(original));
            minSet.insert(original-1);
            maxSet.erase(maxSet.find(original));
            maxSet.insert(original-1);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return (maxSet.empty()) ? string() : *unmap2[*maxSet.begin()].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return (minSet.empty()) ? string() : *unmap2[*minSet.begin()].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */