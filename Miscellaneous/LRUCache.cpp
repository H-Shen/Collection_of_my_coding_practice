#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <chrono>
#include <memory>
#include <cassert>

struct custom_hash {
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

// Reference: https://leetcode.com/problems/lru-cache
struct LRUCache {
    std::list<std::pair<int, int> > L;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator, custom_hash> hashMap;
    std::size_t size;

    explicit LRUCache(std::size_t size) : size(size) {}

    int get(const int &key);

    void put(const int &key, const int &value);
};

// O(1)
inline
int LRUCache::get(const int &key) {
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

// O(1)
inline
void LRUCache::put(const int &key, const int &value) {
    // We check if 'key' is in the hash map
    auto iter = hashMap.find(key);
    if (iter == hashMap.end()) {
        if (hashMap.size() == size) {
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

int main() {

    // test
    constexpr int CAPACITY = 2;
    auto cache = std::make_shared<LRUCache>(CAPACITY);
    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);
    cache->put(3, 3);
    assert(cache->get(2) == -1);
    cache->put(4, 4);
    assert(cache->get(1) == -1);
    assert(cache->get(3) == 3);
    assert(cache->get(4) == 4);

    return 0;
}
