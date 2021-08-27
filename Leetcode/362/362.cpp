class HitCounter {
public:
    unordered_map<int,int> unmap;
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++unmap[timestamp];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        constexpr int MAXN = 300;
        int counter = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (unmap.find(timestamp - i) != unmap.end()) {
                counter += unmap[timestamp - i];
            }
        }
        return counter;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */