class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> unmap;
        for (const auto &i : nums) {
            ++unmap[i];
        }
        int counter = 0;
        while (!unmap.empty()) {
            auto &[key, val] = *unmap.begin();
            int diff = k - key;
            if (unmap.find(diff) == unmap.end()) {
                unmap.erase(key);
            }
            else {
                if (key == diff) {
                    counter += val / 2;
                    unmap.erase(key);
                }
                else {
                    counter += min(val, unmap[diff]);
                    unmap.erase(key);
                    unmap.erase(diff);
                }
            }
        }
        return counter;
    }
};