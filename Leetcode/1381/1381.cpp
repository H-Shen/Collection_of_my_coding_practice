class CustomStack {
private:
    vector<int> vec;
    size_t maxSize;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        
    }
    
    void push(int x) {
        if (vec.size() < maxSize) {
            vec.emplace_back(x);
        }
    }
    
    int pop() {
        if (vec.empty()) {
            return -1;
        }
        int result = vec.back();
        vec.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        int n = (int)vec.size();
        for (int i = 0; i < n && i < k; ++i) {
            vec.at(i) += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */