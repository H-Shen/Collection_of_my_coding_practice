class Memcache {
private:
    static const int NOT_EXIST = 2147483647;
    struct Node {
        int value;
        bool hasTtl;
        int endTime;
        Node() = default;
        Node(int value, bool hasTtl, int endTime = -1) : 
            value(value), 
            hasTtl(hasTtl),
            endTime(endTime) {}
    };
    unordered_map<int, Node> hashmap;
public:
    Memcache() {
        // do intialization if necessary
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: An integer
     */
    int get(int curtTime, int key) {
        // write your code here
        auto iter = hashmap.find(key);
        if (iter == hashmap.end()) {
            return NOT_EXIST;
        }
        // out of time
        if (iter->second.hasTtl && iter->second.endTime < curtTime) {
            hashmap.erase(iter);
            return NOT_EXIST;
        }
        return iter->second.value;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param value: An integer
     * @param ttl: An integer
     * @return: nothing
     */
    void set(int curtTime, int key, int value, int ttl) {
        // write your code here
        if (ttl == 0) {
            hashmap[key] = Node(value, false);
        }
        else {
            hashmap[key] = Node(value, true, curtTime + ttl - 1);
        }
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: nothing
     */
    void del(int curtTime, int key) {
        // write your code here
        hashmap.erase(key);
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int incr(int curtTime, int key, int delta) {
        // write your code here
        auto iter = hashmap.find(key);
        if (iter == hashmap.end()) {
            return NOT_EXIST;
        }
        // out of time
        if (iter->second.hasTtl && iter->second.endTime < curtTime) {
            hashmap.erase(iter);
            return NOT_EXIST;
        }
        iter->second.value += delta;
        return iter->second.value;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int decr(int curtTime, int key, int delta) {
        // write your code here
        return incr(curtTime, key, -delta);
    }
};