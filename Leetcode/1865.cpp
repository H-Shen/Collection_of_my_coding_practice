class FindSumPairs {
public:
    unordered_map<int,int> v1,v2;
    vector<int> n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (const auto &i : nums1) {
            ++v1[i];
        }
        n2 = nums2;
        for (const auto &i : nums2) {
            ++v2[i];
        }
    }
    
    void add(int index, int val) {
        int oldValue = n2[index];
        v2[oldValue]--;
        n2[index] += val;
        int newValue = n2[index];
        ++v2[newValue];
    }
    
    int count(int tot) {
        int ans = 0;
        int diff;
        for (const auto &[k,v] : v1) {
            diff = tot - k;
            if (v2.find(diff) != v2.end()) {
                ans += v*v2[diff];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */