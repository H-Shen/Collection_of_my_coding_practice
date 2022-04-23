class MyHashMap {
private:
    static const int MAX_LENGTH = 1000005;
    static const int INF = 0x3f3f3f3f;
    int mArray[MAX_LENGTH];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(mArray, 0x3f, sizeof mArray);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        mArray[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return (mArray[key] == INF) ? -1 : mArray[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mArray[key] = INF;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */