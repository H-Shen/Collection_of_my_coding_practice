class LRUCache {
private:
    struct inner_custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    std::list<std::pair<int, int> > L;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator, inner_custom_hash> hashMap;
    int capacity;
public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // We check if 'key' is in the hash map
        auto iter = hashMap.find(key);
        if (iter == hashMap.end()) {
            return -1;  // -1 indicates 'not found'
        }
        // Otherwise, push the (key, value) pair to the front of 'L' and update the hash map
        L.emplace_front(std::make_pair(key, iter->second->second));
        L.erase(iter->second);
        iter->second = L.begin();
        // Return 'value' from the pair
        return L.begin()->second;
    }

    void put(int key, int value) {
        // Corner case:
        if (capacity == 0) {
            return;
        }
        // We check if 'key' is in the hash map
        auto iter = hashMap.find(key);
        if (iter == hashMap.end()) {
            if (static_cast<int>(hashMap.size()) == capacity) {
                // The cache is full, we need to erase the least recently used item from 'L' and update the hash map
                hashMap.erase(L.back().first);
                L.pop_back();
            }
            L.emplace_front(std::make_pair(key, value));
            hashMap[key] = L.begin();
        } else {
            L.erase(iter->second);
            L.emplace_front(std::make_pair(key, value));
            iter->second = L.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */