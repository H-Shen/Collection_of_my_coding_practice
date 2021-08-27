class FirstUnique {
private:
    list<int> l;
    unordered_map<int, list<int>::iterator> unmap;
    unordered_map<int,int> freq;
public:
    FirstUnique(vector<int>& nums) {
        for (const auto &i : nums) {
            this->add(i);
        }
    }
    
    int showFirstUnique() {
        if (l.empty()) {
            return -1;
        }
        return *l.begin();
    }
    
    void add(int value) {
        if (freq.find(value) == freq.end()) {
            freq[value] = 1;
            l.emplace_back(value);
            auto iter = l.end();
            --iter;
            unmap[value] = iter;
        }
        else if (freq[value] == 1) {
            ++freq[value];
            l.erase(unmap[value]);
            unmap.erase(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */