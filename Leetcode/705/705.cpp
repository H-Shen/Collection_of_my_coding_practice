class MyHashSet {
private:
    static const int MAX_LENGTH = 1000005;
    bitset<MAX_LENGTH> mBitset;
public:
    /** Initialize your data structure here. */
    MyHashSet() {

        
    }
    
    void add(int key) {
        mBitset[key] = true;
    }
    
    void remove(int key) {
        mBitset[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return mBitset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */