class LRUCache {
private:
    static const int MAXN = 10001;
    static const int NOT_EXIST = -1;    // (k,v) v 
    std::list<int> m_List;
    std::pair<std::list<int>::iterator, int> m_hashMap[MAXN];
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {
        for (int i = 0; i < MAXN; ++i) {
            m_hashMap[i].second = NOT_EXIST;
        }
    }
    
    int get(int key) {
        if (m_hashMap[key].second == NOT_EXIST) {
            return -1;
        }
        if (m_hashMap[key].first != m_List.begin()) {
            m_List.erase(m_hashMap[key].first);
            m_List.push_front(key);
            m_hashMap[key].first = m_List.begin();   
        }
        return m_hashMap[key].second;
    }
    
    void put(int key, int value) {
        if (m_hashMap[key].second == NOT_EXIST) {
            if ((int)m_List.size() == capacity) {
                m_hashMap[m_List.back()].second = NOT_EXIST;
                m_List.pop_back();
            }
            m_List.emplace_front(key);
            m_hashMap[key].first = m_List.begin();
            m_hashMap[key].second = value;
        }
        else {
            m_hashMap[key].second = value;
            if (m_hashMap[key].first != m_List.begin()) {
                m_List.erase(m_hashMap[key].first);
                m_List.emplace_front(key);
                m_hashMap[key].first = m_List.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */