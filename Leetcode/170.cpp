// The time complexity is incorrect in the official answer since the worst case is that we add 25000 numbers at first, then we search 25000 numbers
// such that each number has no any possible of two sum.

class TwoSum {
public:
    unordered_map<int, int> unmap;
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++unmap[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        using ll = long long;
        ll temp;
        int diff;
        for (const auto &[k,v] : unmap) {
            temp = (ll)value - (ll)k;
            if (temp >= numeric_limits<int>::min() && temp <= numeric_limits<int>::max()) {
                diff = (int)temp;
                if (diff == k) {
                    if (v > 1) {
                        return true;
                    }
                } else {
                    if (unmap.find(diff) != unmap.end()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */