class MyHashSet {
private:
    static const int MAXN = 1000005;
    bitset<MAXN> exist;
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    void add(int key) {
        exist[key] = true;
    }

    void remove(int key) {
        exist[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return exist[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */