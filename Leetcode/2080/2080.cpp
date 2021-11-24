class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> unmap;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = (int)arr.size();
        for (int i = 0; i < n; ++i) {
            unmap[arr[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (unmap.find(value) == unmap.end()) {
            return 0;
        }
        auto& vec = unmap[value];
        if (right < vec.front() || left > vec.back()) {
            return 0;
        }
        int l = lower_bound(vec.begin(),vec.end(),left) - vec.begin();
        int r = (--upper_bound(vec.begin(),vec.end(),right)) - vec.begin();
        return r-l+1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */