class PhoneDirectory {
private:
    set<int> s;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            s.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (s.empty()) {
            return -1;
        }
        int ans = *s.begin();
        s.erase(ans);
        return ans;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return s.find(number) != s.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        s.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */