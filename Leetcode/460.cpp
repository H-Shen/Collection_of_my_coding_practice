class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int freq;
        explicit Node(int key, int value, int freq) : key(key), value(value), freq(freq) {}
    };
    struct custom_hash_ {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };
    std::size_t size;
    int minimal_freq;
    std::unordered_map<int, std::list<Node>::iterator, custom_hash_> key_hashmap;
    std::unordered_map<int, std::list<Node>, custom_hash_> freq_hashmap;
    explicit LFUCache(int capacity) : size(capacity), minimal_freq(0) {

    }
    int get(int key) {
        auto iter = key_hashmap.find(key);
        if (iter == key_hashmap.end()) {
            return -1;
        }
        auto iter_in_list = iter->second;
        int value = iter_in_list->value;
        int freq = iter_in_list->freq;
        // Update 'freq_hashmap'
        freq_hashmap[freq].erase(iter_in_list);
        if (freq_hashmap[freq].empty()) {
            freq_hashmap.erase(freq);
            if (minimal_freq == freq) {
                ++minimal_freq;
            }
        }
        freq_hashmap[freq + 1].emplace_front(Node(key, value, freq + 1));
        // Update 'key_hashmap'
        iter->second = freq_hashmap[freq + 1].begin();
        // Return 'value'
        return value;
    }

    void put(int key, int value) {
        // Corner case:
        if (size == 0) {
            return;
        }
        auto iter = key_hashmap.find(key);
        if (iter == key_hashmap.end()) {
            // Delete the least frequently used item in both hashmaps
            if (key_hashmap.size() == size) {
                auto iter_to_lfu_item = freq_hashmap[minimal_freq].back();
                key_hashmap.erase(iter_to_lfu_item.key);
                freq_hashmap[minimal_freq].pop_back();
                if (freq_hashmap[minimal_freq].empty()) {
                    freq_hashmap.erase(minimal_freq);
                }
            }
            // Update 'minimal_freq'
            minimal_freq = 1;
            // Update 'freq_hashmap'
            freq_hashmap[minimal_freq].emplace_front(Node(key, value, minimal_freq));
            // Update 'key_hashmap'
            key_hashmap[key] = freq_hashmap[minimal_freq].begin();
        } else {
            auto iter_in_list = iter->second;
            int freq = iter_in_list->freq;
            // Update 'freq_hashmap'
            freq_hashmap[freq].erase(iter_in_list);
            if (freq_hashmap[freq].empty()) {
                freq_hashmap.erase(freq);
                if (minimal_freq == freq) {
                    ++minimal_freq;
                }
            }
            freq_hashmap[freq + 1].emplace_front(Node(key, value, freq + 1));
            // Update 'key_hashmap'
            iter->second = freq_hashmap[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */