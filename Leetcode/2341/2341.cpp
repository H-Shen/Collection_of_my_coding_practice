class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> stats(2);
        unordered_map<int,int> unmap;
        for (auto&i : nums) ++unmap[i];
        int temp;
        for (auto&[k,v] : unmap) {
            if (v >= 2) {
                temp = v / 2;
                stats[0] += temp;
                v -= temp * 2;
            }
        }
        for (auto&[k,v] : unmap) {
            if (v > 0) {
                stats[1] += v;
            }
        }
        return stats;
    }
};